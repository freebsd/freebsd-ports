# Created by: Jean-Yves Lefort <jylefort@brutele.be>
# $FreeBSD$

PORTNAME=	mail-notification
DISTVERSION=	5.4
PORTREVISION=	15
CATEGORIES=	mail ipv6
MASTER_SITES=	SAVANNAH/mailnotify-orig

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail notification for freedesktop.org-compliant system trays

BROKEN=		Run-time failure with Gnome 3

LIB_DEPENDS=	libdbus-glib-1.so:${PORTSDIR}/devel/dbus-glib \
		libgnome-keyring.so:${PORTSDIR}/security/gnome-keyring \
		libnotify.so:${PORTSDIR}/devel/libnotify

USES=		gettext tar:bzip2
USE_LDCONFIG=	yes
USE_GNOME=	gconf2 gnomeprefix gnomevfs2 libglade2 libgnomeui libxml2
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
JB_CONF_ARGS=	cc="${CC}" cflags="${CFLAGS}" cppflags="${CPPFLAGS}" ldflags="${LDFLAGS}" prefix="${PREFIX}" destdir="${STAGEDIR}" hotmail=no
JB_CONF_ENV=	${MAKE_ENV} jb_cppflags="${CPPFLAGS}" jb_ldflags="${LDFLAGS}"
GCONF_SCHEMAS=	mail-notification.schemas
INSTALLS_OMF=	yes
INSTALLS_ICONS=	yes

OPTIONS_DEFINE=	EVOLUTION GMAIL IMAP MAILDIR MBOX MH MOZILLA \
		POP3 SASL SSL SYLPHEED
OPTIONS_DEFAULT=	GMAIL IMAP MAILDIR MBOX MH MOZILLA \
			POP3 SASL SSL SYLPHEED
EVOLUTION_DESC=	Evolution support
GMAIL_DESC=	Gmail support
IMAP_DESC=	IMAP support
MAILDIR_DESC=	Maildir support
MBOX_DESC=	mbox support
MH_DESC=	MH support
MOZILLA_DESC=	Mozilla products support
POP3_DESC=	POP3 support
SYLPHEED_DESC=	Sylpheed support

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MMBOX}
JB_CONF_ARGS+=	mbox=no
.endif
.if ! ${PORT_OPTIONS:MMH}
JB_CONF_ARGS+=	mh=no
.endif
.if ! ${PORT_OPTIONS:MMAILDIR}
JB_CONF_ARGS+=	maildir=no
.endif
.if ! ${PORT_OPTIONS:MPOP3}
JB_CONF_ARGS+=	pop3=no
.endif
.if ! ${PORT_OPTIONS:MIMAP}
JB_CONF_ARGS+=	imap=no
.endif
.if ! ${PORT_OPTIONS:MPOP3} && ! ${PORT_OPTIONS:MIMAP}
# only POP3 and IMAP use SSL and SASL
WITHOUT_SSL=	yes
WITHOUT_SASL=	yes
.endif
.if ! ${PORT_OPTIONS:MGMAIL}
JB_CONF_ARGS+=	gmail=no
PLIST_SUB+=	GMAIL="@comment "
.else
PLIST_SUB+=	GMAIL=""
.endif
JB_CONF_ARGS+=	yahoo=no
.if ! ${PORT_OPTIONS:MEVOLUTION}
JB_CONF_ARGS+=	evolution=no
PLIST_SUB+=	EVOLUTION="@comment "
.else
EVO_VERSION!=	make -C ${PORTSDIR}/mail/evolution -V EVO_VERSION
BUILD_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/evolution-plugin.pc:${PORTSDIR}/mail/evolution
RUN_DEPENDS+=	${LOCALBASE}/libdata/pkgconfig/evolution-plugin.pc:${PORTSDIR}/mail/evolution
USE_GNOME+=	gtkhtml3
PLIST_SUB+=	EVOLUTION="" EVO_VERSION=${EVO_VERSION}
.endif
.if ! ${PORT_OPTIONS:MMOZILLA}
JB_CONF_ARGS+=	mozilla=no
.endif
.if ! ${PORT_OPTIONS:MSYLPHEED}
JB_CONF_ARGS+=	sylpheed=no
.endif
.if ${PORT_OPTIONS:MMBOX} \
	|| ${PORT_OPTIONS:MMH} \
	|| ${PORT_OPTIONS:MMAILDIR} \
	|| ${PORT_OPTIONS:MPOP3} \
	|| ${PORT_OPTIONS:MIMAP} \
	|| ${PORT_OPTIONS:MMOZILLA} \
	|| ${PORT_OPTIONS:MSYLPHEED}
LIB_DEPENDS+=	libgmime-2.6.so:${PORTSDIR}/mail/gmime26
.endif
.if ! ${PORT_OPTIONS:MSSL}
JB_CONF_ARGS+=	ssl=no
.else
USE_OPENSSL=	yes
.endif
.if ! ${PORT_OPTIONS:MSASL}
JB_CONF_ARGS+=	sasl=no
.else
LIB_DEPENDS+=	libsasl2.so:${PORTSDIR}/security/cyrus-sasl2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||g' ${WRKSRC}/jb ${WRKSRC}/jbsrc/jb.c

do-configure:
	cd ${WRKSRC} && ${SETENV} ${JB_CONF_ENV} \
		./jb configure ${JB_CONF_ARGS}

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./jb build
	${STRIP_CMD} ${WRKSRC}/build/src/mail-notification

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./jb install

.include <bsd.port.mk>
