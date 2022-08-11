PORTNAME=	gartoon
PORTVERSION=	1.3
MASTER_SITES=	LOCAL/fluffy \
		http://ns.ael.ru/ports/distfiles/KDE/
PKGNAMESUFFIX=	-svg
DISTNAME=	ICONS-Gartoon-SVG-v${PORTVERSION}

COMMENT=	KDE Gartoon SVG iconset

USES=		tar:bzip2

WRKSRC=		${WRKDIR}/Gartoon
PORT_SHAREDIR?=	"${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}"

PLIST_DIR_PATTERN_EXTRA=	-v "extra/work"
PLIST_FILE_PATTERN_EXTRA=	-v "extra/work"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
