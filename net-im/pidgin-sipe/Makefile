# Created by: John Prather
# $FreeBSD$

PORTNAME=	pidgin-sipe
PORTVERSION=	1.21.1
PORTREVISION=	1
CATEGORIES=	net-im
MASTER_SITES=	SF/sipe/sipe/${DISTNAME}

MAINTAINER=	john.c.prather@gmail.com
COMMENT=	Plugin for Pidgin to provide LCS/OCS connectivity

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnss3.so:security/nss \
		libpurple.so:net-im/libpurple \
		libplds4.so:devel/nspr \
		libgstreamer-1.0.so:multimedia/gstreamer1 \
		libnice.so:net-im/libnice \
		libgmime-2.6.so:mail/gmime26

RUN_DEPENDS=	pidgin:net-im/pidgin

GNU_CONFIGURE=	yes
USES=		gmake libtool localbase pkgconfig tar:bzip2 ssl
USE_GNOME=	gtk20 intltool libxml2
PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README TODO
CONFIGURE_ARGS=	--enable-purple \
		--disable-telepathy
INSTALL_TARGET=	install-strip

USE_LDCONFIG=	yes

OPTIONS_DEFINE=		OCS2005 KRB5 DOCS NLS
OPTIONS_SUB=		yes

OSC2005_DESC=		Message timeout for OCS2005
OSC2005_CONFIGURE_ENABLE=	ocs2005-message-hack
KRB5_DESC=		With Kerberos5
KRB5_CONFIGURE_WITH=	krb5

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext

post-patch:
	@${REINPLACE_CMD} 's/LDLAGS/LDFLAGS/' ${WRKSRC}/configure

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
