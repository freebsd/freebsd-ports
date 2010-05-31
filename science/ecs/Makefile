# New ports collection makefile for:	ecs
# Date created:		Sun 1 apr 2007
# Whom:			thierry@pompo.net
#
# $FreeBSD$
#

PORTNAME=	ecs
PORTVERSION=	1.3.3
PORTREVISION=	4
CATEGORIES=	science
MASTER_SITES=	http://rd.edf.com/fichiers/fckeditor/File/EDF%20RD/Code_Saturne/Fichiers/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.//g}
EXTRACT_SUFX=	.tgz

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Code_Saturne Preprocessor

LIB_DEPENDS=	med.2:${PORTSDIR}/french/med		\
		bft.1:${PORTSDIR}/science/bft		\
		hdf5.0:${PORTSDIR}/science/hdf5		\
		cgns.0:${PORTSDIR}/science/cgnslib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-bft=${LOCALBASE}		\
		--with-hdf5=${LOCALBASE}	\
		--with-cgns=${LOCALBASE}	\
		--with-med=${LOCALBASE}		\
		--with-metis=${LOCALBASE}
CONFIGURE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS}
USE_GMAKE=	yes

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

#NOPORTDOCS=	yes	# PDF not produced ATM
.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	pdflatex:${PORTSDIR}/print/teTeX-base	\
		fig2dev:${PORTSDIR}/print/transfig
PORTDOCS=	mi_ecs.pdf mu_ecs.pdf
.endif

.include <bsd.port.pre.mk>

.if exists(${LOCALBASE}/bin/partdmesh)
# The regular metis is there, cannot depends on metis-edf
LIB_DEPENDS+=	metis.1:${PORTSDIR}/math/metis
.else
# Prefer metis-edf to avoid conflict with Code_Aster
BUILD_DEPENDS+=	${LOCALBASE}/lib/libmetis.a:${PORTSDIR}/math/metis-edf
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
