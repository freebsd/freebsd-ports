# New ports collection makefile for:	newpki-client
# Date created:		2005-07-05
# Whom:			Vsevolod Stakhov <vsevolod@highsecure.ru>
#
# $FreeBSD$
#

PORTNAME=	newpki-client
DISTVERSION=	2.0.0-beta4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	newpki

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ PKI client from newpki project

LIB_DEPENDS=	newpki.2:${PORTSDIR}/security/newpki-lib \
		xml2:${PORTSDIR}/textproc/libxml2 \
		wx_gtk2-2.4.0:${PORTSDIR}/x11-toolkits/wxgtk24

WRKSRC=		${WRKDIR}/${PORTNAME}-2.0.0

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
WX_CONFIG=	${X11BASE}/bin/wxgtk2-2.4-config
USE_GNOME=	gnometarget
USE_GMAKE=	yes

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

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"does not compile (C++ libraries compiled with conflicting gcc versions)"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g' ${WRKSRC}/configure

.include <bsd.port.post.mk>
