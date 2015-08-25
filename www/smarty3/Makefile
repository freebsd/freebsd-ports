# Created by: Michael Fausten <ports@michael-fausten.de>
# $FreeBSD$

PORTNAME=	smarty3
PORTVERSION=	3.1.27
CATEGORIES=	www
MASTER_SITES=	https://github.com/smarty-php/smarty/archive/
DISTNAME=	v${PORTVERSION}

MAINTAINER=	ports@michael-fausten.de
COMMENT=	PHP compiling template engine

LICENSE=	LGPL3

WRKSRC=		${WRKDIR}/smarty-${PORTVERSION}

NO_BUILD=	yes
USE_PHP=	pcre
WANT_PHP_WEB=	yes

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/libs && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
