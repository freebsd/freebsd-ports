# ex:ts=8
# Ports collection makefile for:	pnews
# Date created:			Feb 25, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	pnews
PORTVERSION=	2.6.6
PORTEPOCH=	1
CATEGORIES=	www news
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/v${PORTVERSION}
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PHP Web-based News Reader

USE_PHP=	yes
NO_BUILD=	yes

PNEWSDIR?=	www/pnews
PNEWSFULLDIR=	${PREFIX}/${PNEWSDIR}
PLIST_SUB+=	PNEWSDIR="${PNEWSDIR}"

do-install:
	@${MKDIR} ${PNEWSFULLDIR}
	@${CP} -R ${WRKSRC}/* ${PNEWSFULLDIR}
	@${CP} -R ${WRKSRC}/.htaccess ${WRKSRC}/* ${PNEWSFULLDIR}
	@${FIND} ${PNEWSFULLDIR} -path '*/.svn' | ${XARGS} ${RM} -fr

.include <bsd.port.mk>
