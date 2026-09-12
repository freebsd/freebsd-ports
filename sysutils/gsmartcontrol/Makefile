PORTNAME=	gsmartcontrol
DISTVERSIONPREFIX=	v
DISTVERSION=	2.0.2
CATEGORIES=	sysutils

MAINTAINER=	mce@FreeBSD.org
COMMENT=	Graphical user interface for smartmontools
WWW=		https://gsmartcontrol.shaduri.dev/

LICENSE=	GPLv3 LGPL3+
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/LICENSE.txt
LICENSE_FILE_LGPL3+ =	${WRKSRC}/LICENSE.LGPL3.txt

BUILD_DEPENDS=	nlohmann-json>0:devel/nlohmann-json \
		tl-expected>0:devel/tl-expected
RUN_DEPENDS=	bash:shells/bash \
		pkexec:sysutils/polkit \
		smartctl:sysutils/smartmontools \
		xterm:x11/xterm

USES=		cmake compiler:c++20-lang gnome pkgconfig shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	ashaduri
USE_GNOME=	gtkmm30

SHEBANG_FILES=	data/gsmartcontrol-root.in.sh

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
