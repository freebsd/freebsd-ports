# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	pdsh
PORTVERSION=	2.28
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	i@levsha.me
COMMENT=	Parallel Distributed Shell

LICENSE=	GPLv2

USES=		perl5
USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5=	build

OPTIONS_DEFINE=		SSH DSHGROUPS NETGROUP READLINE RSH
OPTIONS_DEFAULT=	SSH DSHGROUPS
DSHGROUPS_DESC=		DSH groups supprt
NETGROUP_DESC=		NIS Netgroup support
RSH_DESC=		RSH support

NO_STAGE=	yes
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
LIB_DEPENDS+=		readline:${PORTSDIR}/devel/readline
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

MAN1=		dshbak.1 pdcp.1 pdsh.1
MLINKS=		pdcp.1 rpdcp.1

.include <bsd.port.mk>
