# New ports collection makefile for: gri
# Date created:		14 Oct 2000
# Whom:			M. L. Dodson, <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	gri
PORTVERSION=	2.4.4
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.phys.ocean.dal.ca/users/kelley/gri/source/
EXTRACT_SUFX=	.tgz

MAINTAINER=	bdodson@scms.utmb.edu

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

GNU_CONFIGURE=	YES

ALL_TARGET=	gri
MAN1=		gri.1
MANCOMPRESSED=	yes

post-install:
.if !defined(${NOPORTDOCS})
	@-mkdir -p ${PREFIX}/share/doc/gri
	@-mkdir -p ${PREFIX}/share/doc/gri/html
	@-mkdir -p ${PREFIX}/share/doc/gri/html/examples
	@-mkdir -p ${PREFIX}/share/doc/gri/html/resources
	@cd ${WRKSRC}/doc && make PREFIX=${PREFIX} html-install
.endif
	@cd ${WRKSRC}/doc && \
		make PREFIX=${PREFIX} INSTALL_MAN="${INSTALL_MAN}" man-install
	${CHMOD} 555 ${PREFIX}/bin/gri_merge
	${CHMOD} 555 ${PREFIX}/bin/gri_unpage
	${RM} ${PREFIX}/share/gri/license.txt

.include <bsd.port.mk>
