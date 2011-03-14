# New ports collection makefile for:	pclprint
# Date created:		27 Aug 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	pclprint
PORTVERSION=	1.0
CATEGORIES=	print
MASTER_SITES=	ftp://andrsn.stanford.edu/pub/print/ \
		http://www.psn.net/~andrews/dist/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for printing to HP (Laser,Desk)Jets using PCL rather than PS

DEPRECATED=     Upstream disapear and distfile is no more available
EXPIRATION_DATE=        2011-05-01

NO_BUILD=	YES

do-install:
	@${MKDIR} ${PREFIX}/share/pclprint
	@${MKDIR} ${PREFIX}/share/pclprint/pclcodes
	@${INSTALL_SCRIPT} ${WRKSRC}/qp ${PREFIX}/bin
.for i in pagin.awk qp.awk pcl.awk
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/bin
.endfor
.for i in addfont djfontcodetext fontcodetext letters pclprint.doc
	@${INSTALL_DATA} ${WRKSRC}/$i ${PREFIX}/share/pclprint
.endfor
.for i in albertusextrab albertusmed antiqueolive antiqueoliveb \
	antiqueolivei arial arialb arialbi ariali begin bold cgtimes \
	cgtimesb cgtimesbi cgtimesi clarendoncond coronet courier \
	courierb courierbi courieri couriervh couriervhb couriervhi \
	eject end fn fnbegin fnend fontcodetext garamondantiqua \
	garamondhalbfett garamondkurhalb garamondkursiv ital land left \
	lettergoth lettergothb lettergothi lineprinter marigold nobold \
	noital nounder omega omegab omegabi omegai port symbol \
	tablebegin tableend timesnew timesnewb timesnewbi timesnewi \
	under univers universb universbcond universbcondi universbi \
	universi universmedcond universmedcondi vmi wingdings
	@${INSTALL_DATA} ${WRKSRC}/pclcodes/$i ${PREFIX}/share/pclprint/pclcodes
.endfor

.include <bsd.port.mk>
