# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	telbook
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple telephone book

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2

USES=		shebangfix tar:bzip2
SHEBANG_FILES=	telbook
NO_BUILD=	yes
NO_ARCH=	yes

PORTDOCS=	README
PLIST_FILES=	bin/telbook

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/telbook ${STAGEDIR}${PREFIX}/bin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
