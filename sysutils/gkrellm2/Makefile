# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	2.3.5
PORTREVISION=	3
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A GTK based system monitor

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	gkrellmd
WANT_GNOME=	yes
USE_OPENSSL=	yes		# cannot set after bsd.port.pre.mk

OPTIONS_DEFINE=		GKRELLM_CLIENT NLS NTLM SSL
OPTIONS_SINGLE=		SSL
OPTIONS_SINGLE_SSL=	GNUTLS OPENSSL
OPTIONS_DEFAULT=	GKRELLM_CLIENT NLS NTLM SSL OPENSSL
GKRELLM_CLIENT_DESC=	Enable GKrellM Client

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGKRELLM_CLIENT}
CONFLICTS=	gkrellm-1.*
USE_GNOME=	gtk20
.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
.else
MAKE_ENV+=	enable_nls=0
.endif
USE_XORG=	x11 sm
.if ${PORT_OPTIONS:MSSL}
.if ${PORT_OPTIONS:MGNUTLS}
LIB_DEPENDS+=	gnutls-openssl.27:${PORTSDIR}/security/gnutls
MAKE_ENV+=	GNUTLSINC=${LOCALBASE}/include GNUTLSLIB=${LOCALBASE}/lib \
		without-ssl=1
.elif ${PORT_OPTIONS:MOPENSSL}
USE_OPENSSL=	yes
MAKE_ENV+=	without-gnutls=1
.endif
.else
MAKE_ENV+=	without-gnutls=1 without-ssl=1
.endif
.else
BUILD_WRKSRC=	${WRKSRC}/server
INSTALL_WRKSRC=	${WRKSRC}/server
USE_GNOME=	glib20
.endif

.if ${PORT_OPTIONS:MNTLM}
LIB_DEPENDS+=	ntlm.0:${PORTSDIR}/security/libntlm
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
#MAN1=		gkrellm.1
.else
PLIST_SUB+=	CLIENT="@comment " NLS="@comment "
.endif
MAN8=		gkrellmd.8

.if ${PORT_OPTIONS:MDOCS}
PORTDOCS=	COPYRIGHT CREDITS README Themes.html
.endif

ALL_TARGET=	freebsd

MAKE_ENV+=	INSTALLROOT=${LOCALBASE} INSTALLDIR=${LOCALBASE}/bin \
		PKGCONFIGDIR=${LOCALBASE}/libdata/pkgconfig \
		SINSTALLROOT=${PREFIX} SINSTALLDIR=${PREFIX}/sbin \
		SPKGCONFIGDIR=${PREFIX}/libdata/pkgconfig \
		MANDIR=${MAN1PREFIX}/man/man1 SMANDIR=${MANPREFIX}/man/man8 \
		VERSION=${PORTVERSION}

CFLAGS+=	-DSYSTEM_THEMES_DIR='\"${LOCALBASE}/share/gkrellm2/themes\"' \
		-DSYSTEM_PLUGINS_DIR='\"${LOCALBASE}/libexec/gkrellm2/plugins\"' \
		-DGKRELLMD_SYS_ETC='\"${PREFIX}/etc\"' \
		-DGKRELLMD_SYSTEM_PLUGINS_DIR='\"${PREFIX}/libexec/gkrellm2/plugins-gkrellmd\"'

post-patch:
	@${REINPLACE_CMD} -e 's/INCLUDEDIR/SINCLUDEDIR/g' \
			  -e 's/INSTALLROOT/SINSTALLROOT/g' \
			  -e 's/PKGCONFIGDIR/SPKGCONFIGDIR/g' \
			  ${WRKSRC}/server/Makefile

post-install:
.if ${PORT_OPTIONS:MGKRELLM_CLIENT}
	@${MKDIR} ${LOCALBASE}/libexec/gkrellm2/plugins
	@${MKDIR} ${LOCALBASE}/share/gkrellm2/themes
	@${GZIP_CMD} ${MAN1PREFIX}/man/man1/gkrellm.1
.endif
	@${MKDIR} ${PREFIX}/libexec/gkrellm2/plugins-gkrellmd
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf \
		${EXAMPLESDIR}/gkrellmd.conf
	if [ ! -f ${PREFIX}/etc/gkrellmd.conf ]; then \
		${CP} -p ${EXAMPLESDIR}/gkrellmd.conf \
			${PREFIX}/etc/gkrellmd.conf; \
	fi
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
