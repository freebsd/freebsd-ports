# ex:ts=8
# New ports collection makefile for:	gsk
# Date created:			May 1, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gsk
PORTVERSION=	0.3.5
PORTREVISION=	1
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C library for writing servers

USE_GNOME=	glib12
USE_GMAKE=	yes
USE_PERL5=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes

.if !defined(WITHOUT_OPENSSL)
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--enable-ssl
.endif

.include <bsd.port.mk>
