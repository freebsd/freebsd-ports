# New ports collection makefile for:	skytemplate
# Date created:		28 Jul 2005
# Whom:			Mun-Kyo Seo <munggo@gmail.com>
#
# $FreeBSD$

PORTNAME=	skytemplate
PORTVERSION=	1.4.0
CATEGORIES=	www
MASTER_SITES=	http://daddy.withsky.net/SkyTemplate/download/ \
		http://mirror.pmy.lv/SkyTemplate/download/
DISTNAME=	SkyTemplate.v${PORTVERSION:S/.//g}

MAINTAINER=	munggo@gmail.com
COMMENT=	Yet another PHP compiling template engine

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_PHP=	yes
WANT_PHP_WEB=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${DATADIR}
.for f in class.SkyTemplate.php class.SkyTemplate_withDaddy.php
	${INSTALL_DATA} ${WRKSRC}/$f ${DATADIR}
	${MKDIR} ${DATADIR}/SkyTpl
	${INSTALL_DATA} ${WRKSRC}/SkyTpl/* ${DATADIR}/SkyTpl
.endfor

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
