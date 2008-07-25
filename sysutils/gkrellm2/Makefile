# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	2.3.1
PORTREVISION=	5
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A GTK based system monitor

.if !defined(GKRELLM_SERVER_ONLY)
CONFLICTS=	gkrellm-1.*
.endif

USE_RC_SUBR=	gkrellmd.sh

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

.if defined(WITH_GNUTLS) && defined(WITH_OPENSSL)
BROKEN=		GnuTLS and OpenSSL is mutually exclusive.
.endif

.if !defined(WITH_OPENSSL) && !defined(WITH_GNUTLS) && !defined(WITHOUT_GNUTLS)
WITH_GNUTLS=	yes
.endif

.if defined(GKRELLM_SERVER_ONLY)
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

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_SUB=	PREFIX=${PREFIX}
.if defined(GKRELLM_SERVER_ONLY)
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

.include <bsd.port.pre.mk>

ALL_TARGET=	freebsd
.if ${OSVERSION} < 500000
INSTALL_TARGET=	install_freebsd
.endif

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

pre-everything::
.if !defined(GKRELLM_SERVER_ONLY)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use GKRELLM_SERVER_ONLY=yes to build gkrellmd only."
	@${ECHO_MSG} ""
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/INCLUDEDIR/SINCLUDEDIR/g' \
			  -e 's/INSTALLROOT/SINSTALLROOT/g' \
			  -e 's/PKGCONFIGDIR/SPKGCONFIGDIR/g' \
			  ${WRKSRC}/server/Makefile

post-install:
.if !defined(GKRELLM_SERVER_ONLY)
	@${MKDIR} ${LOCALBASE}/libexec/gkrellm2/plugins
	@${MKDIR} ${LOCALBASE}/share/gkrellm2/themes
	@${GZIP_CMD} ${MAN1PREFIX}/man/man1/gkrellm.1
.if ${OSVERSION} < 500000
	@${CHMOD} 2511 ${LOCALBASE}/bin/gkrellm
.endif
.endif
.if ${OSVERSION} < 500000
	@${CHMOD} 2511 ${PREFIX}/sbin/gkrellmd
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
