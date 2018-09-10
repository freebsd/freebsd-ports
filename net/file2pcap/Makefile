# Created by: Nobutaka Mantani <nobutaka@FreeBSD.org>
# $FreeBSD$

PORTNAME=	file2pcap
PORTVERSION=	1.25
CATEGORIES=	net

MAINTAINER=	nobutaka@FreeBSD.org
COMMENT=	Tool to make packet captures containing the content of specified file

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

GH_ACCOUNT=	Cisco-Talos
GH_PROJECT=	file2pcap

USE_GITHUB=	yes

ALL_TARGET=	file2pcap

PLIST_FILES=	bin/file2pcap
PORTDOCS=	Changelog README.md TODO

OPTIONS_DEFINE=	DOCS

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/file2pcap ${STAGEDIR}/${PREFIX}/bin
		${MKDIR} ${STAGEDIR}/${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/Changelog ${STAGEDIR}/${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}/${DOCSDIR}
		${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}/${DOCSDIR}

.include <bsd.port.mk>
