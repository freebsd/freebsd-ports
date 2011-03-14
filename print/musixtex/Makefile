# New ports collection makefile for:    musixtex
# Date created:         9 july 1995
# Whom:                 jmz
#
# $FreeBSD$
#

PORTNAME=	musixtex
PORTVERSION=	T112
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/macros/musixtex/taupin/
DISTFILES=	musixtex-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A set of TeX macros to typeset music

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

BUILD_DEPENDS=	initex:${PORTSDIR}/print/tex
RUN_DEPENDS=	initex:${PORTSDIR}/print/tex

EXAMPLE_VERSION=    T112
DISTFILES+=         musixexa-${EXAMPLE_VERSION}.tar.gz

post-extract:
	@${MKDIR} ${WRKDIR}/musixtex-${PORTVERSION}/examples
	@${CP} ${WRKDIR}/musixexa-${EXAMPLE_VERSION}/* ${WRKDIR}/musixtex-${PORTVERSION}/examples/

pre-install:
	${MKDIR} ${PREFIX}/share/texmf/documentation

post-install:
	@${LOCALBASE}/bin/texhash || ${TRUE}

.include <bsd.port.mk>
