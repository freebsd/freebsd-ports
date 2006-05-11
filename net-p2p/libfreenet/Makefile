# ex:ts=8
# New ports collection makefile for:	libfreenet
# Date created:			Mar 31, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libfreenet
PORTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	net-p2p
MASTER_SITES=	http://thalassocracy.org/libfreenet/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Freenet library written in C

USE_OPENSSL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/libfreenet
INSTALLS_SHLIB=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-g -Wall|\@CFLAGS\@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
