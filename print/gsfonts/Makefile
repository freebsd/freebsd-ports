# New ports collection makefile for:	gsfonts
# Date created:		11 September 1997
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	gsfonts
PORTVERSION=	6.0
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cs.wisc.edu/ghost/gnu/
MASTER_SITE_SUBDIR=	ghostscript
DISTFILES=	${GS_FONTS_STD} ${GS_FONTS_OTHER}
DIST_SUBDIR=	ghostscript

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts used by GNU Ghostscript (or X)

BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

.include <bsd.port.pre.mk>
.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	${X11BASE}/bin/mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.else
BUILD_DEPENDS+=	${X11BASE}/bin/mkfontdir:${PORTSDIR}/x11/XFree86
.endif

NO_BUILD=	yes

GS_FONTS_STD=	gnu-gs-fonts-std-${PORTVERSION}.tar.gz
GS_FONTS_OTHER=	gnu-gs-fonts-other-${PORTVERSION}.tar.gz
GSDIR=	${PREFIX}/share/ghostscript

do-install:
	@${MKDIR} ${GSDIR}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_OTHER} -C ${GSDIR}
	${TAR} -xzf ${DISTDIR}/${DIST_SUBDIR}/${GS_FONTS_STD} -C ${GSDIR}
	(cd ${GSDIR}/fonts; ${LOCALBASE}/bin/type1inst -nox -nolog -q)

.include <bsd.port.post.mk>
