# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	IExtract
PORTVERSION=	0.9.30
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Extract meta-information from files

LIB_DEPENDS=	YGP.0:${PORTSDIR}/devel/libYGP

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USES=		pkgconfig gettext
CONFIGURE_ARGS=	--with-libintl-prefix=${LOCALBASE} --disable-rpath

NO_STAGE=	yes
.include <bsd.port.mk>
