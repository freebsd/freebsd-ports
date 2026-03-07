PORTNAME=	whowatch
DISTVERSION=	1.8.6.2
CATEGORIES=	sysutils

MAINTAINER=	jishanalam9128@gmail.com
COMMENT=	Displays information in real time about users currently logged on
WWW=		https://github.com/Zedai00/whowatch/ \
		https://github.com/mtsuszycki/whowatch/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf ncurses
USE_GITHUB=	yes
GH_ACCOUNT=	Zedai00
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/whowatch \
		share/applications/whowatch.desktop \
		share/man/man1/whowatch.1.gz

.include <bsd.port.mk>
