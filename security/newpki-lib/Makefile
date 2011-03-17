# New ports collection makefile for:	newpki-lib
# Date created:		2005-07-05
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	newpki-lib
DISTVERSION=	2.0.0-beta4
PORTREVISION=	2
CATEGORIES=	security devel
MASTER_SITES=	SF/newpki/${PORTNAME}/2.0.0-beta4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ PKI libraries from newpki project

BROKEN=		does not compile with OpenSSL 0.9.8b
DEPRECATED=	does not compile on FreeBSD 7.x or newer
EXPIRATION_DATE=2011-04-17

WRKSRC=		${WRKDIR}/${PORTNAME}-2.0.0

USE_OPENSSL=	yes
USE_GMAKE=	yes
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS+=	--includedir=${PREFIX}/include/newpki

.if defined(WITHOUT_NLS)
BROKEN=		does not build without gettext
PLIST_SUB+=	NLS="@comment "
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
.endif

pre-patch:
	@${FIND} ${WRKSRC} -name '*.cpp' -or -name '*.h' | ${XARGS} ${REINPLACE_CMD} -e 's|||g'

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
