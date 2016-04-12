# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	picsnvideos
PORTVERSION=	0.2
PORTREVISION=	4
CATEGORIES=	palm comms graphics
MASTER_SITES=	SF/${PORTNAME}/source%20code/${PORTVERSION}
PKGNAMEPREFIX=	jpilot-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JPilot plugin to download photos and videos

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	jpilot:palm/jpilot
BUILD_DEPENDS=	jpilot:palm/jpilot
LIB_DEPENDS=	libgdbm.so:databases/gdbm

GNU_CONFIGURE=	yes
LIBS+=		-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip
USES=		libtool

PORTDOCS=	README AUTHORS
PLIST_FILES=	lib/jpilot/plugins/libpicsnvideos.so

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		-e '/LIBS=/s/$$libs/$$LIBS/' \
		${WRKSRC}/configure

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
