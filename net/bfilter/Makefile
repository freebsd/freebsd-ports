# New ports collection makefile for:	bfilter
# Date created:				10.05.2003
# Whom:					Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	bfilter
PORTVERSION=	0.9.4
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Smart filtering HTTP proxy

LIB_DEPENDS=	popt.0:${PORTSDIR}/devel/popt \
		tre.5:${PORTSDIR}/textproc/libtre \
		sigc-1.2.5:${PORTSDIR}/devel/libsigc++12

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_RC_SUBR=	yes

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if defined(WITH_GUI)
USE_GNOME=	gtk20 pkgconfig
LIB_DEPENDS+=	gtkmm-2.0:${PORTSDIR}/x11-toolkits/gtk--2
CONFIGURE_ARGS+=	--with-gui
PLIST_SUB+=	WITH_GUI=""
.else
PLIST_SUB+=	WITH_GUI="@comment "
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/main/bfilter ${PREFIX}/bin
.if defined(WITH_GUI)
	${INSTALL_PROGRAM} ${WRKSRC}/main/gui/gtk/bfilter-gui ${PREFIX}/bin
.endif
	${MKDIR} ${PREFIX}/etc/bfilter
	${INSTALL_DATA} ${WRKSRC}/conf/config.default \
		${PREFIX}/etc/bfilter/config.default
	${INSTALL_DATA} ${WRKSRC}/conf/rules \
		${PREFIX}/etc/bfilter/rules.sample
	${INSTALL_DATA} ${WRKSRC}/conf/rules.local \
		${PREFIX}/etc/bfilter/rules.local.sample

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/bfilter.sh ${PREFIX}/etc/rc.d
	@${ECHO_MSG} "-----------------------------------------------"
	@${ECHO_MSG} "Add bfilter_enable=\"YES\" to /etc/rc.conf to"
	@${ECHO_MSG} "enable bfilter."
	@${ECHO_MSG} "-----------------------------------------------"
	@${ECHO_MSG} "Sample configuration files placed in"
	@${ECHO_MSG} "${PREFIX}/etc/bfilter/config.default"
	@${ECHO_MSG} "${PREFIX}/etc/bfilter/rules.sample"
	@${ECHO_MSG} "${PREFIX}/etc/bfilter/rules.local.sample"
	@${ECHO_MSG} "-----------------------------------------------"
	@[ -f ${PREFIX}/etc/bfilter/config ] || \
	${CP} ${PREFIX}/etc/bfilter/config.default ${PREFIX}/etc/bfilter/config
	@[ -f ${PREFIX}/etc/bfilter/rules ] || \
	${CP} ${PREFIX}/etc/bfilter/rules.sample ${PREFIX}/etc/bfilter/rules
	@[ -f ${PREFIX}/etc/bfilter/rules.local ] || \
	${CP} ${PREFIX}/etc/bfilter/rules.local.sample ${PREFIX}/etc/bfilter/rules.local

.include <bsd.port.mk>
