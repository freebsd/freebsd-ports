# New ports collection makefile for:	nfbtrans
# Date created:			30 Aug 1998
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nfbtrans
PORTVERSION=	7.55
CATEGORIES=	textproc
MASTER_SITES=	ftp://nfb.org/braille/nfbtrans/
DISTNAME=	nfbtr755
EXTRACT_SUFX=	.exe

MAINTAINER=	max@FreeBSD.org

RESTRICTED=	"Unclear copyright status"

USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-q -a -L -o
NO_WRKSUBDIR=		yes
ALL_TARGET=		freebsd
MAKEFILE=		makefile

do-install:
	${MKDIR} ${PREFIX}/lib/nfbtrans/tables
	${INSTALL_PROGRAM} ${WRKSRC}/nfbtrans ${PREFIX}/bin
.for f in braille.tab back.tab english.dic nfbtrans.cnf menu.cnf
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/lib/nfbtrans
.endfor
	@unzip -q -L -a -o ${WRKSRC}/tables.zip -d ${PREFIX}/lib/nfbtrans/tables
.if !defined(NOPORTDOCS)
	@${ECHO} '~0 ~-pw=80 ~-ls=99 ~-pl=56 ~-if=12 ~-fc=. ~o5 ~p- ~-ip=0 ~-oc=1' \
	  | ${CAT} - ${WRKSRC}/nfbtrans.fmt > ${WRKSRC}/nfbprint.fmt
	@${WRKSRC}/nfbtrans st=${WRKSRC}/stat.txt qm=1 ob=oc=15 \
	  ${WRKSRC}/nfbprint.fmt > ${WRKSRC}/nfbtrans.doc
	${MKDIR} ${PREFIX}/share/doc/nfbtrans
.for f in read.me nfbtrans.doc nfbtrans.fmt tvfreqs.fmt
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/nfbtrans
.endfor
.endif

.include <bsd.port.mk>
