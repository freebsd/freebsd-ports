# Created by: jfitz@FreeBSD.org
# $FreeBSD$

PORTNAME=	pilot_makedoc
PORTVERSION=	0.7a
PORTREVISION=	1
CATEGORIES=	palm textproc
MASTER_SITES=	ftp://ftp.forth.org/pub/PalmOS/ \
		ftp://ftp.cs.tu-berlin.de/pub/palmtops/pilot/
DISTNAME=	makedoc7
EXTRACT_SUFX=	.cpp

MAINTAINER=	simond@irrelevant.org
COMMENT=	Converts text into the Doc format used by PalmPilots

DEPRECATED=	obsolete technology
EXPIRATION_DATE=	2019-09-20

NO_WRKSUBDIR=	yes
PLIST_FILES=	bin/pilot_makedoc
ALL_TARGET=	pilot_makedoc

do-extract:
	@${MKDIR} ${WRKSRC}
	@${CP} ${DISTDIR}/${DISTFILES} ${WRKSRC}
	@${CP} ${FILESDIR}/Makefile ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pilot_makedoc ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
