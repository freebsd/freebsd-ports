# New ports collection makefile for:   libqalculate
# Date created:        03 June 2004
# Whom:                Sergey Akifyev <asa@agava.com>
#
# $FreeBSD$
#

PORTNAME=	libqalculate
PORTVERSION=	0.9.6
PORTREVISION=	5
CATEGORIES=	math
MASTER_SITES=	SF/qalculate/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	scjamorim@bsd.com.br
COMMENT=	A a multi-purpose desktop calculator (backend library)

LIB_DEPENDS=	cln.6:${PORTSDIR}/math/cln

USE_GNOME=	glib20 gnomehack gnometarget intlhack libxml2
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e '/^SUBDIRS =/s|docs||g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e 's/^GMSGFMT = @GMSGFMT@/GMSGFMT = msgfmt/' ${WRKSRC}/po/Makefile.in.in
	@${REINPLACE_CMD} -e 's/-pthread/${PTHREAD_LIBS}/' ${WRKSRC}/configure

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=		NLS="@comment "
.else
USE_GETTEXT=		yes
PLIST_SUB+=		NLS=""
.endif

.include <bsd.port.mk>
