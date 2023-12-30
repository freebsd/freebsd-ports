PORTNAME=	gartoon
PORTVERSION=	1.3
MASTER_SITES=	LOCAL/fluffy \
		http://ns.ael.ru/ports/distfiles/KDE/
PKGNAMESUFFIX=	-blue-svg
DISTNAME=	ICONS-Gartoon.Blue-SVG-v${PORTVERSION}

COMMENT=	KDE Gartoon Blue SVG iconset
WWW=		http://www.kde-look.org/content/show.php?content=17362

DEPRCATED=	Upstream WWW returns NOT FOUND
EXPIRATION_DATE=	2024-01-25

USES=		tar:bzip2

WRKSRC=		${WRKDIR}/Gartoon.Blue
PORT_SHAREDIR?=	"${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
