# $FreeBSD$

PORTNAME=	cplanet
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	http://files.etoilebsd.net/cplanet/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	RSS Feed Aggregator that generate static html

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:${PORTSDIR}/www/clearsilver
LIB_DEPENDS=	libexpat.so:${PORTSDIR}/textproc/expat2 \
		libcurl.so:${PORTSDIR}/ftp/curl

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}/${MANPREFIX}/man/man1

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cplanet-atom.cs \
		${WRKSRC}/samples/cplanet-opml.cs \
		${WRKSRC}/samples/cplanet-rss.cs \
		${WRKSRC}/samples/cplanet.cs \
		${WRKSRC}/samples/cplanet.hdf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
