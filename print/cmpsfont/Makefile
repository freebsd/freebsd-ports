# New ports collection makefile for:	cmps
# Date created:		11 September 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	cmpsfont
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://ftp.ams.org/pub/tex/psfonts/cm/
DISTNAME=	cmps
EXTRACT_SUFX=	-unix.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Computer Modern PostScript Fonts (Adobe Type 1 format)

BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/cmpsfont
TEXDIR?=	${PREFIX}/share/texmf

IGNORE=		is already included in the teTeX distribution

do-build:
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog)

do-install:
	@${MKDIR} ${TEXDIR}/fonts/type1
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${TEXDIR}/fonts/type1
	@${MKDIR} ${PREFIX}/lib/afm
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/lib/afm

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/cmpsfont
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/cmpsfont
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
