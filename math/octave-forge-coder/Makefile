PORTNAME=	octave-forge-coder
DISTVERSIONPREFIX=	coder-
DISTVERSION=	1.8.4
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTAVE_SRC}/COPYING

USES=		octave
USE_GITHUB=	yes
GH_ACCOUNT=	shsajjadi
GH_PROJECT=	OctaveCoder

OCTAVE_SRC=		${GH_PROJECT}-coder-${DISTVERSION}

WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

do-build:
	cd ${WRKSRC} && \
	octave-cli -W -H -q --no-site-file --eval "pre_install" && \
	${RM} pre_install.m

.include <bsd.port.mk>
