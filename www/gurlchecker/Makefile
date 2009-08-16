# New ports collection makefile for:	gURLChecker
# Date created:			06 Jun 2003
# Whom:				Koop Mast <einekoai@chello.nl>
#
# $FreeBSD$
#

PORTNAME=	gurlchecker
PORTVERSION=	0.10.1
PORTREVISION=	13
CATEGORIES=	www gnome
MASTER_SITES=	http://labs.libre-entreprise.org/frs/download.php/%SUBDIR%/
MASTER_SITE_SUBDIR=	547

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A Gnome program to check a page/website for broken links

LIB_DEPENDS=	gnet-2.0.0:${PORTSDIR}/net/gnet2 \
		gnutls.40:${PORTSDIR}/security/gnutls

OPTIONS=	CROCO "Use CROCO library for CSS2 validation" off \
		TIDY "Use TIDY library for HTML w3c validation" off \
		CLAMAV "Use CLAMAV library for virii scan" on \
		GNUTLS "Use GNU TLS library for HTTPS check" on

USE_GNOME=	gnomehack gnomeprefix intlhack libgnomeui
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_CROCO)
LIB_DEPENDS+=	croco-0.6.3:${PORTSDIR}/textproc/libcroco
.else
CONFIGURE_ARGS+=	--disable-croco
.endif

.if defined(WITH_TIDY)
LIB_DEPENDS+=	tidy-0.99.0:${PORTSDIR}/www/tidy-lib
.else
CONFIGURE_ARGS+=	--disable-tidy
.endif

.if defined(WITH_CLAMAV)
LIB_DEPENDS+=	clamav.6:${PORTSDIR}/security/clamav
.else
CONFIGURE_ARGS+=	--disable-clamav
.endif

.if defined(WITHOUT_GNUTLS)
CONFIGURE_ARGS+=	--disable-gnutls
.else
LIB_DEPENDS+=	gnutls.26:${PORTSDIR}/security/gnutls
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/maxratio/s|^.*||' ${WRKSRC}/src/ucclam.c
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|doc ui man|ui|g' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|-lresolv||g' ${WRKSRC}/src/Makefile.in
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} -e \
		'/^SUBDIRS/s|po ui|ui|g' ${WRKSRC}/Makefile.in
.endif

.include <bsd.port.post.mk>
