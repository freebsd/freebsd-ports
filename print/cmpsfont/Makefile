# New ports collection makefile for:	cmps
# Date created:		11 September 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	cmpsfont
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ams.org/pub/tex/psfonts/cm/
DISTNAME=	cmps
EXTRACT_SUFX=	-unix.tar.gz

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Computer Modern PostScript Fonts (Adobe Type 1 format)

BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

WRKSRC=		${WRKDIR}/cmpsfont
TEXDIR=		${PREFIX}/share/texmf

do-build:
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog -q)

do-install:
	@${MKDIR} ${TEXDIR}/fonts/type1
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${TEXDIR}/fonts/type1
	@${MKDIR} ${PREFIX}/lib/afm
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/lib/afm

.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/cmpsfont
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/cmpsfont
.endif

.include <bsd.port.mk>
