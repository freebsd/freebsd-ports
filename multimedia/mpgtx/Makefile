# ex:ts=8
# New ports collection makefile for:	mpgtx
# Date created:			May 15, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mpgtx
PORTVERSION=	0.7b
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION}-1-src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ijliao@FreeBSD.org

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	shared
MAKE_ENV=	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
		INSTALL_MAN="${INSTALL_MAN}"

MAN1=	mpgtx.1 mp3tag.1
MLINKS=	mpgtx.1 mpgdemux.1 \
	mpgtx.1 mpgjoin.1 \
	mpgtx.1 mpgsplit.1 \
	mpgtx.1 mpgcat.1 \
	mpgtx.1 mpginfo.1

.include <bsd.port.mk>
