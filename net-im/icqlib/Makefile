# New ports collection makefile for:    icqlib
# Date created:                         16 March 1999
# Whom:                                 Pavel Andreev
#
# $FreeBSD$
#

PORTNAME=	icqlib
PORTVERSION=	1.0.0
PORTREVISION=	2
CATEGORIES=	net-im
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A library required by kicq (not libicq)

USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure

.include <bsd.port.mk>
