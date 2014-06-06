# Created by: Cheng-Lung Sung <clsung@dragon2.net>
# $FreeBSD$

PORTNAME=	snowlog
PORTVERSION=	1.1.1
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://kiza.kcore.de/software/snowlog/download/

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	Webserver access log browser/analyzer

LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre

DOCS=		INSTALLATION doc/README doc/filters.example
SHAREDOCS=	referers.regexp useragents.regexp

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC}/share && ${INSTALL_DATA} ${SHAREDOCS} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.post.mk>
