# New ports collection makefile for:	gkrellm
# Date Created:		Mar 4 2000
# Whom:			Hajimu UMEMOTO <ume@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gkrellm
PORTVERSION=	2.1.4
PORTREVISION=	1
CATEGORIES=	sysutils ipv6
MASTER_SITES=	http://web.wt.net/~billw/gkrellm/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	ume

MAINTAINER=	ume@FreeBSD.org

.if defined(GKRELLM_SERVER_ONLY)
BUILD_WRKSRC=	${WRKSRC}/server
INSTALL_WRKSRC=	${WRKSRC}/server
USE_GNOMENG=	yes
USE_GNOME=	glib12
.else
LIB_DEPENDS=	gtk-x11-2.0.0:${PORTSDIR}/x11-toolkits/gtk20
USE_XLIB=	yes
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
DOCS=		COPYRIGHT CREDITS README Themes.html

MAN1PREFIX=	${X11BASE}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 300000
ALL_TARGET=	freebsd2
.else
ALL_TARGET=	freebsd
.endif
INSTALL_TARGET=	install_netbsd

MAKE_ENV+=	LOCALEDIR=${X11BASE}/share/locale \
		INCLUDEDIR=${X11BASE}/include \
		INSTALLDIR=${X11BASE}/bin SINSTALLDIR=${PREFIX}/sbin \
		MANDIR=${MAN1PREFIX}/man/man1 SMANDIR=${MANPREFIX}/man/man8
.if defined(GKRELLM_SERVER_ONLY)
MAKE_ENV+=	glib12=1
.endif

CFLAGS+=	-DSYSTEM_THEMES_DIR='\"${X11BASE}/share/gkrellm2/themes\"' \
		-DSYSTEM_PLUGINS_DIR='\"${X11BASE}/libexec/gkrellm2/plugins\"' \
		-DGKRELLMD_SYS_ETC='\"${PREFIX}/etc\"'

pre-everything:
.if !defined(GKRELLM_SERVER_ONLY)
	@${ECHO} ""
	@${ECHO} "You may use GKRELLM_SERVER_ONLY=yes to build gkrellmd only."
	@${ECHO} ""
.endif

post-install:
.if !defined(GKRELLM_SERVER_ONLY)
	@${MKDIR} ${X11BASE}/libexec/gkrellm2/plugins
	@${MKDIR} ${X11BASE}/share/gkrellm2/themes
	@${GZIP_CMD} ${MAN1PREFIX}/man/man1/gkrellm.1
.endif
	@${SED} -e "s;%%PREFIX%%;${PREFIX};g" \
		${FILESDIR}/gkrellmd.sh > ${PREFIX}/etc/rc.d/gkrellmd.sh.sample
	@${CHMOD} ${BINMODE} ${PREFIX}/etc/rc.d/gkrellmd.sh.sample
	${INSTALL_DATA} ${WRKSRC}/server/gkrellmd.conf \
		${PREFIX}/etc/gkrellmd.conf.sample
	if [ ! -f ${PREFIX}/etc/gkrellmd.conf ]; then \
		${CP} -p ${PREFIX}/etc/gkrellmd.conf.sample \
			${PREFIX}/etc/gkrellmd.conf; \
	fi
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
