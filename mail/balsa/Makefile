# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#   $MCom: ports-stable/mail/balsa/Makefile,v 1.3 2007/12/02 19:18:50 marcus Exp $
#

PORTNAME=	balsa
PORTVERSION=	2.4.8
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://pawsa.fedorapeople.org/balsa/
DISTNAME=	balsa-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mail reader for the GNOME 2 desktop

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		esmtp.6:${PORTSDIR}/mail/libesmtp \
		gmime-2.4.6:${PORTSDIR}/mail/gmime24 \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		canberra-gtk.0:${PORTSDIR}/audio/libcanberra

USE_GMAKE=	yes
USE_BZIP2=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui gtkhtml3 \
		libgnomeprintui
USE_GETTEXT=	yes
USE_AUTOTOOLS=	libltdl
GNU_CONFIGURE=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--enable-threads \
		--disable-more-warnings \
		--with-ssl \
		--without-nm \
		--with-canberra
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv ${PTHREAD_LIBS}"

MAN1=		balsa.1

OPTIONS=	LDAP "Enable LDAP support" on \
		GTKSPELL "Spell checking support" on \
		GTKSV "Enable GtkSourceview support" on \
		NOTIFY "Enable libnotify support" on \
		GPG "Enable GnuPG support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GPG)
LIB_DEPENDS+=		gpgme.18:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}/bin/gpgme-config
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.if !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell
CONFIGURE_ARGS+=--with-gtkspell
.endif

.if !defined(WITHOUT_GTKSV)
USE_GNOME+=	gtksourceview2
CONFIGURE_ARGS+=--with-gtksourceview=2
.endif

.if !defined(WITHOUT_NOTIFY)
LIB_DEPENDS+=	notify.1:${PORTSDIR}/devel/libnotify
CONFIGURE_ARGS+=--with-libnotify=yes
.else
CONFIGURE_ARGS+=--with-libnotify=no
.endif

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
