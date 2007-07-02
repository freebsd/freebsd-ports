# New ports collection makefile for:	xlisp-stat
# Date created:				Tue Aug 15 17:57:48 CDT 1995
# Whom:					Eric L. Hernes <erich@rrnet.com>
#
# $FreeBSD$
#

PORTNAME=	xlispstat
PORTVERSION=	3.52.20
PORTREVISION=	1
CATEGORIES=	math lang lisp
MASTER_SITES=	ftp://ftp.stat.umn.edu/pub/xlispstat/current/ \
		http://lib.stat.cmu.edu/xlispstat/Src/current/ \
		ftp://ftp.stat.unipg.it/pub/stat/xlispstat/current/ \
		ftp://srsuna.shlrc.mq.edu.au/pub/xlispstat/current/ \
		ftp://statlab.uni-heidelberg.de/pub/mirrors/umn/xlispstat/current/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./-/g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A statistics/X11 based lisp interpreter

USE_XLIB=	yes
GNU_CONFIGURE=	yes
ALL_TARGET=	${PORTNAME}

post-patch:
	@${REINPLACE_CMD} '/^static double fmax/d' ${WRKSRC}/lowess.c

.include <bsd.port.mk>
