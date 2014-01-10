# Created by: mahlon
# $FreeBSD$

PORTNAME=	volta
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://dl.dropbox.com/u/7234177/Releases/ \
		http://projects.martini.nu/volta/chrome/site/
EXTRACT_SUFX=	.tgz

MAINTAINER=	mahlon@martini.nu
COMMENT=	High performance, low resource URI rewriter for Squid

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libcdb.so:${PORTSDIR}/databases/tinycdb

USES=		gmake pkgconfig lua
ALL_TARGET=	${PORTNAME}
NO_INSTALL=	yes

CFLAGS+=	-I${PREFIX}/include
LDFLAGS+=	-L${PREFIX}/lib

PLIST_FILES=	bin/volta
PORTDOCS=	README INSTALL LICENSE ChangeLog
SUB_FILES=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e "s/5.1/${LUA_VER}/g" ${WRKSRC}/Makefile

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/volta ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
