# Created by: Andreas Kohn <andreas@syndrom23.de>
# $FreeBSD$

PORTNAME=		miredo
PORTVERSION=	 	1.2.5
PORTREVISION=		2
CATEGORIES=		net ipv6
MASTER_SITES=		http://www.remlab.net/files/miredo/archive/

MAINTAINER=		sumikawa@FreeBSD.org
COMMENT=		Opensource Teredo (IPv6 tunneling) implementation

LIB_DEPENDS=		Judy.1:${PORTSDIR}/devel/judy

USE_XZ=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--localstatedir=/var --enable-examplesdir=$(EXAMPLESDIR)
USE_LDCONFIG=		yes

OPTIONS_DEFINE=	POLICYTABLE NLS
POLICYTABLE_DESC=	Install policy table to support teredo

MAN1=			teredo-mire.1
MAN5=			miredo-server.conf.5 miredo.conf.5
MAN8=			miredo-server.8 miredo.8 miredo-checkconf.8
USE_RC_SUBR=		miredo_server miredo

LDFLAGS+=		-L${LOCALBASE}/lib

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext iconv
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif


post-install:
.if ${PORT_OPTIONS:MPOLICYTABLE}
			$(INSTALL_DATA) $(FILESDIR)/ip6addrctl.conf /etc
PLIST_SUB+=		POLICYTABLE=""
.else
PLIST_SUB+=		POLICYTABLE="@comment "
.endif

.include <bsd.port.mk>
