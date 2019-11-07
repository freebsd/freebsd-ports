# Created by: Alexander Yerenkow <yerenkow@gmail.com>
# $FreeBSD$

PORTNAME=	x-unikey
PORTVERSION=	1.0.4
CATEGORIES=	vietnamese textproc
MASTER_SITES=	SF/unikey/${PORTNAME}/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vietnamese input method for X

USES=		compiler tar:bzip2 xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes

CXXFLAGS+=	${CXXFLAGS_${CHOSEN_COMPILER_TYPE}}
CXXFLAGS_clang=	-Wno-c++11-narrowing

PLIST_FILES=	bin/unikey bin/ukxim

.include <bsd.port.mk>
