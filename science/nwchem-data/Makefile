# $FreeBSD$

PORTNAME=	nwchem-data
DISTVERSIONPREFIX=	v
DISTVERSION=	7.0.0
DISTVERSIONSUFFIX=	-release
CATEGORIES=	science

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Data for NWChem, the computational chemistry software

LICENSE=	ECL20
LICENSE_NAME=	Educational Community License (ECL) 2.0
LICENSE_FILE=	${WRKSRC}/../LICENSE.TXT
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USE_GITHUB=	yes
GH_ACCOUNT=	nwchemgit
GH_PROJECT=	nwchem

WRKSRC_SUBDIR=	src

DATADIR=	${PREFIX}/share/nwchem

NO_BUILD=	yes
NO_ARCH=	yes

do-install:
	cd ${WRKSRC}/basis && ${COPYTREE_SHARE} libraries ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} data ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}/libraryps
.for d in development_psps HGH_LDA library1 library2 ofpw_default paw_default pspw_default pspw_new pspw_old Spin_Orbit TETER TM
	cd ${WRKSRC}/nwpw/libraryps && ${COPYTREE_SHARE} ${d} ${STAGEDIR}${DATADIR}/libraryps/
.endfor

.include <bsd.port.mk>
