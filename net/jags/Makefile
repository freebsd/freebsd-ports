# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	jags
PORTVERSION=	0.22.1
PORTREVISION=	11
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Jags/${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JAGS - Just Another GTK+ Samba Client

DEPRECATED=	Uses obsolete glib12
EXPIRATION_DATE=	2018-12-20

CONFLICTS=	jags-1.*

USES=		gmake samba:run # smbclient
USE_XORG=	xi xext x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
