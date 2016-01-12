# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gtkimageview
PORTVERSION=	1.6.4
PORTREVISION=	5
CATEGORIES=	x11-toolkits
MASTER_SITES=	LOCAL/kwm
# http://trac.bjourne.webfactional.com/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple image viewer widget

LICENSE=	LGPL21+ # source says LGPL20+ though
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-html-dir=${PREFIX}/share/doc
USES=		libtool pathfix pkgconfig
USE_GNOME=	gtk20
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e '/^gtkimageview-marshal.[ch]:/s|$$[(]GLIB_GENMARSHAL[)]||'\
		${WRKSRC}/src/Makefile.in
	@${REINPLACE_CMD} -e '/^CFLAGS/s|-Werror||' ${WRKSRC}/configure

.include <bsd.port.mk>
