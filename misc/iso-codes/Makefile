# New ports collection makefile for:   iso-codes
# Date created:			02 April 2005
# Whom:				Koop Mast <kwm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	iso-codes
DISTVERSION=	0.58
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL} \
		http://freebsd.powered.net/distfiles/
DISTNAME=	${PORTNAME}_${PORTVERSION}-1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lists of the country, language and currency iso names

BUILD_DEPENDS=	xmlproc_parse:${PORTSDIR}/textproc/py-xml

USE_PYTHON_BUILD=	yes
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal:19 autoconf:259 automake:19
AUTOMAKE_ARGS+=	--add-missing --foreign --copy
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:C/-.*$//}
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

.include <bsd.port.mk>
