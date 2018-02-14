# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvswitch
PORTVERSION=	2.8.1
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	koue@chaosophia.net
COMMENT=	Production quality, multilayer virtual switch

LICENSE=	APACHE20

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR}

BROKEN_powerpc64=	fails to compile: bfd.c: internal compiler error: in extract_insn, at recog.c

USES=		cpe gmake libtool perl5 pkgconfig python:2.7 shebangfix ssl
SHEBANG_FILES=	utilities/ovs-docker \
		utilities/ovs-appctl-bashcomp.bash \
		ovn/utilities/ovndb-servers.ocf \
		vtep/ovs-vtep.in
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --localstatedir=/var \
		--with-dbdir=/var/db/${PORTNAME} \
		--with-openssl=${OPENSSLBASE}
USE_RC_SUBR=	ovs-vswitchd ovsdb-server
LDFLAGS+=	-lpthread
INSTALL_TARGET=install-strip

post-install:
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${STAGEDIR}${PREFIX}/share/openvswitch/

.include <bsd.port.mk>
