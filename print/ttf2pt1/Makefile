# Created by: ijliao
# $FreeBSD$

PORTNAME=	ttf2pt1
PORTVERSION=	3.4.4
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	True Type Font to Postscript Type 1 Converter

LIB_DEPENDS=	libfreetype.so:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	t1asm:${PORTSDIR}/print/t1utils

USES=		pkgconfig shebangfix perl5 uidfix
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} ${CPPFLAGS}" LIBS="${LIBS}" \
		INSTDIR="${STAGEDIR}${PREFIX}" LIBXDIR="${STAGEDIR}${PREFIX}/bin" \
		OWNER=${BINOWN} GROUP=${BINGRP}
SHEBANG_FILES=	app/TeX/sfd2map \
		app/TeX/cjk-latex-config \
		other/showdf \
		other/showg \
		other/*.pl \
		scripts/forceiso \
		scripts/frommap \
		scripts/inst_dir \
		scripts/html2man \
		scripts/t1fdir \
		scripts/trans


CPPFLAGS+=	`pkg-config --cflags freetype2` \
		-I${LOCALBASE}/include -DUSE_FREETYPE
LIBS+=		`pkg-config --libs freetype2` \
		-L${LOCALBASE}/lib -lm

post-install:
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/bin/ttf2pt1_convert \
		${STAGEDIR}${PREFIX}/man/man1/ttf2pt1_x2gs.1 \
		${STAGEDIR}${PREFIX}/man/man1/ttf2pt1.1 \
		${STAGEDIR}${PREFIX}/man/man1/ttf2pt1_convert.1 \
		${STAGEDIR}${DATADIR}/scripts/convert

.include <bsd.port.mk>
