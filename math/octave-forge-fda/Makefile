PORTNAME=	octave-forge-fda
DISTVERSION=	1.0.0
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKDIR}/${OCTSRC}/COPYING

USE_GITLAB=	yes
GL_ACCOUNT=	kakila
GL_PROJECT=	fda
GL_COMMIT=	99f733cfa284fc0fdf911e7da97269197c4dec94

# OCTSRC is the name of the directory of the package.
# It is usually ${OCTAVE_PKGNAME} or ${DISTNAME}.
OCTSRC=		${GL_PROJECT}-${GL_COMMIT}

WRKSRC=		${WRKDIR}/${OCTSRC}/src

do-build:
	@${DO_NADA}

NO_ARCH=	yes

.include "${.CURDIR}/../../Mk/bsd.octave.mk"

post-build:
	${RM} ${WRKSRC}/Makefile ${WRKSRC}/configure
	cd ${WRKDIR} && ${TAR} cfz ${OCTAVE_DISTNAME}.tar.gz ${OCTSRC}

.include <bsd.port.mk>
