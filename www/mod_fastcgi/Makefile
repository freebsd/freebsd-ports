# Created by: JunSeon Oh <hollywar@mail.holywar.net>
# $FreeBSD$

PORTNAME=	mod_fastcgi
PORTVERSION=	2.4.7
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/ \
		LOCAL/ohauer
DISTNAME=	mod_fastcgi-SNAP-0910052141
DIST_SUBDIR=	apache2

MAINTAINER=	apache@FreeBSD.org
COMMENT=	A fast-cgi module for Apache


USE_APACHE=	22
AP_FAST_BUILD=	yes
AP_GENPLIST=	yes
SRC_FILE=	*.c
PORTDOCS=	LICENSE.TERMS mod_fastcgi.html

do-install:
	@${APXS} -i -a -n ${SHORTMODNAME} ${WRKSRC}/${MODULENAME}.${AP_BUILDEXT}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
