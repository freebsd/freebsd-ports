# New ports collection makefile for:   iso-codes
# Date created:			02 April 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iso-codes
PORTVERSION=	3.10.1
CATEGORIES=	misc
MASTER_SITES=	ftp://pkg-isocodes.alioth.debian.org/pub/pkg-isocodes/

MAINTAINER=	kwm@FreeBSD.org
COMMENT=	Lists of the country, language and currency iso names

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget
USE_PYTHON_BUILD=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
