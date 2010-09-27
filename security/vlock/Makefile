# New ports collection makefile for:	vlock
# Date created:		08 Oct 2000
# Whom:			George Reid <services@nevernet.net>
#
# $FreeBSD$
#

PORTNAME=	vlock
PORTVERSION=	2.2.2
CATEGORIES=	security
MASTER_SITES=	http://cthulhu.c3d2.de/~toidinamai/vlock/archive/

MAINTAINER=	martymac@FreeBSD.org
COMMENT=	Locks a terminal

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-plugins --enable-pam \
		--prefix=${PREFIX} \
		--mandir=${MANPREFIX}/man \
		--with-modules="${VLOCKMODULES}" \
		--with-scripts="${VLOCKSCRIPTS}" \
		VLOCK_GROUP="${VLOCKGRP}" \
		VLOCK_MODE="0750" \
		EXTRA_CFLAGS="-I${LOCALBASE}/include" \
		EXTRA_LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	ROOTPWD "Enable unlock using root password" on \
		VLOCKSCRIPTS "Install sample hook scripts" off \
		CACASAVER "Enable libcaca screensaver" off

MANLANG=	""
MAN1=		vlock.1
MAN5=		vlock-plugins.5
MAN8=		vlock-main.8

# Default scripts/modules
VLOCKSCRIPTS=
VLOCKMODULES=	all.so new.so

# Vlock group = vlock:*:129:
VLOCKGRP=	vlock
VLOCKGID=	129

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_ROOTPWD)
CONFIGURE_ARGS+=	--enable-root-password
.else
CONFIGURE_ARGS+=	--disable-root-password
.endif

.if !defined(WITHOUT_VLOCKSCRIPTS)
VLOCKSCRIPTS+=	amarok.sh example_script.sh mplayer.sh
PLIST_SUB+=	PL_VLOCKSCRIPTS=""
.else
PLIST_SUB+=	PL_VLOCKSCRIPTS="@comment "
.endif

.if !defined(WITHOUT_CACASAVER)
BUILD_DEPENDS+=	${LOCALBASE}/lib/libcaca.a:${PORTSDIR}/graphics/libcaca
VLOCKMODULES+=	caca.so
PLIST_SUB+=	PL_CACASAVER=""
.else
PLIST_SUB+=	PL_CACASAVER="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lncurses|-lm|' ${WRKSRC}/modules/Makefile

pre-install:
	if ! pw groupshow ${VLOCKGRP}; then pw groupadd ${VLOCKGRP} -g ${VLOCKGID}; fi

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/PLUGINS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.X11 ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/SECURITY ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
