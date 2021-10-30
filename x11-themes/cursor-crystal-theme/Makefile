# Created by: David Naylor <naylor.b.david@gmail.com>

PORTNAME=	cursor-crystal-theme
DISTVERSION=	1.1.1
PORTREVISION=	6
CATEGORIES=	x11-themes
MASTER_SITES=	http://www.notmart.org/files/ \
		http://pinguin.stttelkom.ac.id/gentoo/distfiles/
DISTNAME=	Crystalcursors

MAINTAINER=	ports@FreeBSD.org
COMMENT=	KDE Crystal style X cursor theme

LICENSE=	LGPL21

BUILD_DEPENDS=	xcursorgen:x11/xcursorgen

USES=		gmake magick:6,build tar:bzip2

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

pre-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_CMD} clean ${MAKE_ARGS})

pre-install:
	@${REINPLACE_CMD} \
		-e 's|$$(HOME)/.icons/|${STAGEDIR}${PREFIX}/share/icons|' \
		-e 's|$$(MAKE) .*install|$$(MAKE) PREFIX=${STAGEDIR}${PREFIX}/share/icons install|g' \
		-e 's|theme.default .*/default/index.theme|theme.default ${STAGEDIR}${PREFIX}/share/icons/default/index.theme|' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
