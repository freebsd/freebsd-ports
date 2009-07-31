# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	2.3.2
PORTREVISION=	2
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A GTK based system monitor

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_RC_SUBR=	gkrellmd.sh
WANT_GNOME=	yes
USE_OPENSSL=	yes		# cannot set after bsd.port.pre.mk

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

OPTIONS=	GKRELLM_CLIENT	"Enable GKrellM Client"			on  \
		GNUTLS		"Use GnuTLS"				off \
		NLS		"Enable NLS support"			on  \
		NTLM		"Enable NTLM support"			on  \
		OPENSSL		"Use OpenSSL"				on

.include <bsd.port.pre.mk>

.if defined(WITH_GKRELLM_CLIENT)
CONFLICTS=	gkrellm-1.*
.endif

.if defined(WITH_GNUTLS) && defined(WITH_OPENSSL)
BROKEN=		GnuTLS and OpenSSL is mutually exclusive.
.endif

.if !defined(WITH_GKRELLM_CLIENT)
BUILD_WRKSRC=	${WRKSRC}/server
INSTALL_WRKSRC=	${WRKSRC}/server
USE_GNOME=	glib20
.else
USE_GNOME=	gtk20
.if defined(WITHOUT_NLS)
MAKE_ENV+=	enable_nls=0
.else
USE_GETTEXT=	yes
.endif
USE_XORG=	x11 sm
.if defined(WITH_GNUTLS)
LIB_DEPENDS+=	gnutls-openssl.26:${PORTSDIR}/security/gnutls
MAKE_ENV+=	GNUTLSINC=${LOCALBASE}/include GNUTLSLIB=${LOCALBASE}/lib \
		without-ssl=1
.elif defined(WITH_OPENSSL)
USE_OPENSSL=	yes
MAKE_ENV+=	without-gnutls=1
.else
MAKE_ENV+=	without-gnutls=1 without-ssl=1
.endif
.endif
.if defined(WITH_NTLM)
LIB_DEPENDS+=	ntlm.0:${PORTSDIR}/security/libntlm
.else
MAKE_ENV+=	without-ntlm=1
.endif

PLIST_SUB=	PREFIX=${PREFIX}
.if !defined(WITH_GKRELLM_CLIENT)
PLIST_SUB+=	CLIENT="@comment " NLS="@comment "
.else
PLIST_SUB+=	CLIENT=""
.if defined(WITHOUT_NLS)
PLIST_SUB+=	NLS="@comment "
.else
PLIST_SUB+=	NLS=""
.endif
#MAN1=		gkrellm.1
.endif
MAN8=		gkrellmd.8

.if !defined(NOPORTDOCS)
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
.if defined(WITH_GKRELLM_CLIENT)
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
