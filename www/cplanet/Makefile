# New ports collection makefile for:	cplanet
# Date created:		2010-02-22
# Whom:			Bapt <baptiste.daroussin@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	cplanet
PORTVERSION=	0.5
CATEGORIES=	www textproc
MASTER_SITES=	http://files.etoilebsd.net/cplanet/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	RSS Feed Aggregator that generate static html

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:${PORTSDIR}/www/clearsilver
LIB_DEPENDS=	expat.6:${PORTSDIR}/textproc/expat2 \
		curl.6:${PORTSDIR}/ftp/curl

LICENSE=	BSD

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
