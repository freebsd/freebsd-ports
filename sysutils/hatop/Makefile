PORTNAME=	hatop
PORTVERSION=	0.8.1
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	sysutils net

MAINTAINER=	mikeg@bsd-box.net
COMMENT=	Interactive real-time monitoring tool for the HAProxy unix socket
WWW=		https://github.com/jhunt/hatop

LICENSE=	GPLv3+

RUN_DEPENDS=	${LOCALBASE}/sbin/haproxy:net/haproxy

USES=		python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	jhunt

SHEBANG_FILES=	bin/hatop
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/hatop share/man/man1/hatop.1.gz
PORTDOCS=	HACKING KEYBINDS README.rst

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/bin/hatop ${STAGEDIR}${PREFIX}/bin/hatop
	${INSTALL_MAN} ${WRKSRC}/man/hatop.1 ${STAGEDIR}${PREFIX}/share/man/man1

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${PORTDOCS}" ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
