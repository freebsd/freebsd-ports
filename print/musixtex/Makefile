# Created by: jmz
# $FreeBSD$

PORTNAME=	musixtex
PORTVERSION=	T112
PORTREVISION=	3
CATEGORIES=	print
MASTER_SITES=	http://icking-music-archive.org/software/musixtex/
DISTFILES=	musixtex-${PORTVERSION}.tar.gz \
		musixexa-${EXAMPLE_VERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of TeX macros to typeset music

BROKEN=		does not build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2017-03-27

USE_TEX=	basic

EXAMPLE_VERSION=	T112

post-extract:
	@${MKDIR} ${WRKDIR}/musixtex-${PORTVERSION}/examples
	@${CP} ${WRKDIR}/musixexa-${EXAMPLE_VERSION}/* \
		${WRKDIR}/musixtex-${PORTVERSION}/examples/

.include <bsd.port.mk>
