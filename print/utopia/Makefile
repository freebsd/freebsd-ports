PORTNAME=	utopia
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	print
MASTER_SITES=	https://BSDforge.com/projects/source/print/utopia/

MAINTAINER=	portmaster@BSDforge.com
COMMENT=	Adobe Utopia typeface for Groff
WWW=		http://www.mammothcheese.ca/munger.html

MAKE_ARGS=	DEST=${STAGEDIR}${DATADIR}/devps \
		INSTALL_DATA="${INSTALL_DATA}" \
		INSTALL_MAN="${INSTALL_MAN}" \
		MANDIR="${STAGEDIR}${PREFIX}/share/man/man7/" \
		PREFIX=${PREFIX}

PLIST_FILES=	share/man/man7/utopia_font.7.gz
PORTDATA=	*

.include <bsd.port.mk>
