# Created by: Patrick Li <pat@databits.net>
# $FreeBSD$

PORTNAME=	jags
PORTVERSION=	0.22.1
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Jags/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	JAGS - Just Another GTK+ Samba Client

RUN_DEPENDS=	smbclient:${PORTSDIR}/${SAMBA_PORT}

SAMBA_PORT?=	net/samba36

CONFLICTS=	jags-1.*

USE_GMAKE=	yes
USE_XORG=	xi xext x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
CFLAGS+=	-ffriend-injection
.endif

.include <bsd.port.post.mk>
