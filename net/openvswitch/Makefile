# Created by: Edward Tomasz Napierala <trasz@FreeBSD.org>
# $FreeBSD$

PORTNAME=	openvswitch
PORTVERSION=	2.3.3
CATEGORIES=	net
MASTER_SITES=	http://openvswitch.org/releases/

MAINTAINER=	kevlo@FreeBSD.org
COMMENT=	Production quality, multilayer virtual switch

LICENSE=	APACHE20

USES=		cpe gmake libtool perl5 pkgconfig python shebangfix
SHEBANG_FILES=	vtep/ovs-vtep
USE_OPENSSL=	yes
USE_LDCONFIG=   yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared --localstatedir=/var \
		--with-dbdir=/var/db/${PORTNAME} \
		--with-openssl=${OPENSSLBASE}
USE_RC_SUBR=	ovs-vswitchd ovsdb-server
LDFLAGS+=	-lpthread

post-install:
	${INSTALL_DATA} ${WRKSRC}/vswitchd/vswitch.ovsschema ${STAGEDIR}${PREFIX}/share/openvswitch/

.include <bsd.port.mk>
