PORTNAME=	q
DISTVERSIONPREFIX=	v
DISTVERSION=	6.0
PORTREVISION=	1
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Molecular Dynamics (MD) tools
WWW=		https://github.com/qusers/Q6

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/../LICENSE

USES=		fortran:gfortran gmake

USE_GITHUB=	yes
GH_ACCOUNT=	qusers
GH_PROJECT=	Q6

MAKEFILE=	makefile

WRKSRC_SUBDIR=	src

BINARY_ALIAS=	make=${GMAKE} gfortran=gfortran${GCC_DEFAULT}

MAKE_JOBS_UNSAFE=	yes

EXECUTABLES=	Qcalc6 Qdum6 Qdyn6 Qfep6 Qpi6 Qprep6

PLIST_FILES=	${EXECUTABLES:C/(.*)/bin\/\1/}

do-install:
.for e in ${EXECUTABLES}
	${INSTALL_PROGRAM} ${WRKSRC}/../bin/${e} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
