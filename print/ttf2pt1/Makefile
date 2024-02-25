PORTNAME=	ttf2pt1
PORTVERSION=	3.4.4
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	True Type Font to Postscript Type 1 Converter
WWW=		https://ttf2pt1.sourceforge.net/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

LIB_DEPENDS=	libfreetype.so:print/freetype2
RUN_DEPENDS=	t1asm:print/t1utils

USES=		localbase perl5 pkgconfig shebangfix tar:tgz uidfix

SHEBANG_FILES=	app/TeX/cjk-latex-config app/TeX/sfd2map other/*.pl \
		other/showdf other/showg scripts/forceiso scripts/frommap \
		scripts/html2man scripts/inst_dir scripts/t1fdir scripts/trans

MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS} ${CPPFLAGS}" \
		GROUP=${BINGRP} \
		INSTDIR="${STAGEDIR}${PREFIX}" \
		LIBS="${LIBS}" \
		LIBXDIR="${STAGEDIR}${PREFIX}/bin" \
		MANDIR="${STAGEDIR}${PREFIX}/share/man" \
		OWNER=${BINOWN}

CPPFLAGS+=	`pkg-config --cflags freetype2` -DUSE_FREETYPE
LIBS+=		`pkg-config --libs freetype2` -lm

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/ttf2pt1
	@${SED} -i '' 's,${STAGEDIR},,' ${STAGEDIR}${PREFIX}/bin/ttf2pt1_convert \
		${STAGEDIR}${PREFIX}/share/man/man1/ttf2pt1_x2gs.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/ttf2pt1.1 \
		${STAGEDIR}${PREFIX}/share/man/man1/ttf2pt1_convert.1 \
		${STAGEDIR}${DATADIR}/scripts/convert

.include <bsd.port.mk>
