# New ports collection makefile for:	xvid
# Date created:		04 April 2002
# Whom:			Michael Nottebrock <michaelnottebrock@gmx.net> et al
#
# $FreeBSD$
#

PORTNAME=	xvid
PORTVERSION=	0.9.2
PORTEPOCH=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://files.xvid.org/downloads/
DISTNAME=	${PORTNAME}core-${PORTVERSION}

MAINTAINER=	lofi@freebsd.org
COMMENT=	An opensource MPEG-4 codec, based on OpenDivx

BUILD_DEPENDS=	${LOCALBASE}/bin/nasm:${PORTSDIR}/devel/nasm

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

WRKSRC=			${WRKDIR}/${DISTNAME}/build/generic

post-install:
	@ ${LN} -sf ${PREFIX}/lib/libxvidcore.so.2 ${PREFIX}/lib/libxvidcore.so

.include <bsd.port.mk>
