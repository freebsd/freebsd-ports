# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	netsed
PORTVERSION=	1.3
CATEGORIES=	net security
MASTER_SITES=	http://silicone.homelinux.org/release/netsed/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Alters the contents of network packets in real time

USES=		gmake
MAKE_ARGS=	CFLAGS="${CFLAGS}"

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
