# New ports collection makefile for:	jafm
# Date created:			31 August 1998
# Whom:				brett@peloton.physics.montana.edu
#
# $FreeBSD$
#

PORTNAME=	jafm
PORTVERSION=	0.5
CATEGORIES=	x11-fm
MASTER_SITES=	http://www-personal.usyd.edu.au/~rlittlew/jafm/ \
		${MASTER_SITE_SUNSITE}
MASTER_SITE_SUBDIR=	X11/desktop

MAINTAINER=	brett@peloton.runet.edu

USE_QT_VER=	1
USE_BISON=	yes
MAKE_ENV=	Cxx="${CXX}" CxxFLAGS="${CXXFLAGS}"
ALL_TARGET=	jafm

MAN8=	jafm.8

.include <bsd.port.mk>
