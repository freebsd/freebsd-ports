# New ports collection makefile for:	balsa
# Date created:				02 December 1998
# Whom:					Glenn Johnson <gljohns@bellsouth.net>
#
# $FreeBSD$
#   $MCom: ports-stable/mail/balsa/Makefile,v 1.1 2006/03/05 06:57:58 marcus Exp $
#

PORTNAME=	balsa
PORTVERSION=	2.3.12
PORTREVISION=	1
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.theochem.kth.se/~pawsa/balsa/
DISTNAME=	balsa-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	A mail reader for the GNOME 2 desktop

LIB_DEPENDS=	aspell.16:${PORTSDIR}/textproc/aspell \
		pcre.0:${PORTSDIR}/devel/pcre \
		esmtp.6:${PORTSDIR}/mail/libesmtp \
		gmime-2.0.4:${PORTSDIR}/mail/gmime2

USE_GMAKE=	yes
USE_BZIP2=	yes
USE_X_PREFIX=	yes
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes
USE_PERL5=	yes
USE_OPENSSL=	yes
USE_GNOME=	gnomeprefix intlhack gnomehack libgnomeui libgnomeprintui \
		gtkhtml3
USE_AUTOTOOLS=	libltdl:15
USE_GCC=	3.4+
GNU_CONFIGURE=	yes
USE_ICONV=	yes
CONFIGURE_ARGS=	--enable-threads \
		--enable-gtkhtml \
		--disable-more-warnings \
		--with-ssl \
		--enable-gtkhtml=yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib -liconv"

MAN1=		balsa.1

OPTIONS=	LDAP "Enable LDAP support" on \
		GTKSPELL "Spell checking support" on \
		GPG "Enable GnuPG support" off

.include <bsd.port.pre.mk>

.if defined(WITH_GPG)
LIB_DEPENDS+=		gpgme.15:${PORTSDIR}/security/gpgme
CONFIGURE_ARGS+=	--with-gpgme=${LOCALBASE}/bin/gpgme-config
.endif

.if !defined(WITHOUT_LDAP)
USE_OPENLDAP=		yes
CONFIGURE_ARGS+=	--with-ldap
.endif

.if !defined(WITHOUT_GTKSPELL)
LIB_DEPENDS+=	gtkspell.0:${PORTSDIR}/textproc/gtkspell2
CONFIGURE_ARGS+=--with-gtkspell
.endif

.if ${PREFIX}==${X11BASE}
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

post-install:
	@${X11BASE}/bin/gtk-update-icon-cache -f -q --ignore-theme-index \
		${PREFIX}/share/gnome/balsa/hicolor

.include <bsd.port.post.mk>
