# New ports collection makefile for:	link-grammar
# Date created:				22 May 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	link-grammar
PORTVERSION=	4.1.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.abisource.com/downloads/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A grammar checking library

USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_REINPLACE=	yes
INSTALLS_SHLIB=	yes
USE_LIBTOOL_VER=15

DOCS=		LICENSE README

post-patch:
	@${REINPLACE_CMD} -e 's|[(]libdir[)]/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's|/words/|/en/words/|g' \
		${WRKSRC}/data/en/4.0.dict

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
