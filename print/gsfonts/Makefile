# New ports collection makefile for:	gsfonts
# Date created:		11 September 1997
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	gsfonts
PORTVERSION=	5.10
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GNU} \
		ftp://ftp.cs.wisc.edu/ghost/gnu/gs510/
MASTER_SITE_SUBDIR=	ghostscript
DISTFILES=	${GS_FONTS_STD} ${GS_FONTS_OTHER}

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Fonts used by GNU Ghostscript

BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

.include <bsd.port.pre.mk>
.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	${X11BASE}/bin/mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.else
BUILD_DEPENDS+=	${X11BASE}/bin/mkfontdir:${PORTSDIR}/x11/XFree86
.endif

NO_BUILD=	yes

GS_FONTS_STD=	ghostscript-fonts-std-5.10.tar.gz
GS_FONTS_OTHER=	ghostscript-fonts-other-5.10.tar.gz
GSDIR=	${PREFIX}/share/ghostscript

do-install:
	@${MKDIR} ${GSDIR}/fonts
	${TAR} -xzf ${DISTDIR}/${GS_FONTS_OTHER} -C ${GSDIR}/fonts
	${TAR} -xzf ${DISTDIR}/${GS_FONTS_STD} -C ${GSDIR}/fonts
	(cd ${GSDIR}/fonts; ${LOCALBASE}/bin/type1inst -nogs -nolog -q)

.include <bsd.port.post.mk>
