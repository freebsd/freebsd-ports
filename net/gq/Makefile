# Created by: Roman Shterenzon <roman@xpert.com>
# $FreeBSD$

PORTNAME=	gq
PORTVERSION=	1.3.4
PORTREVISION=	11
PORTEPOCH=	1
CATEGORIES=	net
MASTER_SITES=	SF/${PORTNAME}client/GQ%20Unstable/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK-based LDAP client

LIB_DEPENDS=	libgnome-keyring.so:${PORTSDIR}/security/gnome-keyring

OPTIONS_DEFINE=	DND CACHE
OPTIONS_DEFAULT=	DND CACHE
DND_DESC=	Enable Drag and drop support in browse mode
CACHE_DESC=	Support the OpenLDAP experimental client cache

USE_GNOME=	libglade2 gnomedocutils
USE_OPENSSL=	yes
USE_OPENLDAP=	yes
USES=		gettext gmake pkgconfig shared-mime-info desktop-file-utils
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-ldap-prefix=${LOCALBASE} --disable-update-mimedb
DND_CONFIGURE_ENABLE=	browser-dns
CACHE_CONFIGURE_ENABLE=	cache
INSTALLS_ICONS=	yes

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS} -Wno-return-type
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' \
		${WRKSRC}/src/syntax.h \
		${WRKSRC}/src/glib-helpers.[ch] \
		${WRKSRC}/src/gq-hash.h \
		${WRKSRC}/src/gq-main-loop.h \
		${WRKSRC}/src/gq-stack.[ch] \
		${WRKSRC}/src/gq-tab.h

.include <bsd.port.mk>
