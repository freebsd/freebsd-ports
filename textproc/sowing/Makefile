# New ports collection makefile for:  sowing
# Date created:               27 September 2004
# Whom:                       Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	sowing
PORTVERSION=	1.1.12
PORTREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	ftp://info.mcs.anl.gov/pub/sowing/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Text processing tools to generate documentation from source files

BUILD_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm	\
		latex:${PORTSDIR}/print/teTeX-base
RUN_DEPENDS=	ppmtogif:${PORTSDIR}/graphics/netpbm	\
		dvips:${PORTSDIR}/print/dvipsk-tetex

USE_PERL5=	yes
USE_GHOSTSCRIPT=yes
USE_GMAKE=	yes
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
