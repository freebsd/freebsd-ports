# New ports collection makefile for:	snortsnarf
# Date created:		29 July 2001
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	snortsnarf
PORTVERSION=	050314
CATEGORIES=	security
MASTER_SITES=	http://www.snort.org/dl/contrib/data_analysis/snortsnarf/
DISTNAME=	SnortSnarf-${PORTVERSION}.1

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	Generate HTML report summaries from snort incident alerts

RUN_DEPENDS=	${SITE_PERL}/Time/JulianDay.pm:${PORTSDIR}/devel/p5-Time-modules

NO_BUILD=	yes

do-install:
	${SED} s,%LOCALBASE%,${LOCALBASE}, < ${WRKSRC}/snortsnarf.pl > ${WRKSRC}/snortsnarf
	${INSTALL_SCRIPT} ${WRKSRC}/snortsnarf ${LOCALBASE}/bin/snortsnarf
	${MKDIR} ${LOCALBASE}/libdata/snortsnarf
	${MKDIR} ${LOCALBASE}/libdata/snortsnarf/SnortSnarf
.for i in IPAddrContact.pm ann_xml.pl web_utils.pl xml_help.pl
	${INSTALL_DATA} ${WRKSRC}/include/${i} ${LOCALBASE}/libdata/snortsnarf/
.endfor
.for i in AlertBase.pm HTMLOutput.pm MemTimeBase.pm MultiStore.pm \
	MemPacket.pm HTMLMemStorage.pm Filtering.pm PacketBase.pm \
	AllMods.pm BasicFilters.pm KnownEquiv.pm SnortFileInput.pm \
	HTMLAnomMemStorage.pm Input.pm SorterBase.pm Sort.pm \
	StorageBase.pm MemAlert.pm BasicSorters.pm Filter.pm \
	SnortRules.pm MemStorage.pm SnortDBInput.pm TimeFilters.pm \
	IPObfuscater.pm
	${INSTALL_DATA} ${WRKSRC}/include/SnortSnarf/${i} ${LOCALBASE}/libdata/snortsnarf/SnortSnarf/
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${LOCALBASE}/share/doc/snortsnarf
.for i in README Usage
	${INSTALL_DATA} ${WRKSRC}/${i} ${LOCALBASE}/share/doc/snortsnarf
.endfor
.endif

.include <bsd.port.mk>
