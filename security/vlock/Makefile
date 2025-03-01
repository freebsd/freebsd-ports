PORTNAME=	vlock
PORTVERSION=	2.2.3
PORTREVISION=	5
CATEGORIES=	security
MASTER_SITES=	LOCAL/martymac

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Locks a terminal
WWW=		http://freshmeat.net/projects/vlock

LICENSE=	GPLv2

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-plugins --enable-pam \
		--prefix=${PREFIX} \
		--mandir=${PREFIX}/share/man \
		--with-modules="all.so new.so" \
		--with-scripts="${VLOCKSCRIPTS}" \
		VLOCK_GROUP="nobody"
USES=	gmake
USE_CSTD=	gnu99

OPTIONS_DEFINE=	ROOTPWD VLOCKSCRIPTS DOCS
OPTIONS_DEFAULT=	ROOTPWD
OPTIONS_SUB=	yes
ROOTPWD_DESC=	Enable unlock using root password
ROOTPWD_CONFIGURE_ENABLE=	root-password
VLOCKSCRIPTS_DESC=	Install sample hook scripts

# Default scripts/modules
VLOCKSCRIPTS=

# Vlock special group
VLOCK_GRP=	vlock
GROUPS=	${VLOCK_GRP}
PLIST_SUB+=	VLOCK_GRP=${VLOCK_GRP}

PORTDOCS=	ChangeLog PLUGINS README README.X11 SECURITY TODO

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MVLOCKSCRIPTS}
VLOCKSCRIPTS+=	amarok.sh example_script.sh mplayer.sh
.endif

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
