# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	gq
PORTVERSION=	1.3.4
PORTREVISION=	13
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}client/GQ%20Unstable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based LDAP client

LICENSE=	GPLv2+ LGPL21+ # some source files are under lgpl
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnome-keyring.so:security/libgnome-keyring

USE_GNOME=	intltool libglade2 gnomedocutils
USE_OPENLDAP=	yes
USES=		desktop-file-utils gettext gmake gnome pkgconfig \
		shared-mime-info ssl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE} --disable-update-mimedb
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -Wno-return-type
LIBS+=		-L${LOCALBASE}/lib -lcrypto

OPTIONS_DEFINE=	DND CACHE
OPTIONS_DEFAULT=	DND CACHE
DND_DESC=	Enable Drag and drop support in browse mode
DND_CONFIGURE_ENABLE=	browser-dns
CACHE_DESC=	Support the OpenLDAP experimental client cache
CACHE_CONFIGURE_ENABLE=	cache

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/syntax.h \
		${WRKSRC}/src/glib-helpers.[ch] \
		${WRKSRC}/src/gq-hash.h \
		${WRKSRC}/src/gq-main-loop.h \
		${WRKSRC}/src/gq-stack.[ch] \
		${WRKSRC}/src/gq-tab.h

.include <bsd.port.mk>
