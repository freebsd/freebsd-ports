# Created by: Francisco Gomez <francisco@gomezmarin.com>
# $FreeBSD$

PORTNAME=	uebimiau
PORTVERSION=	2.7.11
CATEGORIES=	mail www
MASTER_SITES=	http://www.uebimiau.org/downloads/
DISTNAME=	${PORTNAME}-${PORTVERSION}-any

MAINTAINER=	sylvio@FreeBSD.org
COMMENT=	UebiMiau is a simple yet efficient WebMail written in PHP

WRKSRC=		${WRKDIR}/webmail

USES=		zip
USE_PHP=	pcre
WANT_PHP_MOD=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

NO_STAGE=	yes
do-install:
	${MKDIR} ${PREFIX}/www/data/${PORTNAME}
	${CP} -vR ${WRKSRC}/* ${PREFIX}/www/data/${PORTNAME}
	${CHOWN} -R www:www ${PREFIX}/www/data/${PORTNAME}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
