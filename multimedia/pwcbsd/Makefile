# Created by: Raaf <freebsd@luna.afraid.org>
# $FreeBSD$

PORTNAME=	pwcbsd
PORTVERSION=	1.4.1
PORTREVISION=	9
CATEGORIES=	multimedia sysutils kld
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	lme@FreeBSD.org
COMMENT=	The Linux pwc webcam driver ported to FreeBSD

CONFLICTS=	pwcview-[0-9]*

MAN4=		pwc.4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS_DEFINE=	PROGRAMS MMAP
OPTIONS_DEFAULT=	PROGRAMS
PROGRAMS_DESC=	Build the programs
MMAP_DESC=	Enable mmap support (MAY CRASH YOUR SYSTEM)

.include <bsd.port.options.mk>

EXTRA_PATCHES=	${FILESDIR}/extra-patch-Makefile.kld \
		${FILESDIR}/extra-patch-pwc-ctrl.c \
		${FILESDIR}/extra-patch-pwc-v4l.c \
		${FILESDIR}/extra-patch-pwc.c \
		${FILESDIR}/extra-patch-pwc.h

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
LIB_DEPENDS=	jpeg:${PORTSDIR}/graphics/jpeg
MAN1=		pwcview.1
USE_SDL=	sdl
PLIST_SUB+=	PROGRAMS=""
.else
PLIST_SUB+=	PROGRAMS="@comment "
.endif

post-patch:
.if ${PORT_OPTIONS:MPROGRAMS}
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if ${PORT_OPTIONS:MPROGRAMS}
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${PREFIX}/man/man1
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
