# New ports collection makefile for:	amspsfnt
# Date created:		11 September 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	amspsfnt
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.ams.org/pub/tex/psfonts/ams/
DISTNAME=	amsps
EXTRACT_SUFX=	-unix.tar.gz

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	$(LOCALBASE)/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst

WRKSRC=		$(WRKDIR)/amspsfnt
TEXDIR=		$(PREFIX)/share/texmf
AMSFNTDIR=	$(TEXDIR)/fonts/ams

do-build:
	(cd ${WRKSRC}/pfb; $(LOCALBASE)/bin/type1inst -nolog -q)

do-install:
	@${MKDIR} $(AMSFNTDIR)/tfm
	$(INSTALL_DATA) ${WRKSRC}/tfm/* $(AMSFNTDIR)/tfm
	@${MKDIR} $(AMSFNTDIR)/type1
	$(INSTALL_DATA) ${WRKSRC}/pfb/* $(AMSFNTDIR)/type1
	@${MKDIR} $(TEXDIR)/dvips/mapfiles.ams
	$(INSTALL_DATA) ${WRKSRC}/mapfiles/* $(TEXDIR)/dvips/mapfiles.ams
	@${MKDIR} $(PREFIX)/lib/afm
	$(INSTALL_DATA) ${WRKSRC}/afm/* $(PREFIX)/lib/afm

.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	$(INSTALL_DATA) ${WRKSRC}/READ.ME ${DOCSDIR}
.endif

.include <bsd.port.mk>
