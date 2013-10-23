# Created by: Emanuel Haupt <ehaupt@critical.ch>
# $FreeBSD$

PORTNAME=	tmpreaper
PORTVERSION=	1.6.13
CATEGORIES=	sysutils
MASTER_SITES=	CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Cleans up files in directories based on their age

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
USES=		gmake

PLIST_FILES=	sbin/tmpreaper man/man8/tmpreaper.8.gz
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
