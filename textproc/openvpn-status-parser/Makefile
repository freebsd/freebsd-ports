PORTNAME=	openvpn-status-parser
PORTVERSION=	0.1.0
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	textproc

MAINTAINER=	zeus@gnu.org.ua
COMMENT=	OpenVPN status file parser and exporter
WWW=		https://github.com/z-eos/openvpn-status-parser

LICENSE=	GPLv3

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	z-eos

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
