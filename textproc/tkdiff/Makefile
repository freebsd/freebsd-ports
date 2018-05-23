# Created by: Kevin Lo <kevlo@FreeBSD.org>
# $FreeBSD$

PORTNAME=	tkdiff
PORTVERSION=	4.2
PORTREVISION=	2
CATEGORIES=	textproc tk
MASTER_SITES=	SF

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Tk frontend for diff(1)

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	base64>0:converters/base64

WRKSRC=		${WRKDIR}/${PORTNAME}-unix

USES=		tk:wrapper
NO_BUILD=	yes

DESKTOP_ENTRIES=	"Tkdiff" "Tk frontend for the diff command" \
			"tkdiff" \
			"tkdiff" "GNOME;GTK;Development;System;" \
			false

UNPACK=	base64 -d

PLIST_FILES=	bin/tkdiff share/pixmaps/tkdiff.png share/pixmaps/tkdiff-256.png \
		share/pixmaps/tkdiff-128.png share/pixmaps/tkdiff-64.png

post-patch:
	${FIND} ${WRKSRC} -type f | ${XARGS} \
		${REINPLACE_CMD} -e '/^exec wish/s|wish|${WISH}|g' -e '/^exec tclsh/s|tclsh|${TCLSH}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tkdiff ${STAGEDIR}${PREFIX}/bin
	${UNPACK} ${FILESDIR}/icon256.base64 > ${STAGEDIR}${PREFIX}/share/pixmaps/tkdiff-256.png
	${UNPACK} ${FILESDIR}/icon128.base64 > ${STAGEDIR}${PREFIX}/share/pixmaps/tkdiff-128.png
	${UNPACK} ${FILESDIR}/icon64.base64 > ${STAGEDIR}${PREFIX}/share/pixmaps/tkdiff-64.png
	${UNPACK} ${FILESDIR}/icon32.base64 > ${STAGEDIR}${PREFIX}/share/pixmaps/tkdiff.png

.include <bsd.port.mk>
