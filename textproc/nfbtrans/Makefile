# New ports collection makefile for:	nfbtrans
# Version required:		7.53
# Date created:			30 Aug 1998
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	nfbtr753
PKGNAME=	nfbtrans-7.53
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.netcom.com/pub/in/inge/
EXTRACT_SUFX=	.zip

MAINTAINER=	max@FreeBSD.org

RESTRICTED=	"Unclear copyright status"

USE_ZIP=	yes
EXTRACT_BEFORE_ARGS=	-q -a -L -o
NO_WRKSUBDIR=	yes
ALL_TARGET=	freebsd
MAKEFILE=	makefile

do-install:
	${MKDIR} ${PREFIX}/lib/nfbtrans/tables
	${INSTALL_PROGRAM} ${WRKSRC}/nfbtrans ${PREFIX}/bin
.for f in braille.tab back.tab english.dic nfbtrans.cnf
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/lib/nfbtrans
.endfor
	@unzip -q -L -a -o ${WRKSRC}/tables.zip -d ${PREFIX}/lib/nfbtrans/tables
.if !defined(NOPORTDOCS)
	@${ECHO} '~0 ~-pw=80 ~-ls=99 ~-pl=56 ~-if=12 ~-fc=. ~o5 ~p- ~-ip=0 ~-oc=1' \
	  | ${CAT} - ${WRKSRC}/nfbtrans.fmt > ${WRKSRC}/nfbprint.fmt
	@${WRKSRC}/nfbtrans st=${WRKSRC}/stat.txt qm=1 ob=oc=15 \
	  ${WRKSRC}/nfbprint.fmt > ${WRKSRC}/nfbtrans.doc
	${MKDIR} ${PREFIX}/share/doc/nfbtrans
	${INSTALL_DATA} ${WRKSRC}/nfbtrans.doc ${PREFIX}/share/doc/nfbtrans
	${INSTALL_DATA} ${WRKSRC}/nfbtrans.fmt ${PREFIX}/share/doc/nfbtrans
.endif

.include <bsd.port.mk>
