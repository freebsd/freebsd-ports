# Created by: Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	encode
PORTVERSION=	5.0
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}${PKGNAMESUFFIX}/${PORTNAME}${PKGNAMESUFFIX}/${PORTNAME}${PKGNAMESUFFIX}_${PORTVERSION}
PKGNAMESUFFIX=	-explorer
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}_${PORTVERSION}

MAINTAINER=	fw@moov.de
COMMENT=	A PHP script to browse, create folders, upload files etc

USE_PHP=	yes
WANT_PHP_WEB=	yes
USES=		zip
NO_BUILD=	yes

OPTIONS_DEFINE=	EXPERIMENTAL DOCS
EXPERIMENTAL_DESC=	Experimental features

WRKSRC=		${WRKDIR}/${DISTNAME}
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXPERIMENTAL}
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-index-php-experimental
.endif

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL} ${WRKSRC}/index.php ${STAGEDIR}${WWWDIR}

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${CP} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
