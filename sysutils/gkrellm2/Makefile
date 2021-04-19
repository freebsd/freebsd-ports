PORTNAME=	gkrellm
PORTVERSION=	2.3.11
PORTREVISION=	0
CATEGORIES=	sysutils
MASTER_SITES=	http://gkrellm.srcbox.net/releases/ \
		LOCAL/ume
PKGNAMESUFFIX=	2

MAINTAINER=	ume@FreeBSD.org
COMMENT=	GTK based system monitor

LICENSE=	GPLv3

USES=		gmake gnome pkgconfig tar:bzip2
USE_RC_SUBR=	gkrellmd

OPTIONS_DEFINE=		DOCS CLIENT NLS NTLM OPENSSL
OPTIONS_DEFAULT=	CLIENT NTLM OPENSSL
OPTIONS_SUB=		yes

CLIENT_DESC=		GKrellM Client
CLIENT_CONFLICTS=	gkrellm-[^2].* gkrellm[^2]-[^2].*
CLIENT_USES=		xorg
CLIENT_USE=		GNOME=gtk20 XORG=sm,x11
CLIENT_USE_OFF=		GNOME=glib20
CLIENT_VARS_OFF=	BUILD_WRKSRC=${WRKSRC}/server \
			INSTALL_WRKSRC=${WRKSRC}/server
NTLM_LIB_DEPENDS=	libntlm.so:security/libntlm
NTLM_VARS_OFF=		MAKE_ENV+=without-ntlm=1

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCLIENT}
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
.else
MAKE_ENV+=	enable_nls=0
.endif
.if ${PORT_OPTIONS:MOPENSSL}
USES+=		ssl
MAKE_ENV+=	without-gnutls=1
.else
MAKE_ENV+=	without-gnutls=1 without-ssl=1
.endif
.endif

PORTDOCS=	COPYRIGHT CREDITS README Themes.html

ALL_TARGET=	freebsd

MAKE_ENV+=	INSTALLROOT=${PREFIX} INSTALL_PREFIX=${STAGEDIR} \
		PKGCONFIGDIR=${PREFIX}/libdata/pkgconfig \
		SINSTALLDIR=${PREFIX}/sbin \
		MANDIR=${MAN1PREFIX}/man/man1 SMANDIR=${MANPREFIX}/man/man8 \
		VERSION=${PORTVERSION}

CFLAGS+=	-DSYSTEM_THEMES_DIR='\"${LOCALBASE}/share/gkrellm2/themes\"' \
		-DSYSTEM_PLUGINS_DIR='\"${LOCALBASE}/libexec/gkrellm2/plugins\"' \
		-DGKRELLMD_SYS_ETC='\"${PREFIX}/etc\"' \
		-DGKRELLMD_SYSTEM_PLUGINS_DIR='\"${PREFIX}/libexec/gkrellm2/plugins-gkrellmd\"'

post-patch:
	@${REINPLACE_CMD} -e 's/gthread-2.0/gmodule-2.0 gthread-2.0/g' \
			  ${WRKSRC}/src/Makefile

post-install-CLIENT-on:
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/libexec/gkrellm2/plugins
	@${MKDIR} ${STAGEDIR}${LOCALBASE}/share/gkrellm2/themes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/gkrellm2/plugins-gkrellmd
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf \
		${STAGEDIR}${EXAMPLESDIR}/gkrellmd.conf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
