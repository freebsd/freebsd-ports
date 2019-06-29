# Created by: Sergey Matveev <stargrave@stargrave.org>
# $FreeBSD$

PORTNAME=	govpn
DISTVERSION=	7.5
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.govpn.info/download/

MAINTAINER=	stargrave@stargrave.org
COMMENT=	Simple secure, DPI-resistant VPN daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		go:no_targets tar:xz
MAKEFILE=	BSDmakefile

PORTDOCS=	AUTHORS INSTALL NEWS NEWS.RU README README.RU THANKS
INFO=		govpn
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/govpn-server bin/govpn-client bin/govpn-verifier \
		share/govpn/newclient.sh

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
