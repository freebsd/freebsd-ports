# New ports collection makefile for:	mod_put Apache module
# Date created:		Jun 26 2001
# Whom:			Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $FreeBSD$
#

PORTNAME=	mod_put
PORTVERSION=	1.3
CATEGORIES=	www
MASTER_SITES=	http://hpwww.ec-lyon.fr/~vincent/apache/
DISTFILES=	mod_put.tar.gz

MAINTAINER=	apache@FreeBSD.org
COMMENT=	An Apache module that provides PUT and DELETE methods

USE_APACHE=	yes
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

CONFLICTS=	apache-contrib-1.*

do-build:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -c ${PORTNAME}.c

do-install:
	cd ${WRKSRC} && ${LOCALBASE}/sbin/apxs -A -i ${PORTNAME}.so

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${PREFIX}/share/doc/${PORTNAME}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.html \
		${PREFIX}/share/doc/${PORTNAME}
.endif

.include <bsd.port.mk>
