# New ports collection makefile for:	ecs
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ecs
PORTVERSION=	2.0.2
CATEGORIES=	science
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Preprocessor

LICENSE=	GPLv2

LIB_DEPENDS=	med.4:${PORTSDIR}/french/med		\
		bft.1:${PORTSDIR}/science/bft		\
		hdf5.7:${PORTSDIR}/science/hdf5-18	\
		cgns.3:${PORTSDIR}/science/cgnslib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USE_ZIP=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}		\
		--with-hdf5=${LOCALBASE}	\
		--with-cgns=${LOCALBASE}	\
		--with-med=${LOCALBASE}		\
		--with-metis=${LOCALBASE}	\
		--with-metis-include=${LOCALBASE}/include/metis
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
USE_GMAKE=	yes

.if defined(WITH_CCMIO)
LIB_DEPENDS+=	adf.5:${PORTSDIR}/science/libccmio	\
		ccmio.2:${PORTSDIR}/science/libccmio
CONFIGURE_ARGS+=--with-adf=${LOCALBASE}		\
		--with-ccm=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-adf --without-ccm
.endif

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
USE_ICONV=	yes
PLIST_SUB+=	NLS=""
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	pdflatex:${PORTSDIR}/print/teTeX-base	\
		fig2dev:${PORTSDIR}/print/transfig
PORTDOCS=	mi_ecs.pdf mt_ecs.pdf
.endif

MAN1=	cs_io_dump.1 cs_partition.1 cs_preprocess-config.1 cs_preprocess.1

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/partdmesh)
# The regular metis is present, so we cannot depend on metis-edf
LIB_DEPENDS+=	metis.1:${PORTSDIR}/math/metis4
.else
# Prefer metis-edf to avoid conflict with Code_Aster
BUILD_DEPENDS+=	${LOCALBASE}/bin/onmetis.exe:${PORTSDIR}/math/metis-edf
.endif

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	${LOCALBASE}/lib/libscotch.a:${PORTSDIR}/cad/scotch
CONFIGURE_ARGS+=	--with-scotch=${LOCALBASE}
.endif

pre-configure:
.if !defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^SUBDIRS/s| po| po doc|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
