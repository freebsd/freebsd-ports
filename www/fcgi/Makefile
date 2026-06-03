PORTNAME=	fcgi
DISTVERSION=	2.4.7
CATEGORIES=	www
PKGNAMESUFFIX=	-devkit

MAINTAINER=	john@essenz.com
COMMENT=	FastCGI Development Kit
WWW=		https://fastcgi-archives.github.io/

LICENSE=	Open_Market_FastCGI_license
LICENSE_NAME=	Open Market FastCGI license
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		autoreconf cpe libtool pathfix
CPE_VENDOR=	fastcgi
USE_GITHUB=	yes
GH_ACCOUNT=	FastCGI-Archives
GH_PROJECT=	fcgi2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi.so \
		${STAGEDIR}${PREFIX}/lib/libfcgi++.so
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${PREFIX}/share/man/man3

post-install-DOCS-on:
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name *\.[13]")

.include <bsd.port.mk>
