# Created by: rafan@infor.org
# $FreeBSD$

PORTNAME=	freetype-tools
PORTVERSION=	1.3.1
PORTREVISION=	9
CATEGORIES=	print
MASTER_SITES=   SF/freetype/freetype/${PORTVERSION} \
		http://sunsite.cnlab-switch.ch/ftp/mirror/freetype/freetype1/ \
		http://www.funet.fi/pub/mirrors/ftp.freetype.org/freetype1/ \
		http://ftp.sunet.se/pub/text-processing/freetype/freetype1/ \
		${MASTER_SITE_RINGSERVER:S,%SUBDIR%,graphics/freetype/&,} \
		ftp://ftp.freetype.org/freetype/freetupe1/
DISTNAME=	freetype-${PORTVERSION}

MAINTAINER=	rafan@FreeBSD.org
COMMENT=	Tools for FreeType 1

LIB_DEPENDS=	libttf.so:${PORTSDIR}/print/freetype
RUN_DEPENDS=	t1asm:${PORTSDIR}/print/t1utils
BUILD_DEPENDS:=	${RUN_DEPENDS}

USE_TEX=	base texmf
USES=		gmake
USE_AUTOTOOLS=	libtool
CONFIGURE_ARGS=	--disable-nls --enable-static --enable-shared

TEXMFMAIN=	${PREFIX}/share/texmf

MAN1=		ttf2bdf.1 ttf2tfm.1 ttf2pk.1

PORTSCOUT=	limit:^1\.

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|LIBTOOL =.*|LIBTOOL = ${LIBTOOL}|'
	@${FIND} ${WRKSRC} -name '*.orig' -delete
	@${REINPLACE_CMD} -e 's|^PROGRAMS = t1asm|PROGRAMS =|' \
		${WRKSRC}/contrib/ttf2pfb/Makefile.in

post-build:
	@cd ${WRKSRC}/contrib/ttf2bdf && ./configure --prefix=${PREFIX} && ${MAKE_CMD}
	@cd ${WRKSRC}/contrib/ttf2pfb && ./configure --prefix=${PREFIX} && ${MAKE_CMD}
	@cd ${WRKSRC}/contrib/ttf2pk && ./configure --prefix=${PREFIX} --with-kpathsea-dir=${LOCALBASE} && ${MAKE_CMD}
	@cd ${WRKSRC}/contrib/ttfbanner && ./configure --prefix=${PREFIX} && ${MAKE_CMD}

do-install:
	@cd ${WRKSRC}/contrib/ttf2bdf && ${MAKE_CMD} install
	@cd ${WRKSRC}/contrib/ttf2pfb && ${MAKE_CMD} install
	@cd ${WRKSRC}/contrib/ttf2pk && ${MAKE_CMD} install
	@cd ${WRKSRC}/contrib/ttfbanner && ${MAKE_CMD} install
	@${MKDIR} ${TEXMFMAIN}/ttf2pk
	@for f in ${WRKSRC}/contrib/ttf2pk/data/*; do \
	  ${INSTALL_DATA} $$f ${TEXMFMAIN}/ttf2pk; \
	done
	@${LN} -fs ${TEXMFMAIN}/ttf2pk ${TEXMFMAIN}/ttf2tfm

.include <bsd.port.mk>
