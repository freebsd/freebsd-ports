# New ports collection makefile for:	ifhp
# Version required:	3.3.10
# Date created:		27 August 1999
# Whom:			papowell@astart.com
#
# $FreeBSD$
#

DISTNAME=	ifhp-3.3.10
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.astart.com/pub/LPRng/FILTERS/
EXTRACT_SUFX=	.tgz

MAINTAINER=	papowell@astart.com

MAKEFILE=	Makefile.bsd
HAS_CONFIGURE=	yes

MAN8=		ifhp.8 textps.8

post-install:
	${INSTALL} -d -g bin -o bin -m 0555 ${PREFIX}/share/doc/ifhp
.if !defined(NOPORTSDOCS)
	${CP} -r ${WRKSRC}/HOWTO/* ${PREFIX}/share/doc/ifhp;
.endif

.include <bsd.port.mk>
