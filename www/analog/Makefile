# New ports collection makefile for: analog
# Date created:		October 21st 1996
# Whom:			jfitz
#
# $FreeBSD$
#

PORTNAME=	analog
PORTVERSION=	6.0
PORTREVISION=	0
PORTEPOCH=	1
CATEGORIES=	www
MASTER_SITES=	http://www.analog.cx/ \
		http://analog.planetmirror.com/ \
		http://analog.gsp.com/ \
		http://isr.ath.cx/analog/ \
		http://analog.mirrors.ecodigit.com.br/ \
		http://analog.org/loganalysis/ \
		http://analog.techsell.ru/ \
		http://sunsite.sut.ac.jp/pub/archives/WWW/analog/ \
		ftp://ftp.polytechnic.edu.na/pub/analog/ \
		http://analog.netsoc.ucd.ie/ \
		http://analog.tzone.it/

MAINTAINER=	mharo@FreeBSD.org
COMMENT=	An extremely fast program for analysing WWW logfiles

LIB_DEPENDS=	gd.4:${PORTSDIR}/graphics/gd \
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
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/*.cfg ${EXAMPLESDIR}
	${MKDIR} ${EXAMPLESDIR}/css
	${INSTALL_DATA} ${WRKSRC}/examples/css/Readme.txt ${EXAMPLESDIR}/css
	${INSTALL_DATA} ${WRKSRC}/examples/css/default.css ${EXAMPLESDIR}/css
	${MKDIR} ${EXAMPLESDIR}/css/jreeves
	${INSTALL_DATA} ${WRKSRC}/examples/css/jreeves/* ${EXAMPLESDIR}/css/jreeves
.endif
	${INSTALL_MAN} ${WRKSRC}/analog.man ${PREFIX}/man/man1/analog.1

.include <bsd.port.post.mk>
