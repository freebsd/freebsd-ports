# New ports collection makefile for:   iso-codes
# Date created:			02 April 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iso-codes
PORTVERSION=	0.51
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL}
DISTNAME=	${PORTNAME}_${PORTVERSION}.orig

MAINTAINER=	rainer.alves@gmail.com
COMMENT=	Lists of the country, language and currency iso names

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_PYTHON_BUILD=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:19 autoconf:259 automake:19
AUTOMAKE_ARGS+=	--add-missing --foreign --copy
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

post-patch:
	@${REINPLACE_CMD} -e 's|!/usr/bin/python|!${LOCALBASE}/bin/python|g' \
		${WRKSRC}/iso2pot.py ${WRKSRC}/iso2tab.py \
		${WRKSRC}/iso_3166/iso3166tab.py ${WRKSRC}/iso_639/iso639tab.py

post-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_3166/iso_3166_2/iso_3166_2.tab \
		${PREFIX}/share/iso-codes/iso_3166_2.tab
	@${INSTALL_SCRIPT} ${WRKSRC}/iso_4217/iso_4217.tab \
		${PREFIX}/share/iso-codes/iso_4217.tab

.include <bsd.port.mk>
