# New ports collection makefile for: analog
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $FreeBSD$
#

PORTNAME=	analog
PORTVERSION=	5.1
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.analog.cx/ \
		http://www.monash.edu.au/mirror/analog/ \
		http://analog.gsp.com/ \
		http://analog.barringtons.com/ \
		http://www.pomfret.net/mirror/analog/ \
		http://analog.org/loganalysis/ \
		http://www.skreamsoft.com/analogmirror/ \
		http://sunsite.org.uk/packages/analog/ \

MAINTAINER=	mharo@FreeBSD.org

LIB_DEPENDS=	gd.2:${PORTSDIR}/graphics/gd \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

LIMGDIR?=	www/data/images
IMGDIR=		${PREFIX}/${LIMGDIR}
PLIST_SUB=	IMGDIR=${LIMGDIR}

MAN1=		analog.1
ALL_TARGET=	analog

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/share/analog/lang
	${MKDIR} ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/images/* ${IMGDIR}
	${INSTALL_DATA} ${WRKSRC}/lang/* ${PREFIX}/share/analog/lang
	${INSTALL_PROGRAM} ${WRKSRC}/analog ${PREFIX}/bin
.if !exists(${PREFIX}/etc/analog.cfg)
	${INSTALL_DATA} ${WRKSRC}/analog.cfg ${PREFIX}/etc
.endif
	${INSTALL_DATA} ${WRKSRC}/analog.cfg ${PREFIX}/etc/analog.cfg-dist
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/analog
	${INSTALL_DATA} ${WRKSRC}/docs/* ${PREFIX}/share/doc/analog
.endif
	${INSTALL_MAN} ${WRKSRC}/analog.man ${PREFIX}/man/man1/analog.1

.include <bsd.port.post.mk>
