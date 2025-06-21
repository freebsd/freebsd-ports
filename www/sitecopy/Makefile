PORTNAME=	sitecopy
PORTVERSION=	0.16.6
PORTREVISION=	9
CATEGORIES=	www
MASTER_SITES=	http://www.manyfish.co.uk/${PORTNAME}/

MAINTAINER=	sitecopy@oldach.net
COMMENT=	Maintains remote websites, uses FTP or WebDAV to sync up w/ local copy
WWW=		https://www.manyfish.co.uk/sitecopy/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		Fails to build with neon 0.32+, configure: incompatible neon library version 0.34.0: wanted 0.24 25 26 27 28 29 30 31 32

LIB_DEPENDS=	libneon.so:www/neon

USES=		gmake gnome localbase
USE_GNOME=	libxml2

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-neon --with-libxml2

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_OFF=	--disable-nls
NLS_LIBS=	-lintl

.include <bsd.port.options.mk>

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
