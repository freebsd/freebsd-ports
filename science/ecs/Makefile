# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ecs
PORTVERSION=	2.0.2
PORTREVISION=	2
CATEGORIES=	science
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Preprocessor

LICENSE=	GPLv2

LIB_DEPENDS=	med.5:${PORTSDIR}/french/med		\
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

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDOCS}
USE_TEX=	tex:build
BUILD_DEPENDS+=	fig2dev:${PORTSDIR}/print/transfig
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
.if ${PORT_OPTIONS:MDOCS}
	${REINPLACE_CMD} -e '/^SUBDIRS/s| po| po doc|' ${WRKSRC}/Makefile.in
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
