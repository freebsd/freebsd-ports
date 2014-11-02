# Created by: Mykola Dzham <i@levsha.me>
# $FreeBSD$

PORTNAME=	pdsh
PORTVERSION=	2.29
CATEGORIES=	sysutils
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	i@levsha.me
COMMENT=	Parallel Distributed Shell

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
# :keepla because port uses lt_dlopen
USES=		libtool:keepla perl5 shebangfix tar:bzip2
USE_PERL5=	build
SHEBANG_FILES=	scripts/dshbak

OPTIONS_DEFINE=		SSH DSHGROUPS NETGROUP READLINE RSH
OPTIONS_DEFAULT=	SSH DSHGROUPS
OPTIONS_SUB=		yes
DSHGROUPS_DESC=		DSH groups supprt
DSHGROUPS_CONFIGURE_WITH=	dshgroups
NETGROUP_DESC=		NIS Netgroup support
NETGROUP_CONFIGURE_WITH=netgroup
READLINE_CONFIGURE_WITH=readline
READLINE_LIB_DEPENDS=	libreadline.so.6:${PORTSDIR}/devel/readline
RSH_DESC=		RSH support
RSH_CONFIGURE_WITH=	rsh
SSH_CONFIGURE_WITH=	ssh

.include <bsd.port.mk>
