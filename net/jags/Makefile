# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	jags
PORTVERSION=	0.22.1
PORTREVISION=	7
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Jags/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JAGS - Just Another GTK+ Samba Client

RUN_DEPENDS=	smbclient:${SAMBA_PORT}

SAMBA_PORT?=	net/samba36

CONFLICTS=	jags-1.*

USES=		gmake
USE_XORG=	xi xext x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
