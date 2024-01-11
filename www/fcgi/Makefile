PORTNAME=	fcgi
PORTVERSION=	2.4.0
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	LOCAL/adamw
PKGNAMESUFFIX=	-devkit

MAINTAINER=	john@essenz.com
COMMENT=	FastCGI Development Kit
WWW=		http://www.fastcgi.com/

LICENSE=	Open_Market_FastCGI_license
LICENSE_NAME=	Open Market FastCGI license
LICENSE_FILE=	${WRKSRC}/LICENSE.TERMS
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		cpe libtool
CPE_VENDOR=	fastcgi

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi.so.0.0.0
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libfcgi++.so.0.0.0

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/*.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/*.3 ${STAGEDIR}${PREFIX}/share/man/man3
	(cd ${WRKSRC}/doc && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} "! -name *\.[13]")

.include <bsd.port.mk>
