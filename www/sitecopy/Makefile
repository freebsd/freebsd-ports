# New ports collection makefile for:	sitecopy
# Date created:		15 January 1999
# Whom:			nik
#
# $FreeBSD$
#

PORTNAME=	sitecopy
PORTVERSION=	0.16.1
PORTREVISION?=	1
CATEGORIES=	www
MASTER_SITES=	http://www.lyra.org/sitecopy/

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Maintains remote websites, uses FTP or WebDAV to sync up with local copy

LIB_DEPENDS=	neon.25:${PORTSDIR}/www/neon

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CC="${CC} -I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib -lintl"
CONFIGURE_ARGS=	--with-neon --with-libxml2
USE_GETTEXT=	yes
USE_GNOME=	libxml2
USE_GETOPT_LONG=	yes
USE_GMAKE=	yes

.ifndef WITHOUT_SSL
USE_OPENSSL=	yes
CONFIGURE_ARGS+=	--with-ssl
.endif

MAN1=		sitecopy.1

post-patch:
	@${REINPLACE_CMD} -e 's|;;|;|g' \
		${WRKSRC}/src/sitestore.c

.include <bsd.port.mk>
