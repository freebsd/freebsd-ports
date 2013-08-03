# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	sowing
PORTVERSION=	1.1.16
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/sowing/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text processing tools to generate documentation from source files

BUILD_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm
RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm

USES=		perl5
USE_GHOSTSCRIPT=yes
USE_GMAKE=	yes
USE_TEX=	latex dvipsk
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"
CONFIGURE_ARGS=	--datadir=${DATADIR}
ALL_TARGET=	all-redirect

MAN1=		bfort.1 doctext.1 tohtml.1

.if defined(MAINTAINER_MODE)
regression-test: install
	@(cd ${BUILD_WRKSRC};	\
	${SETENV} ${MAKE_ENV} ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} testing)
.endif

.include <bsd.port.mk>
