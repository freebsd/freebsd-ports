# Created by: ijliao
# $FreeBSD$

PORTNAME=	ttf2pt1
PORTVERSION=	3.4.4
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	True Type Font to Postscript Type 1 Converter

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2
RUN_DEPENDS=	t1asm:${PORTSDIR}/print/t1utils

USES=		pkgconfig shebangfix perl5
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS} ${CPPFLAGS}" LIBS="${LDFLAGS}" \
		INSTDIR="${PREFIX}" LIBXDIR="${PREFIX}/bin"
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

MAN1=		ttf2pt1.1 ttf2pt1_convert.1 ttf2pt1_x2gs.1

CPPFLAGS+=	`pkg-config --cflags freetype2` \
		-I${LOCALBASE}/include -DUSE_FREETYPE
LDFLAGS+=	`pkg-config --libs freetype2` \
		-L${LOCALBASE}/lib -lm

.include <bsd.port.mk>
