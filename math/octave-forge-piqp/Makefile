PORTNAME=	octave-forge-piqp
PORTVERSION=	0.5.0
CATEGORIES=	math
MASTER_SITES=	https://github.com/PREDICT-EPFL/piqp/releases/download/v0.5.0/
DISTNAME=	piqp-octave

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge package ${OCTAVE_PKGNAME}
WWW=		https://packages.octave.org/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		octave

OCTAVE_SRC=	${DISTNAME}
WRKSRC=		${WRKDIR}/${OCTAVE_SRC}

do-build:
	cd ${WRKSRC}; \
	octave-cli -W -H -q --no-site-file --eval make_piqp
	${RM} ${WRKSRC}/src/piqp/interfaces/octave/package/DESCRIPTION
	${RM} ${WRKSRC}/pre_install.m
	${MV} ${WRKSRC}/piqp_oct.oct ${WRKSRC}/inst/.

.include <bsd.port.mk>
