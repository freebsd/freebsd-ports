# New ports collection makefile for:	rus-ispell
# Date created:				29.01.2001
# Whom:					ache
#
# $FreeBSD$
#

PORTNAME=	rus-ispell
PORTVERSION=	0.99f7
PORTREVISION=	1
CATEGORIES=	russian textproc
MASTER_SITES=	ftp://scon155.phys.msu.su/pub/russian/ispell/

MAINTAINER=	ache@FreeBSD.org
COMMENT=	New Russian dictionaries for ispell

BUILD_DEPENDS=	ispell:${PORTSDIR}/textproc/ispell

USE_GMAKE=	yes
.if defined(RUS_ISPELL_WITH_YO_ONLY)
MAKE_ARGS+=	YO=1
.endif
.if defined(RUS_ISPELL_LOCAL_DICT)
MAKE_ARGS+=	LOCAL_DICT=${RUS_ISPELL_LOCAL_DICT}
.endif

ALL_TARGET=	koi

NO_WRKSUBDIR=	yes

do-install:
	cd ${WRKSRC} && \
		${INSTALL_DATA} russian.hash russian.dict russian.aff \
		${PREFIX}/share/ispell
	${INSTALL_SCRIPT} ${FILESDIR}/ispell-ru.sh ${PREFIX}/bin/ispell-ru

.include <bsd.port.mk>
