# New ports collection makefile for:	chemtool-devel
# Date created:                 Mar 5, 2003
# Whom:				NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.6.1
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
DISTNAME=	ct161gtk2
EXTRACT_SUFX=   .tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Drawing organic molecules easily and store them (developer version)

LIB_DEPENDS=    EMF.1:${PORTSDIR}/graphics/libemf
RUN_DEPENDS=	transfig:${PORTSDIR}/print/transfig

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-gtk2/
USE_REINPLACE=	yes
USE_GTK=	yes
USE_AUTOCONF=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ARGS= --enable-emf=yes
PKGNAMESUFFIX=  -devel
MAN1=	chemtool.1 cht.1

post-patch:
	${REINPLACE_CMD} -e 's+%%LOCALBASE%%+${LOCALBASE}+g;' ${WRKSRC}/Makefile.in

do-install:
	@(cd ${WRKSRC}; ${GMAKE} install)
	@(cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/share/examples/chemtool/; \
	cd ${WRKSRC}/examples/; \
	${INSTALL_DATA} * ${PREFIX}/share/examples/chemtool; \
	)

.include <bsd.port.mk>
