# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cezanne
PORTVERSION=	0.3b
MASTER_SITES=	http://homepage.ntlworld.com/christopher.townson/
DISTNAME=	Cezanne_packaged

COMMENT=	KDE Cezanne iconset

USES=		tar:bzip2

BROKEN=		does not fetch (connect timeout)

WRKSRC=		${WRKDIR}/Cezanne
PORT_SHAREDIR?=	"${PORTNAME}-${PORTVERSION}"

PLIST_FILE_PATTERN_EXTRA=	-v "buildset"

.include "${.CURDIR}/../kde-icons-noia/Makefile.icons"
