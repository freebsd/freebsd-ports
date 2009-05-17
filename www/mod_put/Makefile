# New ports collection makefile for:	mod_put Apache module
# Date created:		Jun 26 2001
# Whom:			Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	mod_put
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://perso.ec-lyon.fr/lyonel.vincent/apache/
DISTNAME=	${PORTNAME}

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that provides PUT and DELETE methods

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache-contrib-1.*

USE_APACHE=	1.3

WRKSRC=	${WRKDIR}/${PORTNAME}-${PORTVERSION}

AP_FAST_BUILD=	yes
AP_GENPLIST=	yes

PORTDOCS=	${PORTNAME}.html

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}/
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
