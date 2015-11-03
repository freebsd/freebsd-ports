# Created by: ports@FreeBSD.org
# $FreeBSD$

PORTNAME=	cups-pstoraster
PORTVERSION=	8.15.4
PORTREVISION=	8
CATEGORIES=	print
MASTER_SITES=	EASYSW/ghostscript/${PORTVERSION}
DISTNAME=	espgs-${ESPGS_VER}-source
DIST_SUBDIR=	ghostscript

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Postscript interpreter for CUPS printing to non-PS printers

LICENSE=	GPLv2

LIB_DEPENDS=	libcupsimage.so:${PORTSDIR}/print/cups-image

ESPGS_VER=	${PORTVERSION}
GS_VERSION=	8.15

WRKSRC=		${WRKDIR}/espgs-${PORTVERSION}

DATADIR=	${PREFIX}/share/espgs

# We just need the ghostscript fonts, nothing more
USES=		ghostscript:run gmake iconv tar:bzip2
GNU_CONFIGURE=		yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--without-x --with-gs=espgs
MAKE_ARGS=	CFLAGS_STANDARD="${CFLAGS} -DUPD_SIGNAL=0" \
		DEVICE_DEVS="\$$(DD)cups.dev \$$(DD)pxlcolor.dev \$$(DD)pxlmono.dev"
PLIST_SUB=	GS_VERSION="${GS_VERSION}"

OPTIONS_DEFINE=	CJK

CJK_DESC=		Japanese PostScript documents processing
CJK_RUN_DEPENDS=	${LOCALBASE}/share/fonts/std.ja_JP/Ryumin-Light:${PORTSDIR}/japanese/font-std \
			${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts
CJK_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-lib_cidfmap

MAKE_JOBS_UNSAFE=	yes

pre-configure:
	${RM} -f ${WRKSRC}/ijs/config.guess ${WRKSRC}/ijs/missing ${WRKSRC}/ijs/config.sub ${WRKSRC}/ijs/install-sh ${WRKSRC}/ijs/ltmain.sh
	${RM} -f ${WRKSRC}/trunk/ijs/config.guess ${WRKSRC}/trunk/ijs/missing ${WRKSRC}/trunk/ijs/config.sub ${WRKSRC}/trunk/ijs/install-sh ${WRKSRC}/trunk/ijs/ltmain.sh

post-patch:
	${LN} -sf ${WRKSRC}/pstoraster/gdevcups.c ${WRKSRC}/src
	${CAT} ${FILESDIR}/cups.contrib.mak >> ${WRKSRC}/src/contrib.mak
	${FIND} ${WRKSRC} -name "*.mak" -type f | ${XARGS} ${REINPLACE_CMD} -e \
		's|$$(install_prefix)|$$(DESTDIR)$$(install_prefix)|g'
.for file in pstopxl pstoraster
	${REINPLACE_CMD} -e 's:@prefix@:${PREFIX}:g ; \
		 s:@exec_prefix@:${PREFIX}:g ; \
		 s:@bindir@:${PREFIX}/bin:g ; \
		 s:@GS@:espgs:g ; \
		 s|^GS_LIB="|GS_LIB="${PREFIX}/share/ghostscript/fonts:|' \
		 ${WRKSRC}/pstoraster/${file}.in
.endfor
	${REINPLACE_CMD} -e 's|^CFLAGS=|CFLAGS=@CPPFLAGS@ |g ; \
		 s|^LDFLAGS=|LDFLAGS=@LDFLAGS@ |g ; \
		 s|^DEVICE_DEVS|#DEVICE_DEVS|g ; \
		 s|^gssharedir = @libdir@/ghostscript|gssharedir = @libdir@/espgs| ; \
		 s|^gsdir = @datadir@/ghostscript|gsdir = @datadir@/espgs|' \
		 ${WRKSRC}/Makefile.in

pre-build:
	${MKDIR} ${WRKSRC}/bin
	${MKDIR} ${WRKSRC}/obj

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/espgs

.include <bsd.port.mk>
