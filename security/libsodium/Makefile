# $FreeBSD$

PORTNAME=	libsodium
PORTVERSION=	0.4.5
CATEGORIES=	security
MASTER_SITES=	http://download.dnscrypt.org/libsodium/releases/

MAINTAINER=	csosstudy@gmail.com
COMMENT=	Library to build higher-level cryptographic tools

LICENSE=	ISCL

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=	pkgconfig

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS README.markdown THANKS

post-patch:
	@${REINPLACE_CMD} -e 's|$$(libdir)/pkgconfig|${PREFIX}/libdata/pkgconfig|' \
		${WRKSRC}/Makefile.in

post-build:
	cd ${WRKSRC} && ${MAKE} check

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
