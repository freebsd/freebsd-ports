# New ports collection makefile for:	gsfonts
# Version required:	5.10a
# Date created:		11 September 1997
# Whom:			giffunip
#
# $Id$
#

DISTNAME=	gsfonts-5.10
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.cs.wisc.edu/ghost/gnu/fonts/	\
		$(MASTER_SITE_GNU)
DISTFILES=	${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	$(LOCALBASE)/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst	\
		$(X11BASE)/bin/mkfontdir:${PORTSDIR}/x11/XFree86

EXTRACT_ONLY=
NO_BUILD=	yes

GS_FONTS_STD=	ghostscript-fonts-5.10a.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz
GSDIR=	${PREFIX}/share/ghostscript

do-install:
	@${MKDIR} ${GSDIR}/fonts
	tar -xzf ${DISTDIR}/${GS_FONTS_OTHER} -C ${GSDIR}/fonts
	tar -xzf ${DISTDIR}/${GS_FONTS_STD} -C ${GSDIR}/fonts
	(cd ${PREFIX}/share/ghostscript/fonts; $(LOCALBASE)/bin/type1inst -nogs -nolog -q)
	mkfontdir ${GSDIR}/fonts

.include <bsd.port.mk>
