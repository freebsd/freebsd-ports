# New ports collection makefile for:	encode-explorer
# Date created:			Thu Apr 22 11:24:23 CEST 2010
# Whom:				Frank Wall <fw@moov.de>
#
# $FreeBSD$
#

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

USE_ZIP=	yes
NO_BUILD=	yes

OPTIONS=	EXPERIMENTAL "Enable experimental features" off

WRKSRC=		${WRKDIR}/${DISTNAME}
WWWDIR=		${PREFIX}/www/${PORTNAME}${PKGNAMESUFFIX}
DOCSDIR=	${PREFIX}/share/doc/${PORTNAME}${PKGNAMESUFFIX}

.include <bsd.port.pre.mk>

.if defined(WITH_EXPERIMENTAL)
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-index-php-experimental
.endif

do-install:
	${MKDIR} ${WWWDIR}
	${INSTALL} ${WRKSRC}/index.php ${WWWDIR}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/README.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
