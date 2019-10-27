# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvswitch
DISTVERSION=	2.12.0
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Production quality, multilayer virtual switch

LICENSE=	APACHE20

BROKEN_mips64=		fails to compile: ofp-actions.h:486: flexible array member in otherwise empty struct

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

USES=		compiler:c11 cpe gmake libtool perl5 pkgconfig python:2.7 \
		shebangfix ssl
SHEBANG_FILES=	ovn/utilities/ovndb-servers.ocf \
		utilities/bugtool/ovs-bugtool-ovs-ofctl-loop-over-bridges \
		utilities/ovs-docker \
		utilities/ovs-appctl-bashcomp.bash \
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

post-install:
	@${MKDIR} ${STAGEDIR}/var/run/openvswitch
	@${MKDIR} ${STAGEDIR}/var/log/openvswitch
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${STAGEDIR}${PREFIX}/share/openvswitch/

.include <bsd.port.mk>
