# $FreeBSD$

PORTNAME=	gpaw-setups
DISTVERSION=	0.9.20000
CATEGORIES=	science
MASTER_SITES=	https://wiki.fysik.dtu.dk/gpaw-files/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Setups (data files) for py-gpaw, the DFT quantum chemistry software

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${DATADIR}
	# autoplist for potentials: 500+ files in DATADIR
	@cd ${STAGEDIR}${PREFIX} && \
		${FIND} ${DATADIR:S/^${PREFIX}\///} -type f >> ${TMPPLIST}

.include <bsd.port.mk>
