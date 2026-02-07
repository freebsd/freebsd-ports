PORTNAME=	sitecopy
DISTVERSION=	0.16.6
PORTREVISION=	10
CATEGORIES=	www
MASTER_SITES=	http://www.manyfish.co.uk/${PORTNAME}/

MAINTAINER=	sitecopy@oldach.net
COMMENT=	Maintains remote websites, uses FTP or WebDAV to sync up w/ local copy
WWW=		https://www.manyfish.co.uk/sitecopy/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libneon.so:www/neon
# Depending on www/neon, this port may be linked against the following
# libraries: libexpat.so:textproc/expat2, libxml2.so:textproc/libxml2,
# libproxy.so:net/libproxy.
# Bump this port if the SONAME of the using library has been bumped.

USES=		gettext-runtime gmake localbase

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-neon

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext-tools
NLS_CONFIGURE_OFF=	--disable-nls

.include <bsd.port.options.mk>

.ifndef WITHOUT_SSL
USES+=			ssl
CONFIGURE_ARGS+=	--with-ssl
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|25 26 27 28|& 29 [3-][0-9]|g' \
		${WRKSRC}/configure
.if ${OPSYS} == FreeBSD
	@${REINPLACE_CMD} -e '/#define ksize_t /d' \
		${WRKSRC}/configure
.endif

.include <bsd.port.mk>
