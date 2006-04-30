# New ports collection makefile for:	mail-notification
# Date created:			18 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=		mail-notification
PORTVERSION=		2.0
PORTREVISION=		3
CATEGORIES=		mail ipv6
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	mailnotify

MAINTAINER=		jylefort@FreeBSD.org
COMMENT=		A mail notification for freedesktop.org-compliant system trays

USE_REINPLACE=		yes
USE_X_PREFIX=		yes
USE_GNOME=		gnomeprefix gnomehack eel2
GNU_CONFIGURE=	yes
USE_GMAKE=		yes
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS=		-L${LOCALBASE}/lib
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
GCONF_SCHEMAS=		mail-notification.schemas
INSTALLS_OMF=		yes

OPTIONS=		MBOX "mbox support" on \
			MH "MH support" on \
			MAILDIR "Maildir support" on \
			POP3 "POP3 support" on \
			IMAP "IMAP support" on \
			SSL "SSL/TLS support" on \
			SASL "SASL authentication support" on \
			GMAIL "Gmail support" on \
			EVOLUTION "Evolution support" off \
			SYLPHEED "Sylpheed support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MBOX)
CONFIGURE_ARGS+=	--disable-mbox
.endif
.if defined(WITHOUT_MH)
CONFIGURE_ARGS+=	--disable-mh
.endif
.if defined(WITHOUT_MAILDIR)
CONFIGURE_ARGS+=	--disable-maildir
.endif
.if defined(WITHOUT_POP3)
CONFIGURE_ARGS+=	--disable-pop3
.endif
.if defined(WITHOUT_IMAP)
CONFIGURE_ARGS+=	--disable-imap
.endif
.if defined(WITHOUT_POP3) && defined(WITHOUT_IMAP)
# only POP3 and IMAP use SSL and SASL
WITHOUT_SSL=		yes
WITHOUT_SASL=		yes
.endif
.if defined(WITHOUT_GMAIL)
CONFIGURE_ARGS+=	--disable-gmail
PLIST_SUB+=		GMAIL="@comment "
.else
PLIST_SUB+=		GMAIL=""
.endif
.if defined(WITHOUT_EVOLUTION)
CONFIGURE_ARGS+=	--disable-evolution
PLIST_SUB+=		EVOLUTION="@comment "
.else
BUILD_DEPENDS+=		${NONEXISTENT}:${PORTSDIR}/mail/evolution:patch \
			${X11BASE}/libdata/pkgconfig/evolution-plugin-2.6.pc:${PORTSDIR}/mail/evolution
RUN_DEPENDS+=		${X11BASE}/libdata/pkgconfig/evolution-plugin-2.6.pc:${PORTSDIR}/mail/evolution
EVOLUTION_WRKSRC!=	cd ${PORTSDIR}/mail/evolution && ${MAKE} -V WRKSRC
CONFIGURE_ARGS+=	--with-evolution-source-dir="${EVOLUTION_WRKSRC}"
LDFLAGS+=		-Wl,-export-dynamic
PLIST_SUB+=		EVOLUTION="" LITERAL_PREFIX="${PREFIX}"
.endif
.if defined(WITHOUT_SYLPHEED)
CONFIGURE_ARGS+=	--disable-sylpheed
.endif
.if defined(WITH_MBOX) \
	|| defined(WITH_MH) \
	|| defined(WITH_MAILDIR) \
	|| defined(WITH_POP3) \
	|| defined(WITH_IMAP) \
	|| defined(WITH_SYLPHEED)
LIB_DEPENDS+=		gmime-2.0:${PORTSDIR}/mail/gmime2
.endif
.if defined(WITHOUT_SSL)
CONFIGURE_ARGS+=	--disable-ssl
.else
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif
.if defined(WITHOUT_SASL)
CONFIGURE_ARGS+=	--disable-sasl
.else
LIB_DEPENDS+=		sasl2:${PORTSDIR}/security/cyrus-sasl2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|evolution-plugin-2.2|evolution-plugin-2.6|' \
		${WRKSRC}/configure

.include <bsd.port.post.mk>
