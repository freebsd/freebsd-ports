# New ports collection makefile for:	newpki-client
# Date created:		2005-07-05
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	newpki-client
DISTVERSION=	2.0.0-beta4
PORTREVISION=	6
CATEGORIES=	security
MASTER_SITES=	SF/newpki/${PORTNAME}/2.0.0-beta4

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ PKI client from newpki project

LIB_DEPENDS=	newpki.2:${PORTSDIR}/security/newpki-lib \
		xml2:${PORTSDIR}/textproc/libxml2

WRKSRC=		${WRKDIR}/${PORTNAME}-2.0.0

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnometarget
USE_GMAKE=	yes
USE_WX=		2.4

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		LDFLAGS="-L${LOCALBASE}/lib -L${PREFIX}/lib" \
		WXCONFIG=${WX_CONFIG}
CONFIGURE_ARGS+=	--with-newpki-include=${PREFIX}/include/newpki \
			--with-newpki-lib=${PREFIX}/lib \
			--with-libxml2-include=${PREFIX}/include/libxml2

PLIST_FILES=	bin/newpki-client

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
.else
USE_GETTEXT=	yes
PLIST_FILES+=	share/locale/fr/LC_MESSAGES/newpki-client.mo
CONFIGURE_ARGS+=	--with-libintl-prefix=${LOCALBASE}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.mk>
