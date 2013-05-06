.if defined(PKGNAMESUFFIX)

PORTNAME=	remmina-plugin

MASTER_SITES=	SF/remmina/0.9
DISTNAME=	remmina-plugins-${PORTVERSION}
DISTFILES=	${DISTNAME}.tar.gz

BUILD_DEPENDS+=	${LOCALBASE}/include/remmina/plugin.h:${PORTSDIR}/net/remmina
RUN_DEPENDS+=	remmina:${PORTSDIR}/net/remmina

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GNOME=	glib20 gtk20
INSTALLS_ICONS=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ARGS+=--disable-nx --disable-rdp --disable-ssh --disable-telepathy \
		--disable-vnc --disable-xdmcp --disable-nls

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

.include <bsd.port.pre.mk>

.if ${PKGNAMESUFFIX} == "-i18n"
CONFIGURE_ARGS+=--enable-nls
PLIST=		${.CURDIR}/pkg-plist
.else
CONFIGURE_ARGS+=--enable${PKGNAMESUFFIX}
PLIST_SUB+=	PLUGIN="${PKGNAMESUFFIX:S,-,,}"
PLIST=		${PKGDIR}/pkg-plist.plugin

.if ${PORT_OPTIONS:MTELEP}
PLIST_SUB+=	TELEP="" ICONS="@comment "
.else
PLIST_SUB+=	TELEP="@comment " ICONS=""
.endif
.if ${PORT_OPTIONS:MTELEP}
LIB_DEPENDS+=	ssh.4:${PORTSDIR}/security/libssh
CONFIGURE_ARGS+=--enable-ssh
PLIST_SUB+=	SSH="@comment "
.if ${OSVERSION} >= 800040
LDFLAGS+=	-fstack-protector
.endif
.else
PLIST_SUB+=	SSH=""
.endif

.if ${PORT_OPTIONS:MNLS}
RUN_DEPENDS+=	${LOCALBASE}/share/locale/bg/LC_MESSAGES/remmina-plugins.mo:${PORTSDIR}/net/remmina-plugin-i18n
.endif

.endif

.include <bsd.port.post.mk>
.endif
