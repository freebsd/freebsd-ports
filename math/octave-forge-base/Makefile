# Created by: Stephen Montgomery-Smith <stephen@math.missouri.edu>
# $FreeBSD$

PORTNAME=	octave-forge-base
PORTVERSION=	1.4
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	#none
DISTFILES=	#none
EXTRACT_ONLY=	#none

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Octave-forge baseport for all packages

LICENSE=	BSD2CLAUSE

RUN_DEPENDS=	octave:math/octave \
		gmake:devel/gmake \
		p5-File-Remove>=0:devel/p5-File-Remove

USES=		perl5
SUB_FILES=	load-octave-pkg
SUB_LIST=	PERL=${PERL}
NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/octave/tarballs
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/octave
	${INSTALL_SCRIPT} ${WRKDIR}/load-octave-pkg ${STAGEDIR}${PREFIX}/libexec/octave/.

.include <bsd.port.mk>
