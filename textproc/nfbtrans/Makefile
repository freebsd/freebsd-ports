# New ports collection makefile for:	nfbtrans
# Date created:			30 Aug 1998
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	nfbtrans
PORTVERSION=	7.74
CATEGORIES=	textproc
MASTER_SITES=	http://www.nfb.org/braille/nfbtrans/
DISTNAME=	nfbtr${PORTVERSION:S/.//}

MAINTAINER=	max@FreeBSD.org
COMMENT=	ASCII text to Grade Two braille translator

RESTRICTED=	"Unclear copyright status"

USE_ZIP=		yes
EXTRACT_BEFORE_ARGS=	-q -a -L -o
NO_WRKSUBDIR=		yes
ALL_TARGET=		freebsd
MAKEFILE=		makefile

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		"Does not install on ia64 or amd64 (segfault during install)"
.endif

post-extract:
	@${UNZIP_CMD} -q -L -a -o ${WRKSRC}/tables.zip -d ${WRKDIR}/tables
	@${UNZIP_CMD} -q -L -a -o ${WRKSRC}/spanish.zip -d ${WRKDIR}/spanish

do-install:
	${MKDIR} ${PREFIX}/share/nfbtrans/tables
	${INSTALL_PROGRAM} ${WRKSRC}/nfbtrans ${PREFIX}/bin
.for f in braille.tab back.tab english.dic nfbtrans.cnf menu.cnf
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/nfbtrans
.endfor
	@${CP} -pR ${WRKDIR}/tables ${PREFIX}/share/nfbtrans
	@${CP} -pR ${WRKDIR}/spanish ${PREFIX}/share/nfbtrans
.if !defined(NOPORTDOCS)
	@${ECHO} '~0 ~-pw=80 ~-ls=99 ~-pl=56 ~-if=12 ~-fc=. ~o5 ~p- ~-ip=0 ~-oc=1' \
	  | ${CAT} - ${WRKSRC}/nfbtrans.fmt > ${WRKSRC}/nfbprint.fmt
	@${WRKSRC}/nfbtrans st=${WRKSRC}/stat.txt qm=1 ob=oc=15 \
	  ${WRKSRC}/nfbprint.fmt > ${WRKSRC}/nfbtrans.doc
	${MKDIR} ${PREFIX}/share/doc/nfbtrans
.for f in readme.txt nfbtrans.doc nfbtrans.fmt tvfreqs.fmt
	${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/share/doc/nfbtrans
.endfor
.endif

.include <bsd.port.post.mk>
