# New ports collection makefile for:	KDE Nut Client
# Date created:				Mon Apr 28 05:30:59 UTC 2003
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	knutclient
PORTVERSION=	0.6.0
PORTREVISION=	1
CATEGORIES=	sysutils kde
MASTER_SITES=	ftp://ftp.buzuluk.cz/pub/alo/knutclient/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A visual client for UPS system NUT

USE_KDELIBS_VER=3
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-mt \
		--program-transform-name=''

post-patch:
	@${REINPLACE_CMD} -E \
		-e 's|-O2||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
