# New ports collection makefile for:    mod_fastcgi ( in apache )
# Date created:         14 Jul 2000
# Whom:                 JunSeon Oh <hollywar@mail.holywar.net>
#
# $FreeBSD$
#

PORTNAME=	mod_fastcgi
PORTVERSION=	2.4.6
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A fast-cgi module for Apache

MAKE_JOBS_SAFE=  yes

CONFLICTS=	apache-contrib-1.*
USE_APACHE=	1.3+
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	*.c
PORTDOCS=	LICENSE.TERMS mod_fastcgi.html

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
