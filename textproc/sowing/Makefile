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

USES=		gmake perl5
USE_GHOSTSCRIPT=yes
USE_TEX=	latex dvipsk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR}
ALL_TARGET=	all-redirect

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)\($$(exec_prefix)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(bindir)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(datadir)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(man1dir)\)|\1$$(DESTDIR)\2|' \
		${WRKSRC}/Makefile.in

.if defined(MAINTAINER_MODE)
regression-test: install
	@(cd ${BUILD_WRKSRC};	\
	${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} testing)
.endif

.include <bsd.port.mk>
