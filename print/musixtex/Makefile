# Created by: jmz
# $FreeBSD$

PORTNAME=	musixtex
PORTVERSION=	T112
PORTREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://icking-music-archive.org/software/musixtex/
DISTFILES=	musixtex-${PORTVERSION}.tar.gz \
		musixexa-${EXAMPLE_VERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Set of TeX macros to typeset music

BUILD_DEPENDS=	initex:print/tex
RUN_DEPENDS=	initex:print/tex

EXAMPLE_VERSION=	T112

post-extract:
	@${MKDIR} ${WRKDIR}/musixtex-${PORTVERSION}/examples
	@${CP} ${WRKDIR}/musixexa-${EXAMPLE_VERSION}/* \
		${WRKDIR}/musixtex-${PORTVERSION}/examples/

.include <bsd.port.mk>
