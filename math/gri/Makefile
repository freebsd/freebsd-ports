# New ports collection makefile for: gri
# Date created:		14 Oct 2000
# Whom:			M. L. Dodson, <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	gri
PORTVERSION=	2.10.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	gri
DISTNAME=	gri-${PORTVERSION}-arch-indep

MAINTAINER=	bdodson@scms.utmb.edu

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
BUILD_DEPENDS=	gawk:${PORTSDIR}/lang/gawk

WRKSRC=		${WRKDIR}/gri-${PORTVERSION}
GNU_CONFIGURE=	YES
MAKE_ENV+=	PREFIX=${PREFIX}
ALL_TARGET=	gri
MAN1=		gri.1

post-extract:
	${CP} ${WRKSRC}/doc/gri-manpage.1 ${WRKSRC}/gri.1

post-install:
.if defined(NOPORTDOCS)
	${RM} -rf ${PREFIX}/share/gri/doc
.endif
	${CHMOD} 555 ${PREFIX}/bin/gri_merge
	${CHMOD} 555 ${PREFIX}/bin/gri_unpage
	${INSTALL_MAN} ${WRKSRC}/gri.1 ${PREFIX}/man/man1
	@-${RM} ${PREFIX}/share/gri/${PORTVERSION}/license.txt

.include <bsd.port.mk>
