# New ports collection makefile for:	ecs
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ecs
DISTVERSION=	1.3.c
CATEGORIES=	science
MASTER_SITES=	http://www.edf.fr/html/RetD/livraison_saturne_${REL_DATE}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Preprocessor

LIB_DEPENDS=	med.2:${PORTSDIR}/french/med		\
		bft.1:${PORTSDIR}/science/bft		\
		hdf5.0:${PORTSDIR}/science/hdf5		\
		cgns.0:${PORTSDIR}/science/cgnslib

REL_DATE=	070305

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-bft-prefix=${LOCALBASE}	\
		--with-hdf5-prefix=${LOCALBASE}	\
		--with-cgns-prefix=${LOCALBASE}	\
		--with-med-prefix=${LOCALBASE}	\
		--with-metis-prefix=${LOCALBASE}
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}

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

PORTDOCS=	mi_ecs.pdf mu_ecs.pdf

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/partdmesh)
# The regular metis is there, cannot depends on metis-edf
LIB_DEPENDS+=	metis.1:${PORTSDIR}/math/metis
.else
# Prefer metis-edf to avoid conflict with Code_Aster
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis-edf
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
