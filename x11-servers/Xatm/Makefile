# New ports collection makefile for:	xfs-atm
# Date created:		31 Oct 1999
# Whom:			taguchi@tohoku.iij.ad.jp
#
# $FreeBSD$
#

PORTNAME=	xfs-atm
PORTVERSION=	3.0.1
CATEGORIES=	x11-servers
MASTER_SITES=	http://www.netlab.is.tsukuba.ac.jp/~yokota/archive/
DISTNAME=	${PORTNAME}+cid-${PORTVERSION}

MAINTAINER=	taguchi@tohoku.iij.ad.jp

BROKEN=		"Does not build"

USE_IMAKE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	MAKE=${GMAKE}
MANCOMPRESSED=	yes
MAN1=		xfs-atm.1
DOCFILES=	README.t1-cid+xatm-cap README.t1-cid+xatm-cap.eng \
		README.xfs-atm README.xfs-atm.eng \
		lib/font/Xatm/Q_and_A.Xatm \
		lib/font/Xatm/README lib/font/Xatm/README.eng \
		lib/font/Xatm/README.fonts_cap \
		lib/font/Xatm/README.fonts_cap.eng
DOCPATH=	${PREFIX}/share/doc/Xatm

post-install:
.if !defined(NOPORTDOCS)
	( ${MKDIR} ${DOCPATH} ; \
	   cd ${WRKSRC}; \
	   for i in ${DOCFILES} ; do \
		${INSTALL_DATA} $$i ${DOCPATH}; \
	   done )
.endif

.include <bsd.port.mk>
