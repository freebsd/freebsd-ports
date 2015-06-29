# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	ghostscript
PORTVERSION=	7.07
PORTREVISION=	31
CATEGORIES=	print
MASTER_SITES=	SF/ghostscript/gnu-gs/${PORTVERSION}:gs_srcs \
		ftp://mirror.cs.wisc.edu/pub/mirrors/ghost/gnu/gs${PORTVERSION:S/.//}/:gs_srcs \
		PORTS_JP:ports_jp,ports_jp_gs
PKGNAMESUFFIX=	7
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:gs_srcs
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Ghostscript 7.x PostScript interpreter

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/ghostscript/fonts/a010013l.pfb:${PORTSDIR}/print/gsfonts

CONFLICTS_INSTALL= \
		gambc-[0-9]* \
		ghostscript[89]-[0-9]* \
		ghostscript[89]-nox11-[0-9]* \
		ghostscript9-agpl-[0-9]* \
		ghostscript9-agpl-nox11-[0-9]*

USES=		gmake jpeg shebangfix tar:bzip2
USE_LDCONFIG=	yes
SHEBANG_FILES=	lib/fixmswrd.pl	
WANT_GNOME=	yes
# normazile WRKSRC so things like cups-pstoraster may work
WRKSRC=		${WRKDIR}/${PORTNAME}
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	${MAKE_ENV}
CONFIGURE_ARGS=	--disable-compile-inits \
		--with-ijs
MAKE_ENV=	CFLAGS_STANDARD="${CFLAGS}" \
		XCFLAGS="${XCFLAGS}" XLDFLAGS="${XLDFLAGS}" \
		EXTRALIBS="${EXTRALIBS}"
CPPFLAGS+=	-fPIC -DUPD_SIGNAL=0 -I. -I${WRKSRC}/gimp-print		\
		-I${LOCALBASE}/include
LDFLAGS+=	${XLDFLAGS}
XLDFLAGS=	-lpthread -L${LOCALBASE}/lib -L${WRKSRC}/gimp-print
PLIST_SUB=	GS_VERSION="${PORTVERSION}"

MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	X11 DOCS A4SIZE
OPTIONS_DEFAULT=X11 DOCS A4SIZE
NO_OPTIONS_SORT=yes
X11_USE=	GNOME=gtk12
X11_MAKE_ENV=	GS_SHLIB_VER="${SHLIB_VER}"
A4SIZE_DESC=	Set A4 (not Letter) as the default paper size

post-extract-all:
	${LN} -sf ${WRKDIR}/${DISTNAME} ${WRKDIR}/${PORTNAME}

post-extract: post-extract-all

.include "Makefile.drivers"
.include <bsd.port.options.mk>

MASTERDIR?=	${.CURDIR}
.include "${MASTERDIR}/files/Makefile.drivers_post"

.for D in ${OPTIONS_DEFINE:MGS_*:S/^GS_//} \
	${OPTIONS_MULTI_X11:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_SVGALIB:MGS_*:S/^GS_//}
.if ${PORT_OPTIONS:MGS_${D}}
PLIST_SUB+=	GS_${D}=""
.else
PLIST_SUB+=	GS_${D}="@comment "
.endif
.endfor

.if ${PORT_OPTIONS:MA4SIZE}
XCFLAGS+=	-DA4
.endif

# contributed uniprint profiles
CONTRIB_UPP=	lqx70ch.upp lqx70cl.upp lqx70cm.upp \
		stc740ih.upp stc740p.upp stc740pl.upp

.if ${PORT_OPTIONS:MX11}
SHLIB_VER=	1
PLIST_SUB+=	SHLIB="" X11="" SHLIB_VER="${SHLIB_VER}"
ALL_TARGET=	so
INSTALL_TARGET=	soinstall
.if ${PORT_OPTIONS:MGS_pcl3}
ALL_TARGET+=	pcl3opts
.endif
.else
ALL_TARGET=	all
PLIST_SUB+=	SHLIB="@comment " X11="@comment "
.endif

post-patch:
	${REINPLACE_CMD} -e 's|^DEVICE_DEVS|#DEVICE_DEVS|g' \
	    ${WRKSRC}/src/unix-gcc.mak
	${REINPLACE_CMD} -e 's|%%DATADIR%%|${DATADIR}|g' \
	    ${WRKSRC}/lib/gs_res.ps

pre-build-drivers.mak:
	@${ECHO_CMD} '# automatically generated' > ${WRKSRC}/src/drivers.mak
.for N in ${DEVS_LIST}
	@${ECHO_CMD} 'DEVICE_${N}=' >> ${WRKSRC}/src/drivers.mak
.endfor
.for D in ${OPTIONS_DEFINE:MGS_*:S/^GS_//} \
	${OPTIONS_MULTI_X11:MGS_*:S/^GS_//} \
	${OPTIONS_GROUP_SVGALIB:MGS_*:S/^GS_//}
.for N in ${DEVS_LIST}
.if ${PORT_OPTIONS:MGS_${D}}
.if !defined(OPTIONS_UNSET) || !${OPTIONS_UNSET:MGS_${D}}
.for X in ${DEVICE_${N}:M${D}.dev}
	@${ECHO_CMD} 'DEVICE_${N}+= $$(DD)${D}.dev'  >> ${WRKSRC}/src/drivers.mak
.endfor
.endif
.endif
.endfor
.endfor

pre-build-contrib_extra.mak:
	${CAT} /dev/null ${EXTRADEVMKFILE} > ${WRKSRC}/src/contrib_extra.mak

pre-build-all:
	${MKDIR} ${WRKSRC}/obj ${WRKSRC}/bin

pre-build: pre-build-all pre-build-drivers.mak pre-build-contrib_extra.mak

pre-su-install:
	${MKDIR} ${STAGEDIR}${DATADIR}

post-install-docs:
	${MKDIR} ${STAGEDIR}${DOCSDIR}

post-install:
.if ${PORT_OPTIONS:MX11}
	${LN} -sf gsc ${STAGEDIR}${PREFIX}/bin/gs
.endif
	cd ${FILESDIR} \
	    && ${INSTALL_DATA} ${CONTRIB_UPP} \
		${STAGEDIR}${DATADIR}/${PORTVERSION}/lib

post-install: post-install-docs

.include <bsd.port.mk>
