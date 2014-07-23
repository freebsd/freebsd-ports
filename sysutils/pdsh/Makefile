# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	pdsh
PORTVERSION=	2.28
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	i@levsha.me
COMMENT=	Parallel Distributed Shell

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
# :keepla because port uses lt_dlopen
USES=		libtool:keepla perl5 tar:bzip2
USE_PERL5=	build

OPTIONS_DEFINE=		SSH DSHGROUPS NETGROUP READLINE RSH
OPTIONS_DEFAULT=	SSH DSHGROUPS
DSHGROUPS_DESC=		DSH groups supprt
NETGROUP_DESC=		NIS Netgroup support
RSH_DESC=		RSH support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSSH}
CONFIGURE_ARGS+=	--with-ssh
PLIST_SUB+=		SSH=""
.else
CONFIGURE_ARGS+=	--without-ssh
PLIST_SUB+=		SSH="@comment "
.endif

.if ${PORT_OPTIONS:MDSHGROUPS}
CONFIGURE_ARGS+=	--with-dshgroups
PLIST_SUB+=		DSH=""
.else
CONFIGURE_ARGS+=	--without-dshgroups
PLIST_SUB+=		DSH="@comment "
.endif

.if ${PORT_OPTIONS:MNETGROUP}
CONFIGURE_ARGS+=	--with-netgroup
PLIST_SUB+=		NETGROUP=""
.else
CONFIGURE_ARGS+=	--without-netgroup
PLIST_SUB+=		NETGROUP="@comment "
.endif

.if ${PORT_OPTIONS:MREADLINE}
CONFIGURE_ARGS+=	--with-readline
LIB_DEPENDS+=		libreadline.so.6:${PORTSDIR}/devel/readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if ${PORT_OPTIONS:MRSH}
CONFIGURE_ARGS+=	--with-rsh
PLIST_SUB+=		RSH=""
.else
CONFIGURE_ARGS+=	--without-rsh
PLIST_SUB+=		RSH="@comment "
.endif

.include <bsd.port.mk>
