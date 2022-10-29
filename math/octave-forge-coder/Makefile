PORTNAME=	octave-forge-coder
DISTVERSIONPREFIX=	coder-
DISTVERSION=	1.7.0
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	shsajjadi
GH_PROJECT=	OctaveCoder

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${GH_PROJECT}-coder-${DISTVERSION}

WRKSRC=		${WRKDIR}/${OCTSRC}

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

do-build:
	cd ${WRKSRC} && \
	octave-cli -W -H -q --no-site-file --eval "pre_install" && \
	${RM} pre_install.m

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
