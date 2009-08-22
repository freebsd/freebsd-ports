# New ports collection makefile for:	jags
# Date created:				Thu Jul  5 17:13:11 EDT 2001
# Whom:					Patrick Li <pat@databits.net>
#
# $FreeBSD$
#

PORTNAME=	jags
PORTVERSION=	0.22.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}/Jags/${PORTNAME}-${PORTVERSION}

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	JAGS - Just Another GTK+ Samba Client

RUN_DEPENDS=	smbclient:${PORTSDIR}/net/samba3

NO_LATEST_LINK=	yes
USE_GMAKE=	yes
USE_XORG=	xi xext x11
USE_GNOME=	gtk12
GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
CFLAGS+=	-ffriend-injection
.endif

.include <bsd.port.post.mk>
