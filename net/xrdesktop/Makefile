# Created by: Andrej Zverev <az@inec.ru>
# $FreeBSD$

PORTNAME=	xrdesktop
PORTVERSION=	1.2
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://luggage.linux0wnsyou.com/xrdesktop/

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	GTK frontend to rdesktop

RUN_DEPENDS=	rdesktop:${PORTSDIR}/net/rdesktop \
		p5-Gtk>=0:${PORTSDIR}/x11-toolkits/p5-Gtk

NO_BUILD=	yes
USES=		perl5

PLIST_FILES=	bin/xrdesktop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/xrdesktop ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
