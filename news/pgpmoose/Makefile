# New ports collection makefile for:	pgpmoose
# Date created:		28 Nov 1997
# Whom:			dirk.meyer@dinoex.sub.org
#
# $FreeBSD$
#

PORTNAME=	pgpmoose
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	news security
# Distribution broken
# MASTER_SITES=	http://people.qualcomm.com/ggr/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dinoex
DISTNAME=	PGPMoose
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PGP Moose - signatures for moderated newsgroups

MAN1=		pmapp.1 pmcanon.1 pmcheck.1 pmnewsgroups.1 \
		pmdaemon.1 pmcancel.1
BIN1=		pmapp pmcanon pmcheck pmnewsgroups \
		pmdaemon pmcancel

NO_WRKSUBDIR=	yes
NEWSCTL?=	${PREFIX}/news/lib

post-patch:
	${REINPLACE_CMD} -e "s=/usr/local/news=${NEWSCTL}=" \
		${WRKSRC}/pmapp

do-install:
.for i in ${BIN1}
	@${INSTALL_SCRIPT} ${WRKSRC}/${i} ${PREFIX}/bin
.endfor
.for i in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${i} ${PREFIX}/man/man1
.endfor

.include <bsd.port.mk>
