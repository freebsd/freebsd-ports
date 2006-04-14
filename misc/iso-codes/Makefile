# New ports collection makefile for:   iso-codes
# Date created:			02 April 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iso-codes
PORTVERSION=	0.48
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	kwm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lists of the country, language and currency iso names

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_BZIP2=	yes
USE_PYTHON_BUILD=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|!/usr/bin/python|!${LOCALBASE}/bin/python|g' \
		${WRKSRC}/iso2pot.py ${WRKSRC}/iso2tab.py \
		${WRKSRC}/iso_3166/iso3166tab.py ${WRKSRC}/iso_639/iso639tab.py
	@${REINPLACE_CMD} -e 's|(datadir)/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_3166/iso_3166_2/iso_3166_2.tab \
		${PREFIX}/share/iso-codes/iso_3166_2.tab
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_4217/iso_4217.tab \
		${PREFIX}/share/iso-codes/iso_4217.tab

.include <bsd.port.mk>
