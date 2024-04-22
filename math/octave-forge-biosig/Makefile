PORTNAME=	octave-forge-biosig
DISTVERSION=	3.0.1
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	https://pub.ist.ac.at/~schloegl/biosig/prereleases/
DISTNAME=	biosig4octave-${DISTVERSION}.src

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

LIB_DEPENDS+=	libbiosig.so:biology/biosig

USES=		octave

ALL_TARGET=	# nada

OCTAVE_SRC=		${DISTNAME:R}

.include <bsd.port.mk>
