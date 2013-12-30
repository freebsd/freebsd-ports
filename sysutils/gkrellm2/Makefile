# $FreeBSD$

PORTNAME=	gkrellm
PORTVERSION=	2.3.5
PORTREVISION=	4
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume
PKGNAMESUFFIX=	2

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A GTK based system monitor

LICENSE=	GPLv3

USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_RC_SUBR=	gkrellmd
WANT_GNOME=	yes

OPTIONS_DEFINE=		DOCS GKRELLM_CLIENT NLS NTLM
OPTIONS_RADIO=		SSL
OPTIONS_RADIO_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	GKRELLM_CLIENT NTLM OPENSSL
GKRELLM_CLIENT_DESC=	GKrellM Client

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGKRELLM_CLIENT}
CONFLICTS=	gkrellm-[^2].* gkrellm[^2]-[^2].*
USE_GNOME=	gtk20
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
MAKE_ENV+=	enable_nls=0
.endif
USE_XORG=	x11 sm
.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	libgnutls-openssl.so:${PORTSDIR}/security/gnutls
MAKE_ENV+=	GNUTLSINC=${LOCALBASE}/include GNUTLSLIB=${LOCALBASE}/lib \
		without-ssl=1
.elif ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
MAKE_ENV+=	without-gnutls=1
.else
MAKE_ENV+=	without-gnutls=1 without-ssl=1
.endif
.else
BUILD_WRKSRC=	${WRKSRC}/server
INSTALL_WRKSRC=	${WRKSRC}/server
USE_GNOME=	glib20
.endif

.if ${PORT_OPTIONS:MNTLM}
LIB_DEPENDS+=	libntlm.so:${PORTSDIR}/security/libntlm
.else
MAKE_ENV+=	without-ntlm=1
.endif

PLIST_SUB=	PREFIX=${PREFIX}
.if ${PORT_OPTIONS:MGKRELLM_CLIENT}
PLIST_SUB+=	CLIENT=""
.if ${PORT_OPTIONS:MNLS}
PLIST_SUB+=	NLS=""
.else
PLIST_SUB+=	NLS="@comment "
.endif
.else
PLIST_SUB+=	CLIENT="@comment " NLS="@comment "
.endif

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	COPYRIGHT CREDITS README Themes.html
.endif

ALL_TARGET=	freebsd

MAKE_ENV+=	INSTALLROOT=${STAGEDIR}${PREFIX} \
		PKGCONFIGDIR=${STAGEDIR}${PREFIX}/libdata/pkgconfig \
		SINSTALLDIR=${STAGEDIR}${PREFIX}/sbin \
		MANDIR=${STAGEDIR}${MAN1PREFIX}/man/man1 \
		SMANDIR=${STAGEDIR}${MANPREFIX}/man/man8 \
		VERSION=${PORTVERSION}

CFLAGS+=	-DSYSTEM_THEMES_DIR='\"${LOCALBASE}/share/gkrellm2/themes\"' \
		-DSYSTEM_PLUGINS_DIR='\"${LOCALBASE}/libexec/gkrellm2/plugins\"' \
		-DGKRELLMD_SYS_ETC='\"${PREFIX}/etc\"' \
		-DGKRELLMD_SYSTEM_PLUGINS_DIR='\"${PREFIX}/libexec/gkrellm2/plugins-gkrellmd\"'

post-patch:
	@${REINPLACE_CMD} -e 's/gthread-2.0/gmodule-2.0 gthread-2.0/g' \
			  ${WRKSRC}/src/Makefile

post-install:
.if ${PORT_OPTIONS:MGKRELLM_CLIENT}
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/gkrellm2/plugins
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/gkrellm2/themes
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins-gkrellmd
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf \
		${STAGEDIR}${EXAMPLESDIR}/gkrellmd.conf
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
