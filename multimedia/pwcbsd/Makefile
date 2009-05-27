# New ports collection makefile for:	pwcbsd
# Date created:				17 Feb 2006
# Whom:					Raaf <freebsd@luna.afraid.org>
#
# $FreeBSD$
#

PORTNAME=	pwcbsd
PORTVERSION=	1.4.1
PORTREVISION=	2
CATEGORIES=	multimedia sysutils kld
MASTER_SITES=	http://raaf.atspace.org/ \
		http://www.bsd-geek.de/FreeBSD/distfiles/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	miwi

MAINTAINER=	lme@FreeBSD.org
COMMENT=	The Linux pwc webcam driver ported to FreeBSD

MAN4=		pwc.4

WRKSRC=		${WRKDIR}/${PORTNAME}
NO_PACKAGE=	should be recompiled for a particular FreeBSD kernel

OPTIONS=	PROGRAMS	"Build the programs"			on \
		MMAP		"Enable mmap support (MAY CRASH YOUR SYSTEM)"	off

.include <bsd.port.pre.mk>

.if !exists(/usr/src/sys/Makefile)
IGNORE=		requires kernel source files
.endif

.if defined(WITH_MMAP)
ALL_TARGET=	mmap
.else
ALL_TARGET=	all
.endif
.if !defined(WITHOUT_PROGRAMS)
ALL_TARGET+=	pwcview
PROGRAMS=	pwcview
LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg
MAN1=		pwcview.1
USE_SDL=	sdl
PLIST_SUB+=	PROGRAMS=""
.else
PLIST_SUB+=	PROGRAMS="@comment "
.endif

post-patch:
.if !defined(WITHOUT_PROGRAMS)
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG}|g' ${WRKSRC}/Makefile
.endif

post-install:
	${INSTALL_MAN} ${MAN4:S|^|${WRKSRC}/|} ${PREFIX}/man/man4
.if !defined(WITHOUT_PROGRAMS)
	${INSTALL_PROGRAM} ${PROGRAMS:S|^|${WRKSRC}/|} ${PREFIX}/bin
	${INSTALL_MAN} ${MAN1:S|^|${WRKSRC}/|} ${PREFIX}/man/man1
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
