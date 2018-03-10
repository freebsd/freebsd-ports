# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	ecs
PORTVERSION=	2.0.4
PORTREVISION=	5
CATEGORIES=	science
MASTER_SITES=	http://code-saturne.org/releases/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Preprocessor

LICENSE=	GPLv2

BUILD_DEPENDS+=	${LOCALBASE}/lib/libscotch.a:cad/scotch
LIB_DEPENDS=	libmed.so:french/med	\
		libbft.so:science/bft	\
		libhdf5.so:science/hdf5	\
		libcgns.so:science/cgnslib

USES=		gmake
USE_TEX=	dvipsk
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}		\
		--with-hdf5=${LOCALBASE}	\
		--with-cgns=${LOCALBASE}	\
		--without-adf --without-ccm	\
		--with-scotch=${LOCALBASE}	\
		--with-med=${LOCALBASE}		\
		--with-metis=${LOCALBASE}	\
		--with-metis-include=${LOCALBASE}/include/metis
CONFIGURE_ENV=	PTHREAD_LIBS=-lpthread

OPTIONS_DEFINE=	DOCS NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext iconv
NLS_CONFIGURE_ENABLE=	nls

DOCS_USE=	TEX=tex:build
DOCS_BUILD_DEPENDS=	fig2dev:print/transfig

.include <bsd.port.options.mk>

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	mi_ecs.pdf mt_ecs.pdf
MAKE_JOBS_UNSAFE=yes
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/kmetis)
# The regular metis is present, so we cannot depend on metis-edf
LIB_DEPENDS+=	libmetis.so.1:math/metis4
.else
# Prefer metis-edf to avoid conflict with Code_Aster
LIB_DEPENDS+=	libmetis.so.2:math/metis-edf
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
