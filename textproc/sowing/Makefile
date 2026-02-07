PORTNAME=	sowing
PORTVERSION=	1.1.18
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://ftp.mcs.anl.gov/pub/sowing/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Text processing tools to generate documentation from source files
WWW=		http://web.engr.illinois.edu/~wgropp/projects/software/sowing/

BUILD_DEPENDS=	ppmtogif:graphics/netpbm
RUN_DEPENDS=	ppmtogif:graphics/netpbm

USES=		ghostscript gmake perl5 tex
USE_TEX=	latex dvipsk

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=${PREFIX}/share
CONFIGURE_ARGS=	--datadir=${DATADIR}

MAKE_JOBS_UNSAFE=	yes
ALL_TARGET=	all-redirect

CONFLICTS_INSTALL=	bib2html # bin/bib2html

post-patch:
	@${REINPLACE_CMD} -e \
		's|\([[:blank:]]\)\($$(exec_prefix)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(bindir)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(datadir)\)|\1$$(DESTDIR)\2| ; \
		 s|\([[:blank:]]\)\($$(man1dir)\)|\1$$(DESTDIR)\2|' \
		${WRKSRC}/Makefile.in

.if defined(MAINTAINER_MODE)
regression-test: install
	@(cd ${BUILD_WRKSRC} && ${DO_MAKE_BUILD} testing)
.endif

.include <bsd.port.mk>
