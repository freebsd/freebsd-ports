# New ports collection makefile for:	uvscan_dat
# Date created:		01 Sep 2000
# Whom:			Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	uvscan_dat
PORTVERSION=	4319
CATEGORIES=	security
MASTER_SITES=	http://download.nai.com/products/datfiles/4.x/nai/
DISTNAME=	dat-${PORTVERSION}
EXTRACT_SUFX=	.tar

MAINTAINER=	jeh@FreeBSD.org
COMMENT=	AntiVirus DAT file for uvscan

NO_BUILD=	YES
NO_WRKSUBDIR=	YES

RESTRICTED=	"Restricted to the license terms set for VirusScan"

do-configure:
	${SED} -e 's:@PREFIX@:${PREFIX}:g' \
		<${FILESDIR}/update_dat >${WRKDIR}/update_dat

do-install:
	${MKDIR} ${PREFIX}/libexec/uvscan
.for file in clean.dat internet.dat names.dat scan.dat
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/libexec/uvscan
.endfor
	${MKDIR} ${PREFIX}/share/doc/uvscan
.for file in reseller.txt packing.lst
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/uvscan
.endfor
	${INSTALL_SCRIPT} ${WRKDIR}/update_dat ${PREFIX}/sbin
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
