# New ports collection makefile for:	flpsed
# Date created:				6 January 2005
# Whom:					Fernan Aguero <fernan@iib.unsam.edu.ar>
#
# $FreeBSD$
#

PORTNAME=	flpsed
PORTVERSION=	0.3.4
CATEGORIES=	print
MASTER_SITES=	http://www.ecademix.com/JohannesHofmann/

MAINTAINER=	fernan@iib.unsam.edu.ar
COMMENT=	WYSIWYG pseudo Postscript editor

LIB_DEPENDS=	fltk.1:${PORTSDIR}/x11-toolkits/fltk

GNU_CONFIGURE=		yes
USE_X_PREFIX=		yes
USE_GHOSTSCRIPT=	yes
USE_GMAKE=		yes
PLIST_FILES=		bin/flpsed

.if !defined(NOPORTDOCS)
PLIST_FILES+=		%%DOCSDIR%%/README
PLIST_DIRS=		%%DOCSDIR%%
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/flpsed ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
