# Created by: mahlon
# $FreeBSD$

PORTNAME=	volta
PORTVERSION=	0.3.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	https://bitbucket.org/mahlon/volta/downloads/ \
		http://dl.dropbox.com/u/7234177/Releases/

MAINTAINER=	mahlon@martini.nu
COMMENT=	High performance, low resource URI rewriter for Squid

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcdb.so:databases/tinycdb

USES=		gmake pkgconfig lua tar:tgz
ALL_TARGET=	${PORTNAME}

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

PLIST_FILES=	bin/volta
PORTDOCS=	README INSTALL LICENSE ChangeLog
SUB_FILES=	pkg-message

do-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/volta ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
