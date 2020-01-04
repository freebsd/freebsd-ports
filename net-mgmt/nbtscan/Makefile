# Created by: Kris Kennaway <kris@FreeBSD.org>
# $FreeBSD$

PORTNAME=	nbtscan
PORTVERSION=	1.6
CATEGORIES=	net-mgmt

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	NetBIOS name network scanner

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/nbtscan \
		man/man1/nbtscan.1.gz
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

GH_ACCOUNT=	resurrecting-open-source-projects
USE_GITHUB=	yes

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
