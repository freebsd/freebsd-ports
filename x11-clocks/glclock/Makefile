# New ports collection makefile for:	glclock
# Date created:		20 September 1999
# Whom:			Randall Hopper <aa8vb@ipass.net>
#
# $FreeBSD$
#

PORTNAME=	glclock
PORTVERSION=	5.0
PORTREVISION=	1
CATEGORIES=	x11-clocks
MASTER_SITES=	http://www.daionet.gr.jp/~masa/archives/ \
		http://hp.vector.co.jp/authors/VA013133/archives/ \
		http://www.demonews.com/hosted/masa/archives/

MAINTAINER=	aa8vb@ipass.net

USE_X_PREFIX=	yes
USE_MESA=	yes
MAKEFILE=	makefile
ALL_TARGET=	glclock
MAKE_ENV=	PTHREAD_LIBS="${PTHREAD_LIBS}"

SCRIPTS = benchclock crystalclock f_crystalclock f_glclock		\
	  f_marbleclock f_metalclock f_mwclock f_woodclock marbleclock	\
	  metalclock mwclock woodclock

TEXTURES = marble.ppm sky.ppm wood.ppm

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/glclock ${PREFIX}/bin
	@for f in ${SCRIPTS}; do \
	   ${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/bin; \
	 done
	@mkdir -p ${PREFIX}/lib/X11/glclock
	@for f in ${TEXTURES}; do \
	   ${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/lib/X11/glclock; \
	 done

.include <bsd.port.mk>
