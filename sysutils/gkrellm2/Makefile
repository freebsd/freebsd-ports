# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	2.2.5
#PORTREVISION=	0
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://members.dslextreme.com/users/billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org
COMMENT=	A GTK based system monitor

.if !defined(GKRELLM_SERVER_ONLY)
CONFLICTS=	gkrellm-1.*
.endif

LATEST_LINK=	${PORTNAME}2

USE_RC_SUBR=	gkrellmd.sh

WRKSRC=		${WRKDIR}/${DISTNAME:C/[a-z]$//}

.if defined(GKRELLM_SERVER_ONLY)
BUILD_WRKSRC=	${WRKSRC}/server
INSTALL_WRKSRC=	${WRKSRC}/server
USE_GNOME=	glib12
.else
USE_GNOME=	gtk20
USE_GETTEXT=	yes
USE_XLIB=	yes
USE_OPENSSL=	yes
.endif

USE_BZIP2=	yes
USE_GMAKE=	yes

PLIST_SUB=	PREFIX=${PREFIX}
.if defined(GKRELLM_SERVER_ONLY)
PLIST_SUB+=	CLIENT="@comment "
.else
PLIST_SUB+=	CLIENT=""
#MAN1=		gkrellm.1
.endif
MAN8=		gkrellmd.8

.if !defined(NOPORTDOCS)
PORTDOCS=	COPYRIGHT CREDITS README Themes.html
.endif

MAN1PREFIX=	${X11BASE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
ALL_TARGET=	freebsd2
.else
ALL_TARGET=	freebsd
.endif
INSTALL_TARGET=	install_freebsd

MAKE_ENV+=	INSTALLROOT=${X11BASE} SINSTALLDIR=${PREFIX}/sbin \
		PKGCONFIGDIR=${X11BASE}/libdata/pkgconfig \
		MANDIR=${MAN1PREFIX}/man/man1 SMANDIR=${MANPREFIX}/man/man8
.if defined(GKRELLM_SERVER_ONLY)
MAKE_ENV+=	glib12=1
.endif

CFLAGS+=	-DSYSTEM_THEMES_DIR='\"${X11BASE}/share/gkrellm2/themes\"' \
		-DSYSTEM_PLUGINS_DIR='\"${X11BASE}/libexec/gkrellm2/plugins\"' \
		-DGKRELLMD_SYS_ETC='\"${PREFIX}/etc\"' \
		-DGKRELLMD_SYSTEM_PLUGINS_DIR='\"${PREFIX}/libexec/gkrellm2/plugins-gkrellmd\"'

pre-everything::
.if !defined(GKRELLM_SERVER_ONLY)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use GKRELLM_SERVER_ONLY=yes to build gkrellmd only."
	@${ECHO_MSG} ""
.endif

post-install:
.if !defined(GKRELLM_SERVER_ONLY)
	@${MKDIR} ${X11BASE}/libexec/gkrellm2/plugins
	@${MKDIR} ${X11BASE}/share/gkrellm2/themes
	@${GZIP_CMD} ${MAN1PREFIX}/man/man1/gkrellm.1
	@${CHMOD} 2511 ${X11BASE}/bin/gkrellm
.endif
	@${CHMOD} 2511 ${PREFIX}/sbin/gkrellmd
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
