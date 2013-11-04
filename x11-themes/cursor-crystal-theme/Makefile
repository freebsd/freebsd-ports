# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

# Note:	1)	If port is interupted while compiling, "make clean" must be run before
#		attempting to recompile.

PORTNAME=	cursor-crystal-theme
DISTVERSION=	1.1.1
PORTREVISION=	5
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.notmart.org/files/ \
		http://pinguin.stttelkom.ac.id/gentoo/distfiles/
DISTNAME=	Crystalcursors

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	KDE Crystal style X cursor theme

BUILD_DEPENDS=	convert:${PORTSDIR}/graphics/ImageMagick \
		xcursorgen:${PORTSDIR}/x11/xcursorgen

MAKE_ENV+=	DESTDIR=${STAGEDIR}
USES=		gmake
USE_BZIP2=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|function ||' \
		${WRKSRC}/colorize.sh \
		${WRKSRC}/left-handed_templates/flopalltheme.sh \
		${WRKSRC}/left-handed_templates/floptheme.sh
	@${REINPLACE_CMD} -e 's|make|$${MAKE}|g' \
		${WRKSRC}/blue_src/Makefile \
		${WRKSRC}/gray_src/Makefile \
		${WRKSRC}/green_src/Makefile \
		${WRKSRC}/left-handed_templates/Makefile \
		${WRKSRC}/white_src/Makefile

pre-install:
	@${REINPLACE_CMD} \
		-e 's|$$(HOME)/.icons/|${STAGEDIR}${PREFIX}/lib/X11/icons|' \
		-e 's|$$(MAKE) .*install|$$(MAKE) PREFIX=${STAGEDIR}${PREFIX}/lib/X11/icons install|g' \
		-e 's|theme.default .*/default/index.theme|theme.default ${STAGEDIR}${PREFIX}/lib/X11/icons/default/index.theme|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
