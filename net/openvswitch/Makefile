# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>

PORTNAME=	openvswitch
DISTVERSION=	2.17.0
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Production quality, multilayer virtual switch

LICENSE=	APACHE20

BROKEN_mips64=		fails to compile: ofp-actions.h:486: flexible array member in otherwise empty struct

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		compiler:c11 cpe gmake libtool perl5 pkgconfig python \
		shebangfix ssl
SHEBANG_FILES=	ipsec/ovs-monitor-ipsec.in \
		utilities/bugtool/ovs-bugtool-get-port-stats \
		utilities/bugtool/ovs-bugtool-ovs-ofctl-loop-over-bridges \
		utilities/bugtool/ovs-bugtool.in \
		utilities/ovs-appctl-bashcomp.bash \
		utilities/ovs-check-dead-ifs.in \
		utilities/ovs-docker \
		utilities/ovs-dpctl-top.in \
		utilities/ovs-l3ping.in \
		utilities/ovs-parse-backtrace.in \
		utilities/ovs-pcap.in \
		utilities/ovs-tcpdump.in  \
		utilities/ovs-tcpundump.in \
		utilities/ovs-test.in \
		utilities/ovs-vlan-test.in \
		vtep/ovs-vtep.in

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --disable-static --localstatedir=/var \
		--with-dbdir=/var/db/${PORTNAME} \
		--with-openssl=${OPENSSLBASE}
USE_RC_SUBR=	ovs-vswitchd ovsdb-server
LDFLAGS+=	-lpthread
INSTALL_TARGET=install-strip

SHLIB_VER=	${DISTVERSION:C/\.[0-9]*$//}
PLIST_SUB=	SHLIB_VER=${SHLIB_VER}

post-patch:
	@${REINPLACE_CMD} -e 's|uuid_from_string(|uuid_from_string_ovs(|g' \
		${WRKSRC}/*/*.c ${WRKSRC}/*/*.h

post-install:
	${MKDIR} ${STAGEDIR}/var/run/openvswitch
	${MKDIR} ${STAGEDIR}/var/log/openvswitch
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${STAGEDIR}${PREFIX}/share/openvswitch/

.include <bsd.port.mk>
