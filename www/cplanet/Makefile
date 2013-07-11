# $FreeBSD$

PORTNAME=	cplanet
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://files.etoilebsd.net/cplanet/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	RSS Feed Aggregator that generate static html

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:${PORTSDIR}/www/clearsilver
LIB_DEPENDS=	expat:${PORTSDIR}/textproc/expat2 \
		curl:${PORTSDIR}/ftp/curl

LICENSE=	BSD

MAN1=		cplanet.1

OPTIONS_DEFINE=	EXAMPLES

.include <bsd.port.options.mk>
post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet-atom.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet-opml.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet-rss.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet.cs ${EXAMPLESDIR}
	${INSTALL} -o root -g wheel -m 644 ${WRKSRC}/samples/cplanet.hdf ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
