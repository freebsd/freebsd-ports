# ex:ts=8
# New ports collection makefile for:  vnlpr
# Version required:	2.0
# Date created:		Sat Dec 7, 1996
# Whom:			David O'Brien (obrien@cs.ucdavis.edu)
#
# $FreeBSD$
#

DISTNAME=	vnlpr
PKGNAME=	vi-vnlpr-2.0
CATEGORIES=	vietnamese print
MASTER_SITES=	ftp://ftp.media.mit.edu/pub/Vietnet/Viscii/Unix/  \
		ftp://ftp.monash.edu.au/pub/vietnam/unix/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=     obrien@FreeBSD.org

RUN_DEPENDS=	vn7to8:${PORTSDIR}/vietnamese/vn7to8 \
		vnpstext:${PORTSDIR}/vietnamese/vnpstext

pre-patch:
	@${MV} ${WRKSRC}/vnlpr ${WRKSRC}/vnlpr.in

do-build:
	${SED} -e "s:^set VNLIB=./:set VNLIB=${PREFIX}/share/vn-fonts:"  \
	    -e 's/^set PRINTER="barrons"/#set PRINTER="postscript"/'  \
		${WRKSRC}/vnlpr.in > ${WRKSRC}/vnlpr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vnlpr ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/vn-fonts
	${INSTALL_DATA} ${WRKSRC}/*.ps ${PREFIX}/share/vn-fonts
	${INSTALL_DATA} ${WRKSRC}/*.gsf ${PREFIX}/share/vn-fonts
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/vnlpr
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/vnlpr
	${INSTALL_MAN} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/vnlpr
.endif

.include <bsd.port.mk>
