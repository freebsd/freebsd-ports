# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	zombiezapper
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	security
MASTER_SITES=	PACKETSTORM/distributed/zombie
DISTNAME=	zombie-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Send a terminate command to Trinoo/TFN/Stacheldracht DDoS agents

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet10

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet10-config

CPPFLAGS+=	$$(${LIBNET_CONFIG} --cflags --defines)
LDFLAGS+=	$$(${LIBNET_CONFIG} --libs)

PORTDOCS=	USAGE tekpaper.txt
PLIST_FILES=	bin/zz

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-build:
	cd ${WRKSRC} && \
		${CC} ${CFLAGS} ${CPPFLAGS} -o zz zz.c ${LDFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/zz ${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
