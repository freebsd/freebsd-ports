# Created by: Yuri Victorovich <yuri@rawbw.com>
# $FreeBSD$

PORTNAME=	uchardet
PORTVERSION=	0.0.6
CATEGORIES=	textproc
MASTER_SITES=	https://www.freedesktop.org/software/${PORTNAME}/releases/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Universal charset detection library

LICENSE=	GPLv2+ LGPL21+ MPL11
LICENSE_COMB=	dual
LICENSE_FILE_MPL11=	${WRKSRC}/COPYING

USES=		cmake pathfix tar:xz
USE_LDCONFIG=	yes

CMAKE_ARGS=	-DCMAKE_INSTALL_MANDIR:PATH=${MANPREFIX}/man

.include <bsd.port.mk>
