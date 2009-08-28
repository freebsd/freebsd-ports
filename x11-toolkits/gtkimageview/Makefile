# New ports collection makefile for:	gtkimageview
# Date created:		1 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtkimageview
PORTVERSION=	1.6.3
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	LOCAL/chinsan http://people.freebsd.org/~chinsan/
# http://trac.bjourne.webfactional.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer widget

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_GNOME=	gtk20
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^gtkimageview-marshal.[ch]:/s|$$[(]GLIB_GENMARSHAL[)]||'\
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^CFLAGS/s|-Werror||' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e '/^pkgconfigdir/s|=.*|=${PREFIX}/libdata/pkgconfig|'\
		${WRKSRC}/Makefile.in

.include <bsd.port.mk>
