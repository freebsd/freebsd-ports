# Created by: kiesel@schlund.de
# $FreeBSD$

PORTNAME=	lxsplit
PORTVERSION=	0.2.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	yzlin@FreeBSD.org
COMMENT=	Simple program to split or join files

LICENSE=	GPLv2

PLIST_FILES=	bin/lxsplit
PORTDOCS=	COPYING ChangeLog README

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/lxsplit ${PREFIX}/bin/
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif

.include <bsd.port.mk>
