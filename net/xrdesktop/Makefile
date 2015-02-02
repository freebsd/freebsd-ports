# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	xrdesktop
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	#

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK frontend to rdesktop

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop \
		p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk

CONFLICTS=      xrdesktop2-[1-9]*

DEPRECATED=	Unmaintained upstream - please use net/xrdesktop2 instead
EXPIRATION_DATE=	2015-02-28

NO_BUILD=	yes
USES=		perl5 shebangfix
SHEBANG_FILES=	xrdesktop

PLIST_FILES=	bin/xrdesktop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xrdesktop ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
