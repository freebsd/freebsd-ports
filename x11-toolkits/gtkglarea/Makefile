# New ports collection makefile for:	gtkglarea
# Date created:		1 August 1999
# Whom:			Michael Sardo <jaeger16@yahoo.com>
#
# $FreeBSD$
#

PORTNAME=	gtkglarea
PORTVERSION=	1.2.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.student.oulu.fi/~jlof/gtkglarea/download/

MAINTAINER=	jaeger16@yahoo.com

USE_X_PREFIX=	yes
USE_MESA=	yes
USE_GNOMENG=	yes
USE_GNOME=	gtk12
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--with-lib-GL
CONFIGURE_ENV=	LIBS="${PTHREAD_LIBS} -lstdc++"

.include <bsd.port.mk>
