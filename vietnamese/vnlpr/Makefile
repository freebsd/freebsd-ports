# Created by: David O'Brien (obrien@cs.ucdavis.edu)
# $FreeBSD$

PORTNAME=	vnlpr
PORTVERSION=	2.0
CATEGORIES=	vietnamese print
MASTER_SITES=	ftp://ftp.monash.edu.au/pub/vietnam/unix/
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@FreeBSD.org
COMMENT=	Shell script and set of fonts to print Vietnamese text on PostScript printer

BROKEN=		Conflicts with dependency vnpstext on share/vn-fonts/initcour.ps
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2014-11-26

RUN_DEPENDS=	vn7to8:${PORTSDIR}/vietnamese/vn7to8 \
		vnpstext:${PORTSDIR}/vietnamese/vnpstext

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${MV} ${WRKSRC}/vnlpr ${WRKSRC}/vnlpr.in

do-build:
	${SED} -e "s:^set VNLIB=./:set VNLIB=${PREFIX}/share/vn-fonts:"  \
	    -e 's/^set PRINTER="barrons"/#set PRINTER="postscript"/'  \
		${WRKSRC}/vnlpr.in > ${WRKSRC}/vnlpr

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/vnlpr ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/vn-fonts
	${INSTALL_DATA} ${WRKSRC}/*.ps ${STAGEDIR}${PREFIX}/share/vn-fonts
	${INSTALL_DATA} ${WRKSRC}/*.gsf ${STAGEDIR}${PREFIX}/share/vn-fonts
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
