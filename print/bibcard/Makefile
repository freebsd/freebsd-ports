# ex:ts=8
# Ports collection makefile for:  bibcard
# Date created:			  Mon Feb 03, 1997
# Whom:				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

DISTNAME=	bibcard.6.4
PKGNAME=	bibcard-0.6.4
CATEGORIES=	print databases
MASTER_SITES=	ftp://crl.nmsu.edu/pub/misc/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	obrien@NUXI.com

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview

NO_WRKSUBDIR=	yes
USE_IMAKE=	yes
MAN1=		bibcard.1

pre-configure:
	@${ECHO} "OPENWINHOME=${PREFIX}"  \
		>> ${WRKSRC}/Imakefile
	@${ECHO} "EXTRA_DEFINES= -DHAVE_STRCASECMP -DHAVE_STRSTR"  \
		>> ${WRKSRC}/Imakefile
	@${LN} -f ${WRKSRC}/bibcard.1 ${WRKSRC}/bibcard.man

.include <bsd.port.mk>
