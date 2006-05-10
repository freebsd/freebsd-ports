# New ports collection makefile for:	NuppelViodeo
# Date created:		Mon 10 Feb 2003 22:21:51 CET
# Whom:			Steve O'Hara-Smith <steve@sohara.org>
#
# $FreeBSD$
#

PORTNAME=	NuppelVideo
PORTVERSION=	0.52.a
PORTREVISION=	2
CATEGORIES=	multimedia audio
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	arved
DISTNAME=	${PORTNAME}-${PORTVERSION:C/.(.)$/\1/}

MAINTAINER=	steve@sohara.org
COMMENT=	A very low CPU usage VCR/DVR application

RUN_DEPENDS=	wish8.4:${PORTSDIR}/x11-toolkits/tk84

USE_XLIB=	yes
USE_GMAKE=	yes

PORTDOCS=	README

# find dependencies
CFLAGS+=	-I${LOCALBASE}/include -I${X11BASE}/include \
		-L${LOCALBASE}/lib -L${X11BASE}/lib

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386" && ${ARCH} != "amd64"
BROKEN=		"Does not compile on !i386 and !amd64"
.endif

###
## Auto detected features
###
.if ${ARCH} == "i386"
. if (defined(MACHINE_CPU) && ${MACHINE_CPU:Mmmx:L} == "mmx")
WITH_MMX=yes
. endif
.endif

###
## Port options
###
.ifdef(WITH_OPTIMIZED_CFLAGS)
CFLAGS+=	-O3 -ffast-math -fomit-frame-pointer -finline-functions \
		-funroll-loops -fexpensive-optimizations
.endif
#
.ifdef(WITH_MMX)
CFLAGS+=	-DMMX
.endif

pre-everything::
.ifndef(WITH_OPTIMIZED_CFLAGS)
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can enable additional compilation optimizations'
	@${ECHO_MSG} 'by defining WITH_OPTIMIZED_CFLAGS'
.endif
.if (${ARCH} == "i386" && !defined(WITH_MMX))
	@${ECHO_MSG}
	@${ECHO_MSG} 'You can enable MMX compilation optimizations'
	@${ECHO_MSG} 'by defining WITH_MMX'
.endif

post-patch:
# C{C,FLAGS} safeness
	@${REINPLACE_CMD} -E -e \
		's|^CFLAGS.*$$|#|' \
		-e 's|^CC.*$$|#|' \
		-e 's|^(COPTSRT).*$$|\1=\$$(CFLAGS)|' \
		${WRKSRC}/Makefile

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
