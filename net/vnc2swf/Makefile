# Ports collection makefile for:  vnc2swf
# Date created:			  Sun Dec 7 2:45:15 CET 2003
# Whom:				  Sebastian Yepes F. <esn@x123.info>
#
# $FreeBSD$
#

PORTNAME=	vnc2swf
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.unixuser.org/~euske/${PORTNAME}/

MAINTAINER=	esn@x123.info
COMMENT=	VNC Session Recorder To Format (Movie) swf

LIB_DEPENDS=	ming:${PORTSDIR}/graphics/ming

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--with-ming=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/ming"

.include <bsd.port.mk>
