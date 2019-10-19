# Created by: James Bailie <jimmy@mammothcheese.ca>
# $FreeBSD$

PORTNAME=	utopia
PORTVERSION=	1.1
CATEGORIES=	print
MASTER_SITES=	https://BSDforge.com/projects/source/print/utopia/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Adobe Utopia typeface for Groff

MAKE_ARGS=	DEST=${STAGEDIR}${DATADIR}/devps \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		PREFIX=${PREFIX}

PLIST_FILES=	man/man7/utopia_font.7.gz
PORTDATA=	*

.include <bsd.port.mk>
