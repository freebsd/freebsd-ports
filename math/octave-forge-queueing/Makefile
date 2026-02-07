PORTNAME=	octave-forge-queueing
DISTVERSION=	1.2.8
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

BUILD_DEPENDS+=	fig2dev:print/fig2dev

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave tex
USE_TEX=	base:build tex:build
USE_GITHUB=	yes
GH_ACCOUNT=	mmarzolla
GH_PROJECT=	queueing

OCTAVE_SRC=	${OCTAVE_PKGNAME}-${DISTVERSION}

WRKSRC=		${WRKDIR}/${OCTAVE_SRC}
ALL_TARGET=	ALL

.include <bsd.port.mk>
