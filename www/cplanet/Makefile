# $FreeBSD$

PORTNAME=	cplanet
PORTVERSION=	0.9
PORTREVISION=	2
CATEGORIES=	www textproc
MASTER_SITES=	http://files.etoilebsd.net/cplanet/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	RSS Feed Aggregator that generate static html

BUILD_DEPENDS=	${LOCALBASE}/lib/libneo_cs.a:www/clearsilver
LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libcurl.so:ftp/curl

LICENSE=	BSD2CLAUSE

OPTIONS_DEFINE=	EXAMPLES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}/${MANPREFIX}/man/man1

post-install-EXAMPLES-on:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/samples/cplanet-atom.cs \
		${WRKSRC}/samples/cplanet-opml.cs \
		${WRKSRC}/samples/cplanet-rss.cs \
		${WRKSRC}/samples/cplanet.cs \
		${WRKSRC}/samples/cplanet.hdf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
