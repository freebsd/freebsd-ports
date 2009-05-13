# Ports collection makefile for:	miredo
# Date created:				2006-08-12
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		miredo
PORTVERSION=	 	1.1.6
CATEGORIES=		net ipv6
MASTER_SITES=		http://www.remlab.net/files/miredo/archive/

MAINTAINER=		sumikawa@FreeBSD.org
COMMENT=		Opensource Teredo (IPv6 tunneling) implementation

LIB_DEPENDS=		Judy.1:${PORTSDIR}/devel/judy

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
USE_LDCONFIG=		yes

MAN1=			teredo-mire.1
MAN5=			miredo-server.conf.5 miredo.conf.5 isatapd.conf.5
MAN8=			miredo-server.8 miredo.8 isatapd.8 miredo-checkconf.8
USE_RC_SUBR=		miredo_server miredo isatapd

.if !defined(WITHOUT_NLS)
USE_GETTEXT=		yes
USE_ICONV=		yes
CONFIGURE_ENV+=		CPPFLAGS="-I${LOCALBASE}/include" \
			CFLAGS="${PTHREAD_CFLAGS}" \
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ENV+=		LDFLAGS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == sparc64
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
