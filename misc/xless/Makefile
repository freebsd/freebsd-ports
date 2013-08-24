# Created by: Conrad Sabatier <conrads@home.com>
# $FreeBSD$

PORTNAME=	xless
PORTVERSION=	1.7
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_XCONTRIB} \
		ftp://ftp.cs.berkeley.edu/ucb/people/dglo/xless/
MASTER_SITE_SUBDIR=	applications

MAINTAINER=	ports@FreeBSD.org
COMMENT=	X11-based viewer for text files

USES=		imake
USE_XORG=	ice sm x11 xaw xext xmu xpm xt
MAKE_ARGS=	MAKE="${MAKE_CMD}"

MAN1=		xless.1
MANCOMPRESSED=	yes

.include <bsd.port.mk>
