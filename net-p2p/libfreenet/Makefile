# ex:ts=8
# New ports collection makefile for:	libfreenet
# Date created:			Mar 31, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libfreenet
PORTVERSION=	0.3.0
CATEGORIES=	net
MASTER_SITES=	http://thalassocracy.org/libfreenet/

MAINTAINER=	ijliao@FreeBSD.org

USE_OPENSSL=	yes
USE_LIBTOOL=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/libfreenet

USE_GMAKE=	yes

INSTALLS_SHLIB=	yes

.include <bsd.port.mk>
