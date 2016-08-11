# $FreeBSD$

PORTNAME=	math77
PORTVERSION=	6.0
CATEGORIES=	math
MASTER_SITES=	NL/math
DISTNAME=	${PORTNAME}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	mexas@bris.ac.uk
COMMENT=	CalTech mathematical subprogram libraries for Fortran 77

LICENSE=	BSD3CLAUSE

BROKEN_powerpc64=	Does not build

USES=		fortran gmake tar:tgz
WRKSRC=		${WRKDIR}/MATH77
MAKEFILE=	makefile
USE_LDCONFIG=	yes

PLIST_FILES=	lib/libmath77.a

DEMO=	cblas ccoef cgam cge2 cgefsc cpolz csort cwofz daccum dasinh dbacc \
	dbesj0 dbesjn dbi0k0 dbinom dblas1 dblas2 dblas3 dblas4 dc2fit dcdchi \
	dcdnml dcdpoi dcft dchol dchol2 dckder dcon dcpltk dcpval ddasl1 \
	ddasl2 ddasl3 ddasl4 ddasl5 ddasl6 ddasl7 dei deli derf derfce derfi \
	devun devvun dfmin dfrenl dgami dgamma dge2 dgefsc dherql dhfti dhint \
	dhtcc dilup dilupm dint1f dint1r dintmf dintmr diva divdb divx djacg1 \
	djacg2 dlasum dlesum dlnrel dmess dmlc01 dmpval dnlafb dnlafu dnlagb \
	dnlagu dnlsfb dnlsfu dnlsgb dnlsgu dnqsol dpfit dplot dpoi dpolz \
	dpolz2 dprpl dprpl1 dprpl2 dpsi dran drane drang drangv dranr dranu \
	dranus drft drft1 dsbasd dsfit dsfitc dsi dsort dspge dsva dsvdrs \
	dsymql dtcst dtgfi dtgfi1 dtgfi2 dtgrec ducom2 ducomp dwcom2 dwcomp \
	dxrk8 dzero ermsg err1 exsort gsortp idranp insort isort isranp mach \
	matp matpr ran1 saccum sasinh sbacc sbesj0 sbesjn sbi0k0 sbinom sblas1 \
	sblas2 sblas3 sblas4 sc2fit scdchi scdnml scdpoi scft schol schol2 \
	sckder scon scpltk scpval sdasl1 sdasl2 sdasl3 sdasl4 sdasl5 sdasl6 \
	sdasl7 sei seli serf serfce serfi sevun sevvun sfmin sfrenl sgami \
	sgamma sge2 sgefsc sherql shfti shint shtcc silup silupm sint1f sint1r \
	sintmf sintmr siva sivdb sivx sjacg1 sjacg2 slasum slesum slnrel smess \
	smlc01 smpval snlafb snlafu snlagb snlagu snlsfb snlsfu snlsgb snlsgu \
	snqsol spfit splot spoi spolz spolz2 sprpl sprpl1 sprpl2 spsi sran \
	srane srang srangv sranr sranu sranus srft srft1 ssbasd ssfit ssfitc \
	ssi ssort sspge ssva ssvdrs ssymql stcst stgfi stgfi1 stgfi2 stgrec \
	sucom2 sucomp swcom2 swcomp sxrk8 szero vecp vecpr xblas zcoef zcomp \
	zgam zpolz zwofz

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmath77.a ${STAGEDIR}${PREFIX}/lib

do-test:
.for CODE in ${DEMO}
	(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} code=${CODE} ${MAKE_CMD} demo)
.endfor

.include <bsd.port.mk>
