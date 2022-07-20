PORTNAME=	tkdiff
DISTVERSION=	4-3
CATEGORIES=	textproc tk
MASTER_SITES=	SF  https://bsdforge.com/projects/source/textproc/tkdiff/:ikon
DISTFILES=	${DISTNAME}.zip tkicons.txz:ikon

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tk frontend for diff(1)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		cpe tar:txz tk:wrapper
NO_BUILD=	yes

DESKTOP_ENTRIES=	"Tkdiff" "Tk frontend for the diff command" \
			"tkdiff" \
			"tkdiff" "GNOME;GTK;Development;System;" \
			false

IKONS=	tkdiff-256.png tkdiff-128.png \
	tkdiff-64.png tkdiff.png

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${IKONS:S/tkdiff/${WRKSRC}\/tkdiff/g} ${STAGEDIR}${PREFIX}/share/pixmaps/

.include <bsd.port.mk>
