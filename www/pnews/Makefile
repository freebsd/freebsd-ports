# ex:ts=8
# Ports collection makefile for:	pnews
# Date created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pnews
PORTVERSION=	2.6.4
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	www news
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	gslin@gslin.org
COMMENT=	PHP Web-based News Reader

USE_PHP=	yes
NO_BUILD=	yes

PNEWSDIR?=	${PREFIX}/www/data/pnews

do-install:
	@${MKDIR} ${PNEWSDIR}
	@${CP} -R ${WRKSRC}/* ${PNEWSDIR}
	@${CP} -R ${WRKSRC}/.htaccess ${WRKSRC}/* ${PNEWSDIR}

.include <bsd.port.mk>
