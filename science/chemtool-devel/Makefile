# New ports collection makefile for:	chemtool
# Date created:			Mar 5, 2003
# Whom:				NAKATA, Maho <maho@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	chemtool
PORTVERSION=	1.6
CATEGORIES=	science
MASTER_SITES=	http://ruby.chemie.uni-freiburg.de/~martin/chemtool/
DISTNAME=	ct16a29
EXTRACT_SUFX=   .tgz

MAINTAINER=	maho@FreeBSD.org
COMMENT=	Drawing organic molecules easily and store them (develop version)

RUN_DEPENDS=	transfig:${PORTSDIR}/print/transfig

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}alpha29
USE_REINPLACE=	yes
USE_GTK=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAN1=	chemtool.1 cht.1

do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${GMAKE})

do-install:
	@(cd ${WRKSRC}; ${GMAKE} install)
	@(cd ${WRKSRC}; \
	${MKDIR} ${PREFIX}/share/examples/chemtool/; \
	cd ${WRKSRC}/examples/; \
	${INSTALL_DATA} * ${PREFIX}/share/examples/chemtool; \
	)

.include <bsd.port.mk>
