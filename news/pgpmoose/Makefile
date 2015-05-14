# $FreeBSD$

PORTNAME=	pgpmoose
PORTVERSION=	1.19
PORTREVISION=	1
CATEGORIES=	news security
# Distribution broken
# MASTER_SITES=	http://people.qualcomm.com/ggr/
MASTER_SITES=	LOCAL/dinoex
DISTNAME=	PGPMoose
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	PGP Moose - signatures for moderated newsgroups

NO_WRKSUBDIR=	yes
USES=		shebangfix
SHEBANG_FILES=	pmcancel pmdaemon
BIN1=		pmapp pmcanon pmcheck pmnewsgroups \
		pmdaemon pmcancel
LMAN1=		pmapp.1 pmcanon.1 pmcheck.1 pmnewsgroups.1 \
		pmdaemon.1 pmcancel.1

NEWSCTL?=	${PREFIX}/news/lib

_SHEBANG_REINPLACE_ARGS+=	-e "1s|^\#![[:space:]]*/bin/perl|\#!${perl_CMD}|"

post-patch:
	${REINPLACE_CMD} -e "s=/usr/local/news=${NEWSCTL}=" \
		${WRKSRC}/pmapp

do-install:
.for i in ${BIN1}
	${INSTALL_SCRIPT} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin/
.endfor
.for i in ${LMAN1}
	${INSTALL_MAN} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
