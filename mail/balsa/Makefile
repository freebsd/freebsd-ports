# Created by: Glenn Johnson <gljohns@bellsouth.net>
# $FreeBSD$
#   $MCom: ports-stable/mail/balsa/Makefile,v 1.3 2007/12/02 19:18:50 marcus Exp $

PORTNAME=	balsa
PORTVERSION=	2.4.8
PORTREVISION=	7
CATEGORIES=	mail gnome
MASTER_SITES=	http://pawsa.fedorapeople.org/balsa/
DISTNAME=	balsa-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mail reader for the GNOME 2 desktop

LIB_DEPENDS=	aspell:${PORTSDIR}/textproc/aspell \
		pcre:${PORTSDIR}/devel/pcre \
		esmtp:${PORTSDIR}/mail/libesmtp \
		gmime-2.4:${PORTSDIR}/mail/gmime24 \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		canberra-gtk:${PORTSDIR}/audio/libcanberra

USE_BZIP2=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_OPENSSL=	yes
USES=		pathfix gettext iconv perl5 pkgconfig gmake
USE_GNOME=	gnomeprefix intlhack libgnomeui gtkhtml3 \
		libgnomeprintui
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-threads \
		--disable-more-warnings \
		--with-ssl \
		--without-nm \
		--with-canberra
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib ${ICONV_LIB} ${PTHREAD_LIBS}"
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}

MAN1=		balsa.1

OPTIONS_DEFINE=	LDAP GTKSPELL GTKSV NOTIFY GPG
OPTIONS_DEFAULT=LDAP GTKSPELL GTKSV NOTIFY
GTKSPELL_DESC=	Spell checking support
GTKSV_DESC=	GtkSourceview support
GPG_DESC=	GnuPG support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGPG}
LIB_DEPENDS+=		gpgme:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}/bin/gpgme-config
.endif

.if ${PORT_OPTIONS:MLDAP}
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.if ${PORT_OPTIONS:MGTKSPELL}
LIB_DEPENDS+=	gtkspell:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--with-gtkspell
.endif

.if ${PORT_OPTIONS:MGTKSV}
USE_GNOME+=	gtksourceview2
CONFIGURE_ARGS+=--with-gtksourceview=2
.endif

.if ${PORT_OPTIONS:MNOTIFY}
LIB_DEPENDS+=	notify:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--with-libnotify=yes
.else
CONFIGURE_ARGS+=--with-libnotify=no
.endif

.include <bsd.port.pre.mk>

.if ${PREFIX}==${LOCALBASE}
PLIST_SUB+=	GTKICON="@comment "
.else
PLIST_SUB+=	GTKICON=""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|stdint.h|inttypes.h|g' \
		${WRKSRC}/libbalsa/mailbox_imap.c
# PREFIX safeness
	@${REINPLACE_CMD} -E \
		-e 's|^(HICOLOR_ICON_DIR)[^/]+/|\1=${PREFIX}/|' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} ${REINPLACE_CMD} -e \
		's|-D.*_DISABLE_DEPRECATED_SOURCE||g ; s|-D.*_DISABLE_DEPRECATED||g'

.include <bsd.port.post.mk>
