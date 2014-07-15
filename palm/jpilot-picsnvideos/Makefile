# Created by: Sascha Klauder <sklauder@trimind.de>
# $FreeBSD$

PORTNAME=	picsnvideos
PORTVERSION=	0.2
PORTREVISION=	3
CATEGORIES=	palm comms graphics
MASTER_SITES=	SF/${PORTNAME}/source%20code/${PORTVERSION}
PKGNAMEPREFIX=	jpilot-

MAINTAINER=	sklauder@trimind.de
COMMENT=	JPilot plugin to download photos and videos

LICENSE=	GPLv2

RUN_DEPENDS=	jpilot:${PORTSDIR}/palm/jpilot
BUILD_DEPENDS=	jpilot:${PORTSDIR}/palm/jpilot
LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm

GNU_CONFIGURE=	yes

LDFLAGS+=	-L${PREFIX}/lib
PORTDOCS=	README AUTHORS
PLIST_FILES=	lib/jpilot/plugins/libpicsnvideos.la	\
		lib/jpilot/plugins/libpicsnvideos.so

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/configure

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
. for FILE in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${FILE} ${STAGEDIR}${DOCSDIR}
. endfor
.endif

.include <bsd.port.mk>
