PORTNAME=	uuid
PORTVERSION=	1.6.2
PORTREVISION=	11
CATEGORIES=	misc devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	ISO-C API and CLI for generating Universally Unique Identifiers
WWW=		http://www.ossp.org/pkg/lib/uuid/

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
LICENSE_FILE=	${WRKSRC}/../README
.else
LICENSE_FILE=	${WRKSRC}/README
.endif
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
USES+=		libtool pathfix
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-cxx \
		--includedir=${PREFIX}/include/ossp

.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
PKGNAMEPREFIX=	p5-OSSP-
.else
TEST_TARGET=	check
.endif

pre-patch:
### Fixes lib conflicts with misc/libuuid ###
	@${REINPLACE_CMD} 's/libuuid.la/libossp-uuid.la/ ; s/libuuid++.la/libossp-uuid++.la/' \
		${WRKDIR}/${DISTNAME}/Makefile.in

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${LICENSE_FILE} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
