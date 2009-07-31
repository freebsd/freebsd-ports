# New ports collection makefile for:	chemtool-devel
# Date created:                 Mar 5, 2003
# Whom:				NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.7.20050716
PORTREVISION=	3
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/

DISTNAME=	ct17a15
EXTRACT_SUFX=	.tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Drawing organic molecules easily and store them (developer version)

LIB_DEPENDS=	EMF.1:${PORTSDIR}/graphics/libemf
RUN_DEPENDS=	transfig:${PORTSDIR}/print/transfig

WRKSRC=		${WRKDIR}/${PORTNAME}-1.7alpha15/
USE_GNOME=	gtk20
#USE_AUTOTOOLS=	autoconf:213
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes
CONFIGURE_ARGS=	--enable-emf=yes
PKGNAMESUFFIX=	-devel
MAN1=	chemtool.1 cht.1
#to include emf
CFLAGS+=	-I${LOCALBASE}/include/libEMF
CXXFLAGS+=	-I${LOCALBASE}/include/libEMF

post-patch:
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/configure.in
	@${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/configure

do-install:
	@(cd ${WRKSRC}; ${GMAKE} install)
	@(cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/share/examples/chemtool/; \
	cd ${WRKSRC}/examples/; \
	${INSTALL_DATA} * ${PREFIX}/share/examples/chemtool; \
	)

.include <bsd.port.mk>
