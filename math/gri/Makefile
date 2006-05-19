# New ports collection makefile for: gri
# Date created:		14 Oct 2000
# Whom:			M. L. Dodson, <bdodson@scms.utmb.edu>
#
# $FreeBSD$
#

PORTNAME=	gri
PORTVERSION=	2.12.11
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	christopher.illies@ki.se
COMMENT=	An extensible plotting language for producing scientific graphs

LIB_DEPENDS=	netcdf.1:${PORTSDIR}/science/netcdf

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	convert:${PORTSDIR}/graphics/ImageMagick	\
		dvips:${PORTSDIR}/print/dvipsk-tetex
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-FreeBSD
USE_GMAKE=	yes
REINPLACE_ARGS=	-Ei.bak
MAKE_ENV+=	MAKEINFOFLAGS=--no-split

MAN1=	gri.1 gri_merge.1 gri_unpage.1
INFO=	gri

post-patch:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e '/^(DIST_)?SUBDIRS/s/doc//' ${WRKSRC}/Makefile.in
.endif

post-install:
.if defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/doc/gri-manpage.1 ${MANPREFIX}/man/man1/gri.1
	${INSTALL_MAN} ${WRKSRC}/doc/gri_merge.1-skel ${MANPREFIX}/man/man1/gri_merge.1
	${INSTALL_MAN} ${WRKSRC}/doc/gri_unpage.1-skel ${MANPREFIX}/man/man1/gri_unpage.1
	${INSTALL_DATA} ${WRKSRC}/doc/gri.info* ${PREFIX}/info
.endif

.include <bsd.port.mk>
