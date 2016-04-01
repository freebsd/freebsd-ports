# Created by: Koop Mast <einekoai@chello.nl>
# $FreeBSD$

PORTNAME=	gurlchecker
PORTVERSION=	0.10.1
PORTREVISION=	24
CATEGORIES=	www gnome
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/547/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome program to check a page/website for broken links

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgnet-2.0.so:net/gnet2

OPTIONS_DEFINE=	CROCO TIDY CLAMAV GNUTLS
OPTIONS_DEFAULT=CLAMAV GNUTLS
CROCO_DESC=	Library for CSS2 validation
TIDY_DESC=	Library for HTML w3c validation
CLAMAV_DESC=	Library for virii scan
GNUTLS_DESC=	Library for HTTPS check

USES=		gmake libtool pathfix pkgconfig
USE_GNOME=	gnomeprefix intlhack libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-L${LOCALBASE}/lib -lm

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MCROCO}
LIB_DEPENDS+=	libcroco-0.6.so:textproc/libcroco
.else
CONFIGURE_ARGS+=	--disable-croco
.endif

.if ${PORT_OPTIONS:MTIDY}
LIB_DEPENDS+=	libtidy.so:www/tidy-lib
.else
CONFIGURE_ARGS+=	--disable-tidy
.endif

.if ${PORT_OPTIONS:MCLAMAV}
LIB_DEPENDS+=	libclamav.so:security/clamav
.else
CONFIGURE_ARGS+=	--disable-clamav
.endif

.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls.so:security/gnutls
.else
CONFIGURE_ARGS+=	--disable-gnutls
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/maxratio/s|^.*||' ${WRKSRC}/src/ucclam.c
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc ui man|ui|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-lresolv||g' ${WRKSRC}/src/Makefile.in
.if ! ${PORT_OPTIONS:MNLS}
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|po ui|ui|g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.mk>
