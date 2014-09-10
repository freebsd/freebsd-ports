# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ecs
PORTVERSION=	2.0.2
PORTREVISION=	7
CATEGORIES=	science
MASTER_SITES=	http://research.edf.com/fichiers/fckeditor/Commun/Innovation/logiciels/code_saturne/Releases/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Preprocessor

LICENSE=	GPLv2

LIB_DEPENDS=	libmed.so:${PORTSDIR}/french/med	\
		libbft.so:${PORTSDIR}/science/bft	\
		libhdf5.so:${PORTSDIR}/science/hdf5	\
		libcgns.so:${PORTSDIR}/science/cgnslib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

USES=		gmake zip
USE_TEX=	dvipsk
GNU_CONFIGURE=	yes
CPPFLAGS=	-I${LOCALBASE}/include
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}		\
		--with-hdf5=${LOCALBASE}	\
		--with-cgns=${LOCALBASE}	\
		--with-med=${LOCALBASE}		\
		--with-metis=${LOCALBASE}	\
		--with-metis-include=${LOCALBASE}/include/metis
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} CPPFLAGS="${CPPFLAGS}"	\
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_CCMIO)
LIB_DEPENDS+=	libadf.so:${PORTSDIR}/science/libccmio	\
		libccmio.so:${PORTSDIR}/science/libccmio
CONFIGURE_ARGS+=--with-adf=${LOCALBASE}		\
		--with-ccm=${LOCALBASE}
.else
CONFIGURE_ARGS+=--without-adf --without-ccm
.endif

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

DOCS_USE=	TEX=tex:build
DOCS_BUILD_DEPENDS=	fig2dev:${PORTSDIR}/print/transfig

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	mi_ecs.pdf mt_ecs.pdf
MAKE_JOBS_UNSAFE=yes
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/graphchk)
# The regular metis is present, so we cannot depend on metis-edf
LIB_DEPENDS+=	libmetis.so.1:${PORTSDIR}/math/metis4
.else
# Prefer metis-edf to avoid conflict with Code_Aster
LIB_DEPENDS+=	libmetis.so.0:${PORTSDIR}/math/metis-edf
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
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
