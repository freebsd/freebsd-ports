# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cpu-x
PORTVERSION=	3.1.3
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Gathers information about CPU, motherboard, and more

LICENSE=	GPLv3

BUILD_DEPENDS=	nasm:devel/nasm
LIB_DEPENDS=	libcpuid.so:sysutils/libcpuid \
		libpci.so:devel/libpci \
		libstatgrab.so:devel/libstatgrab

USE_GITHUB=	yes
GH_ACCOUNT=	X0rg
GH_PROJECT=	${PORTNAME:tu}

USES=		cmake execinfo gettext-tools ncurses pkgconfig
USE_GNOME=	gtk30
INSTALLS_ICONS=	yes

PORTDOCS=	ChangeLog README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's, -Wno-unused-result,,' ${WRKSRC}/CMakeLists.txt

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
