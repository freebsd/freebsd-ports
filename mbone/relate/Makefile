# New ports collection makefile for:	relate
# Date created:		6 June 2001
# Whom:			Takeshi MUTOH <mutoh@info.nara-k.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	relate
PORTVERSION=	2.1
CATEGORIES=	mbone
MASTER_SITES=	http://www-mice.cs.ucl.ac.uk/multimedia/software/relate-ui/${PORTVERSION}/

MAINTAINER=	tmutoh@mx10.freecom.ne.jp
COMMENT=	Mbone integrated interface, audio, video, editor, and whiteboard

LIB_DEPENDS=	tk82:${PORTSDIR}/x11-toolkits/tk82
RUN_DEPENDS=	rat30:${PORTSDIR}/mbone/rat30 \
		wbd:${PORTSDIR}/mbone/wbd \
		nte:${PORTSDIR}/mbone/nte \
		vic:${PORTSDIR}/mbone/vic

PLIST_FILES=	bin/relate
WRKSRC=		${WRKDIR}/relate

.include <bsd.port.mk>
