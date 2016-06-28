# Created by: kiesel@schlund.de
# $FreeBSD$

PORTNAME=	lxsplit
PORTVERSION=	0.2.4
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple program to split or join files

LICENSE=	GPLv2

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	ChangeLog README
OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
