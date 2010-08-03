# New ports collection makefile for:	sitecopy
# Date created:		15 January 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	sitecopy
PORTVERSION=	0.16.6
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.manyfish.co.uk/${PORTNAME}/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles

MAINTAINER=	sitecopy@oldach.net
COMMENT=	Maintains remote websites, uses FTP or WebDAV to sync up w/ local copy

LIB_DEPENDS=	neon.27:${PORTSDIR}/www/neon29

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" \
		LIBS="${LIBS}"
LIBS=		-L${LOCALBASE}/lib
CONFIGURE_ARGS=	--with-neon --with-libxml2
USE_GNOME=	libxml2
USE_GMAKE=	yes

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
LIBS+=		-lintl
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.endif

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

MAN1=		sitecopy.1

post-patch:
	@${REINPLACE_CMD} -e 's|;;|;|g' \
		${WRKSRC}/src/sitestore.c
	@${REINPLACE_CMD} -e 's|25 26 27 28|25 26 27 28 29|g' \
		${WRKSRC}/configure

.include <bsd.port.mk>
