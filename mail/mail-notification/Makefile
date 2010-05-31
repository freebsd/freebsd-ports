# New ports collection makefile for:	mail-notification
# Date created:			18 Sep 2003
# Whom:				Jean-Yves Lefort <jylefort@brutele.be>
#
# $FreeBSD$
#

PORTNAME=	mail-notification
DISTVERSION=	5.4
PORTREVISION=	6
CATEGORIES=	mail ipv6
MASTER_SITES=	${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	mailnotify

MAINTAINER=	mwisnicki+freebsd@gmail.com
COMMENT=	A mail notification for freedesktop.org-compliant system trays

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib \
		gnome-keyring:${PORTSDIR}/security/gnome-keyring \
		notify:${PORTSDIR}/devel/libnotify

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_LDCONFIG=	yes
USE_GNOME=	gconf2 gnomeprefix gnomevfs2 libglade2 libgnomeui libxml2
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
JB_CONF_ARGS=	cc="${CC}" cflags="${CFLAGS}" cppflags="${CPPFLAGS}" ldflags="${LDFLAGS}" prefix="${PREFIX}"
JB_CONF_ENV=	jb_cppflags="${CPPFLAGS}" jb_ldflags="${LDFLAGS}"
GCONF_SCHEMAS=	mail-notification.schemas
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

OPTIONS=	EVOLUTION "Evolution support" off \
		GMAIL "Gmail support" on \
		HOTMAIL "Windows Live Hotmail support" on \
		IMAP "IMAP support" on \
		MAILDIR "Maildir support" on \
		MBOX "mbox support" on \
		MH "MH support" on \
		MOZILLA "Mozilla products support" on \
		POP3 "POP3 support" on \
		SASL "SASL authentication support" on \
		SSL "SSL/TLS support" on \
		SYLPHEED "Sylpheed support" on \
		YAHOO "Yahoo! Mail support" on

.include <bsd.port.pre.mk>

.if defined(WITHOUT_MBOX)
JB_CONF_ARGS+=	mbox=no
.endif
.if defined(WITHOUT_MH)
JB_CONF_ARGS+=	mh=no
.endif
.if defined(WITHOUT_MAILDIR)
JB_CONF_ARGS+=	maildir=no
.endif
.if defined(WITHOUT_POP3)
JB_CONF_ARGS+=	pop3=no
.endif
.if defined(WITHOUT_IMAP)
JB_CONF_ARGS+=	imap=no
.endif
.if defined(WITHOUT_POP3) && defined(WITHOUT_IMAP)
# only POP3 and IMAP use SSL and SASL
WITHOUT_SSL=	yes
WITHOUT_SASL=	yes
.endif
.if defined(WITHOUT_GMAIL)
JB_CONF_ARGS+=	gmail=no
PLIST_SUB+=	GMAIL="@comment "
.else
PLIST_SUB+=	GMAIL=""
.endif
.if defined(WITHOUT_HOTMAIL)
JB_CONF_ARGS+=	hotmail=no
PLIST_SUB+=	HOTMAIL="@comment "
.else
RUN_DEPENDS+=	getlive:${PORTSDIR}/mail/getlive
PLIST_SUB+=	HOTMAIL=""
.endif
.if defined(WITHOUT_YAHOO)
JB_CONF_ARGS+=	yahoo=no
PLIST_SUB+=	YAHOO="@comment "
.else
RUN_DEPENDS+=	fetchyahoo:${PORTSDIR}/mail/fetchyahoo
PLIST_SUB+=	YAHOO=""
.endif
.if defined(WITHOUT_EVOLUTION)
JB_CONF_ARGS+=	evolution=no
PLIST_SUB+=	EVOLUTION="@comment "
.else
EVO_VERSION!=	make -C ${PORTSDIR}/mail/evolution -V EVO_VERSION
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/evolution-plugin.pc:${PORTSDIR}/mail/evolution
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/evolution-plugin.pc:${PORTSDIR}/mail/evolution
PLIST_SUB+=	EVOLUTION="" EVO_VERSION=${EVO_VERSION}
# Work around the fact that MN is using evolution's private(?) api that is not part of
# evolution-plugin thus it's includes are not covered by pkgconfig metadata.
# That path is frozen at 3.14 even for later versions of libgtkhtml.
CFLAGS+=	-I${LOCALBASE}/include/libgtkhtml-3.14 -I${LOCALBASE}/include/libgtkhtml-3.14/editor
.endif
.if defined(WITHOUT_MOZILLA)
JB_CONF_ARGS+=	mozilla=no
.endif
.if defined(WITHOUT_SYLPHEED)
JB_CONF_ARGS+=	sylpheed=no
.endif
.if defined(WITH_MBOX) \
	|| defined(WITH_MH) \
	|| defined(WITH_MAILDIR) \
	|| defined(WITH_POP3) \
	|| defined(WITH_IMAP) \
	|| defined(WITH_MOZILLA) \
	|| defined(WITH_SYLPHEED) \
	|| defined(WITH_HOTMAIL) \
	|| defined(WITH_YAHOO)
LIB_DEPENDS+=	gmime-2.0.4:${PORTSDIR}/mail/gmime2
.endif
.if defined(WITHOUT_SSL)
JB_CONF_ARGS+=	ssl=no
.else
# we can't use USE_OPENSSL=yes after including bsd.port.pre.mk
.include "${PORTSDIR}/Mk/bsd.openssl.mk"
.endif
.if defined(WITHOUT_SASL)
JB_CONF_ARGS+=	sasl=no
.else
LIB_DEPENDS+=	sasl2:${PORTSDIR}/security/cyrus-sasl2
.endif

post-patch:
.if ${OSVERSION} < 700042
	@${REINPLACE_CMD} -e "s,-Wno-pointer-sign,," ${WRKSRC}/jb
.endif

do-configure:
	cd ${WRKSRC} && ${JB_CONF_ENV} ./jb configure ${JB_CONF_ARGS}

do-build:
	cd ${WRKSRC} && ./jb build

do-install:
	cd ${WRKSRC} && ./jb install

.include <bsd.port.post.mk>
