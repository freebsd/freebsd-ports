# New ports collection makefile for:	sitecopy
# Date created:		15 January 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	sitecopy
PORTVERSION=	0.11.4
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.lyra.org/sitecopy/

MAINTAINER=	olgeni@FreeBSD.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--with-included-neon --with-libxml1

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--with-ssl=${OPENSSLBASE}
.endif

USE_GMAKE=	yes

MAN1=		sitecopy.1

.include <bsd.port.mk>
