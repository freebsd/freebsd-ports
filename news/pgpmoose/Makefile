# $FreeBSD$

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

NO_WRKSUBDIR=	yes
BIN1=		pmapp pmcanon pmcheck pmnewsgroups \
		pmdaemon pmcancel
MAN1=		pmapp.1 pmcanon.1 pmcheck.1 pmnewsgroups.1 \
		pmdaemon.1 pmcancel.1

NEWSCTL?=	${PREFIX}/news/lib

post-patch:
	${REINPLACE_CMD} -e "s=/usr/local/news=${NEWSCTL}=" \
		${WRKSRC}/pmapp

do-install:
.for i in ${BIN1}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for i in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${MANPREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
