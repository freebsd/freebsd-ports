# ex:ts=8
# Ports collection makefile for:  gv
# Date created:			  16 Apr 1996
# Whom:				  tg@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gv
PORTVERSION=	3.5.8
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/  \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/ghostscript/gnu/gv/unix

MAINTAINER=	obrien@freebsd.org

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_IMAKE=	yes
MAN1=		gv.1

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install.doc)
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
