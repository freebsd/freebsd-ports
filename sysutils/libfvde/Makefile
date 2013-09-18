# Created by: Kubilay Kocak <koobs@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libfvde
PORTVERSION=	20130305
CATEGORIES=	sysutils
MASTER_SITES=	https://googledrive.com/host/0B3fBvzttpiiSLUVJYl9XRWhKSjg/
DISTFILES=	${PORTNAME}-experimental-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	koobs@FreeBSD.org
COMMENT=	Library and tools for reading FileVault (FVDE) encrypted volumes

LICENSE=	LGPL3

USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_GNOME=	libxml2 gnomehack
USE_LDCONFIG=	yes

MAN1=	fvdeinfo.1 fvdemount.1
MAN3=	libfvde.3

.include <bsd.port.mk>
