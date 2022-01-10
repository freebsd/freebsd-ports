# Created by: Mykola Dzham <i@levsha.me>

PORTNAME=	pdsh
PORTVERSION=	2.34
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	i@levsha.me
COMMENT=	Parallel Distributed Shell

LICENSE=	GPLv2

GNU_CONFIGURE=	yes
# :keepla because port uses lt_dlopen
USES=		autoreconf gmake libtool:keepla perl5 shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	chaos
USE_PERL5=	run

CONFLICTS_INSTALL=	clusterit # bin/dshbak

SHEBANG_FILES=	scripts/dshbak
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=		SSH DSHGROUPS NETGROUP READLINE RSH
OPTIONS_DEFAULT=	SSH DSHGROUPS
OPTIONS_SUB=		yes
DSHGROUPS_DESC=		DSH groups support
DSHGROUPS_CONFIGURE_WITH=	dshgroups
NETGROUP_DESC=		NIS Netgroup support
NETGROUP_CONFIGURE_WITH=netgroup
READLINE_CONFIGURE_WITH=readline
READLINE_USES=		readline
RSH_DESC=		RSH support
RSH_CONFIGURE_WITH=	rsh
SSH_CONFIGURE_WITH=	ssh

post-patch:
	@${REINPLACE_CMD} -e 's,m4_esyscmd.*,[${PORTVERSION}]),' \
		${WRKSRC}/configure.ac

.include <bsd.port.mk>
