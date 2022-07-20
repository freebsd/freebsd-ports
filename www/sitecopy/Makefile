PORTNAME=	sitecopy
PORTVERSION=	0.16.6
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	http://www.manyfish.co.uk/${PORTNAME}/ \
		GENTOO

MAINTAINER=	sitecopy@oldach.net
COMMENT=	Maintains remote websites, uses FTP or WebDAV to sync up w/ local copy

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libneon.so:www/neon

USES=		gmake gnome localbase
USE_GNOME=	libxml2
GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-neon --with-libxml2

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
LIBS+=		-lintl
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.ifndef WITHOUT_SSL
USES+=	ssl
CONFIGURE_ARGS+=	--with-ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|;;|;|g' \
		${WRKSRC}/src/sitestore.c
	@${REINPLACE_CMD} -e 's|25 26 27 28|& 29 30 31 32|g' \
		${WRKSRC}/configure
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -e '/#define ksize_t /d' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
