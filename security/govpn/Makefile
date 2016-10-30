# Created by: Sergey Matveev <stargrave@stargrave.org>
# $FreeBSD$

PORTNAME=	govpn
PORTVERSION=	7.0
CATEGORIES=	security
MASTER_SITES=	http://www.govpn.info/download/ \
		http://sourceforge.net/projects/govpn/files/

MAINTAINER=	stargrave@stargrave.org
COMMENT=	Simple secure, DPI-resistant VPN daemon

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	go:lang/go

USES=		tar:xz
MAKEFILE=	BSDmakefile

PORTDOCS=	AUTHORS INSTALL NEWS README THANKS README.RU
INFO=		govpn
INSTALL_TARGET=	install-strip

PLIST_FILES=	bin/govpn-server bin/govpn-client bin/govpn-verifier \
		share/govpn/newclient.sh

.include <bsd.port.mk>
