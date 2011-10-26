# New ports collection makefile for:	sysutils/pdsh
# Date created:		2010-03-09
# Whom:			Mykola Dzham <i@levsha.me>
#
# $FreeBSD$
#

PORTNAME=	pdsh
PORTVERSION=	2.27
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	i@levsha.me
COMMENT=	Parallel Distributed Shell

LICENSE=	GPLv2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_PERL5_BUILD=yes

OPTIONS=	SSH		"Enable SSH support" On \
		DSHGROUPS	"Enable DSH groups" On \
		NETGROUP	"Enable NIS Netgroup support" Off \
		READLINE	"Enable GNU readline support" Off \
		RSH		"Enable RSH support" Off

.include <bsd.port.options.mk>

.if defined(WITH_SSH)
CONFIGURE_ARGS+=	--with-ssh
PLIST_SUB+=		SSH=""
.else
CONFIGURE_ARGS+=	--without-ssh
PLIST_SUB+=		SSH="@comment "
.endif

.if defined(WITH_DSHGROUPS)
CONFIGURE_ARGS+=	--with-dshgroups
PLIST_SUB+=		DSH=""
.else
CONFIGURE_ARGS+=	--without-dshgroups
PLIST_SUB+=		DSH="@comment "
.endif

.if defined(WITH_NETGROUP)
CONFIGURE_ARGS+=	--with-netgroup
PLIST_SUB+=		NETGROUP=""
.else
CONFIGURE_ARGS+=	--without-netgroup
PLIST_SUB+=		NETGROUP="@comment "
.endif

.if defined(WITH_READLINE)
CONFIGURE_ARGS+=	--with-readline
LIB_DEPENDS+=		readline:${PORTSDIR}/devel/readline
.else
CONFIGURE_ARGS+=	--without-readline
.endif

.if defined(WITH_RSH)
CONFIGURE_ARGS+=	--with-rsh
PLIST_SUB+=		RSH=""
.else
CONFIGURE_ARGS+=	--without-rsh
PLIST_SUB+=		RSH="@comment "
.endif

MAN1=		dshbak.1 pdcp.1 pdsh.1
MLINKS=		pdcp.1 rpdcp.1

.include <bsd.port.mk>
