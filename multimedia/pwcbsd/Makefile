PORTNAME=	pwcbsd
PORTVERSION=	1.4.1
PORTREVISION=	14
CATEGORIES=	multimedia sysutils
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/ \
		LOCAL/miwi

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Linux pwc webcam driver ported to FreeBSD
WWW=		http://raaf.atspace.org/

LICENSE=	GPLv2

CONFLICTS=	pwcview

SSP_UNSAFE=	kernel module does not support ssp

USES=		kmod

WRKSRC=		${WRKDIR}/${PORTNAME}

OPTIONS_DEFINE=	PROGRAMS MMAP
OPTIONS_DEFAULT=	PROGRAMS
PROGRAMS_DESC=	Build the programs
MMAP_DESC=	Enable mmap support (MAY CRASH YOUR SYSTEM)

CFLAGS+=	-Wno-error

.include <bsd.port.options.mk>

.if !exists(${SRC_BASE}/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if ${PORT_OPTIONS:MMMAP}
ALL_TARGET=	mmap
.else
ALL_TARGET=	all
.endif
.if ${PORT_OPTIONS:MPROGRAMS}
ALL_TARGET+=	pwcview
PROGRAMS=	pwcview
USES+=		jpeg sdl
USE_SDL=	sdl
PLIST_SUB+=	PROGRAMS=""
.else
PLIST_SUB+=	PROGRAMS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MPROGRAMS}
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
.endif

do-install:
	${MKDIR} ${STAGEDIR}${KMODDIR}
	${INSTALL_KLD} ${WRKSRC}/pwc.ko ${STAGEDIR}${KMODDIR}
	${INSTALL_MAN} ${WRKSRC}/pwc.4 ${STAGEDIR}${PREFIX}/share/man/man4
.if ${PORT_OPTIONS:MPROGRAMS}
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${PROGRAMS:S|^|${WRKSRC}/|}.1 ${STAGEDIR}${PREFIX}/share/man/man1
.endif

.include <bsd.port.mk>
