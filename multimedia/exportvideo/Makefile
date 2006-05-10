# New ports collection makefile for:	exportvideo
# Date created:		24 October 2004
# Whom:			Frank W. Josellis <frank@dynamical-systems.org>
#
# $FreeBSD$
#

PORTNAME=	exportvideo
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://tigerente.htu.tuwien.ac.at/~aoe/mystuff/mpeg2_movie-avipatch/
DISTNAME=	${PORTNAME}.7e-pre9

MAINTAINER=	frank@dynamical-systems.org
COMMENT=	Writes yuv4mpeg streams for mpeg2enc from nuppelvideo files

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png

USE_GNOME=	gtk12
USE_XLIB=	yes
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--no-avi --prefix=${PREFIX}

WRKSRC=		${WRKDIR}/${DISTNAME}

PORTDOCS=	README README.links

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
IGNORE=		Supported for i386 architecture only
.endif

# Compiling with MMX extensions fails on FreeBSD 5.x
.if ${OSVERSION} >= 500000
WITHOUT_MMX=	yes
.endif

.if defined(WITHOUT_MMX)
CONFIGURE_ARGS+=	--no-mmx
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -fomit-frame-pointer -funroll-loops -ffast-math
.endif

pre-everything::
.if !defined(WITHOUT_MMX)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can disable MMX optimizations by defining WITHOUT_MMX."
.endif
.if !defined(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable extra optimizations by defining WITH_OPTIMIZED_CFLAGS."
.endif

post-patch:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/libmpeg3/configure ${WRKSRC}/quicktime/configure

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/video/exportvideo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${FILESDIR}/nuv4dvd ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${FILESDIR}/README.FreeBSD ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
