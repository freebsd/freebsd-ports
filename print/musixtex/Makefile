# Created by: jmz
# $FreeBSD$

PORTNAME=	musixtex
PORTVERSION=	T112
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	http://icking-music-archive.org/software/musixtex/
DISTFILES=	musixtex-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of TeX macros to typeset music

BUILD_DEPENDS=	initex:${PORTSDIR}/print/tex
RUN_DEPENDS=	initex:${PORTSDIR}/print/tex

EXAMPLE_VERSION=	T112
DISTFILES+=	musixexa-${EXAMPLE_VERSION}.tar.gz

NO_STAGE=	yes
post-extract:
	@${MKDIR} ${WRKDIR}/musixtex-${PORTVERSION}/examples
	@${CP} ${WRKDIR}/musixexa-${EXAMPLE_VERSION}/* ${WRKDIR}/musixtex-${PORTVERSION}/examples/

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation

post-install:
	@${LOCALBASE}/bin/texhash || ${TRUE}

.include <bsd.port.mk>
