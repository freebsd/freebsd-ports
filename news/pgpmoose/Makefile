# New ports collection makefile for:	pgpmoose
# Date created:		28 Nov 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pgpmoose
PORTVERSION=	1.19
CATEGORIES=	news security
MASTER_SITES=	http://people.qualcomm.com/ggr/ \
		ftp://ftp.dinoex.de/pub/FreeBSD/distfiles/
DISTNAME=	PGPMoose
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dirk.meyer@dinoex.sub.org

MAN1=		pmapp.1 pmcanon.1 pmcheck.1 pmnewsgroups.1 \
		pmdaemon.1 pmcancel.1
BIN1=		pmapp pmcanon pmcheck pmnewsgroups \
		pmdaemon pmcancel

NO_WRKSUBDIR=	yes

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
