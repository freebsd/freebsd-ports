# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	cryptcat
PORTVERSION=	1.2.1
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unix-1.2/${PORTNAME}-unix-${PORTVERSION}
DISTNAME=	${PORTNAME}-unix-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Standard netcat enhanced with twofish encryption

USES=		tar
WRKSRC=		${WRKDIR}/unix
ALL_TARGET=	freebsd

PLIST_FILES=	bin/cryptcat
PORTDOCS=	README.cryptcat

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cryptcat ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
