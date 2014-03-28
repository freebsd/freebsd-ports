# Created by: Michael Fausten <ports@michael-fausten.de>
# $FreeBSD$

PORTNAME=	smarty3
PORTVERSION=	3.1.17
CATEGORIES=	www
MASTER_SITES=	http://www.smarty.net/files/
DISTNAME=	Smarty-${PORTVERSION}

MAINTAINER=	ports@michael-fausten.de
COMMENT=	PHP compiling template engine

WRKSRC=		${WRKDIR}/Smarty-${PORTVERSION}

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
