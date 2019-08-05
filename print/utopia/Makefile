# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	utopia
PORTVERSION=	1.1
CATEGORIES=	print
MASTER_SITES=	http://www.mammothcheese.ca/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Adobe Utopia typeface for Groff

BROKEN=		unfetchable

MAKE_ARGS=	DEST=${STAGEDIR}${DATADIR}/devps \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		PREFIX=${PREFIX}

PLIST_FILES=	man/man7/utopia_font.7.gz
PORTDATA=	*

.include <bsd.port.mk>
