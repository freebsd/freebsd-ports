PORTNAME=	tkdiff
DISTVERSION=	6-0
CATEGORIES=	textproc tk
MASTER_SITES=	SF

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Tk frontend for diff(1)
WWW=		https://sourceforge.net/projects/tkdiff/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		tk:wrapper zip

DESKTOP_ENTRIES=	"Tkdiff" "Tk frontend for the diff command" \
			"tkdiff" \
			"tkdiff" "GNOME;GTK;Development;System;" \
			false
NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/tkdiff

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
