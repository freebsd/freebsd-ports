# ex:ts=8
# New ports collection makefile for:	libfreenet
# Date created:			Mar 31, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libfreenet
PORTVERSION=	0.5.0
CATEGORIES=	net
MASTER_SITES=	http://thalassocracy.org/libfreenet/

MAINTAINER=	ports@FreeBSD.org

USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	--includedir=${PREFIX}/include/libfreenet
INSTALLS_SHLIB=	yes

post-patch:
	@${PERL} -pi -e 's|-g -Wall|\@CFLAGS\@|g' ${WRKSRC}/Makefile.in

.include <bsd.port.mk>
