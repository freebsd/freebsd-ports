# New ports collection makefile for:	xvid
# Date created:		04 April 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net> et al
#
# $FreeBSD$
#

PORTNAME=	xvid
PORTVERSION=	0.9.1
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://files.xvid.org/downloads/
DISTNAME=	${PORTNAME}core-${PORTVERSION}

MAINTAINER=	michaelnottebrock@gmx.net
COMMENT=	An opensource MPEG-4 codec, based on OpenDivx

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

HAS_CONFIGURE=	yes
USE_GMAKE=	yes
INSTALLS_SHLIB=	yes

WRKSRC=			${WRKDIR}/${DISTNAME}/build/generic

post-install:
	@ ${LN} -sf libxvidcore.so ${PREFIX}/lib/libxvidcore.so.0

.include <bsd.port.mk>
