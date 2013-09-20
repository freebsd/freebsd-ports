# Created by: Pavel Andreev
# $FreeBSD$

PORTNAME=	icqlib
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library required by kicq (not libicq)

USE_AUTOTOOLS=	libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
