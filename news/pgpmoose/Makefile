# New ports collection makefile for:	pgpmoose
# Version required:	1
# Date created:		28 Nov 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $Id: Makefile,v 1.1.1.1 1998/08/09 00:34:33 steve Exp $

DISTNAME=	PGPMoose
PKGNAME=	pgpmoose-1
CATEGORIES=	news security
MASTER_SITES=	http://people.qualcomm.com/ggr/ \
		ftp://ftp.dinoex.sub.de/pub/approved/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dirk.meyer@dinoex.sub.org

MAN1=		pmapp.1 pmcanon.1 pmcheck.1 pmnewsgroups.1 \
		pmdaemon.1 pmcancel.1
BIN1=		pmapp pmcanon pmcheck pmnewsgroups \
		pmdaemon pmcancel

WRKSRC=		${WRKDIR}
STRIP=

do-install:
.for i in ${BIN1}
	@${INSTALL_PROGRAM} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
