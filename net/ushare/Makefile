# New ports collection makefile for:   ushare
# Date created:        11 December 2006
# Whom:                Volker Theile <votdev@gmx.de>
#
# $FreeBSD$
#

PORTNAME=	ushare
PORTVERSION=	1.1a
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://ushare.geexbox.org/releases/

MAINTAINER=	votdev@gmx.de
COMMENT=	A lightweight UPnP (TM) A/V Media Server

LIB_DEPENDS=	upnp.3:${PORTSDIR}/devel/upnp

HAS_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	pkgconfig
USE_GETTEXT=	yes
CONFIGURE_ENV+=	LDFLAGS="-L${LOCALBASE}/lib -lintl"

CFLAGS+=	-I${LOCALBASE}/include -I${WRKSRC}

PLIST_FILES=	bin/${PORTNAME} etc/${PORTNAME}.conf.sample etc/rc.d/${PORTNAME}
MAN1=		${PORTNAME}.1

OPTIONS=	LIBDLNA "Enable DLNA (PS3) support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LIBDLNA)
LIB_DEPENDS+=	dlna:${PORTSDIR}/devel/libdlna
CONFIGURE_ARGS=	--enable-dlna
.endif

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/src/${PORTNAME} ${PREFIX}/bin
	${CP} ${WRKSRC}/scripts/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/${PORTNAME} ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.1 ${PREFIX}/man/man1

.include <bsd.port.post.mk>
