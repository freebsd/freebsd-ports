# ex:ts=8
# Ports collection makefile for:  gv
# Date created:			  16 Apr 1996
# Whom:				  tg@freebsd.org
#
# $FreeBSD$
#

PORTNAME=	gv
PORTVERSION=	3.5.8
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/gv/unix/  \
		${MASTER_SITE_TEX_CTAN}
MASTER_SITE_SUBDIR=	support/ghostscript/gnu/gv/unix

PATCHFILES=	gv_3.5.8-26.1.diff.gz
PATCH_SITES=	http://security.debian.org/pool/updates/main/g/gv/
PATCH_DIST_STRIP=	-p1

MAINTAINER=	ports@freebsd.org

PORTCOMMENT=	A PostScript and PDF previewer

LIB_DEPENDS=	Xaw3d.${XAWVER}:${PORTSDIR}/x11-toolkits/Xaw3d

USE_IMAKE=	yes
MAN1=		gv.1

post-install:
.if !defined(NOPORTDOCS)
	@(cd ${WRKSRC}; ${MAKE_ENV} ${MAKE} install.doc)
.endif
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
