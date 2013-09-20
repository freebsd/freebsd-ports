# Created by: Kirill Ponomarew <ponomarew@oberon.net>
# $FreeBSD$

PORTNAME=	telbook
PORTVERSION=	0.4
PORTREVISION=	6
CATEGORIES=	misc
MASTER_SITES=	http://home.arcor.de/kaffeetisch/downloads/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple telephone book

RUN_DEPENDS=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2

NO_BUILD=	yes
USE_BZIP2=	yes

PORTDOCS=	README
PLIST_FILES=	bin/telbook

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/telbook ${PREFIX}/bin
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
