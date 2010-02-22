# New ports collection makefile for:	cplanet
# Date created:		2010-02-22
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cplanet
PORTVERSION=	0.3
CATEGORIES=	www textproc
MASTER_SITES=	http://baptux.free.fr/distfiles/

MAINTAINER=	baptiste.daroussin@gmail.com
COMMENT=	RSS Feed Aggregator that generate static html

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:${PORTSDIR}/www/clearsilver
LIB_DEPENDS=	mrss.19:${PORTSDIR}/textproc/libmrss

USE_BZIP2=	yes

USE_ICONV=	yes

MAN1=		cplanet.1

.include <bsd.port.pre.mk>
post-install:
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet-atom.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet-opml.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet-rss.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet.hdf ${EXAMPLESDIR}
.endif

.include <bsd.port.post.mk>
