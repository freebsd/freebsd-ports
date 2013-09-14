# Created by: rea-fbsd@codelabs.ru
# $FreeBSD$

PORTNAME=	portaudit
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://codelabs.ru/fbsd/distfiles/ \
		http://fbsd.inse.ru/distfiles/
PKGNAMEPREFIX=	nagios-
DISTNAME=	check_portaudit-${PORTVERSION}

MAINTAINER=	rea@FreeBSD.org
COMMENT=	Nagios plug-in to get portaudit/portupgrade status

OPTIONS_DEFINE=	PORTAUDIT PORTUPGRADE PORTUPGRADE_DEVEL
OPTIONS_DEFAULT=	PORTAUDIT PORTUPGRADE
PORTAUDIT_DESC=		Enable portaudit check
PORTUPGRADE_DESC=	Enable portupgrade check
PORTUPGRADE_DEVEL_DESC=	Use portupgrade-devel

USES=		perl5
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if ! ${PORT_OPTIONS:MPORTUPGRADE} && ! ${PORT_OPTIONS:MPORTAUDIT} && ! ${PORT_OPTIONS:MPORTAUDIT_DEVEL}
IGNORE=		unusable without portupgrade and portaudit
.endif

.if ${PORT_OPTIONS:MPORTUPGRADE} && ${PORT_OPTIONS:MPORTUPGRADE_DEVEL}
IGNORE=		choose either portupgrade or portupgrade-devel, not both
.endif

.if ${PORT_OPTIONS:MPORTAUDIT}
RUN_DEPENDS+=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

.if ${PORT_OPTIONS:MPORTUPGRADE}
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
.endif

.if ${PORT_OPTIONS:MPORTUPGRADE_DEVEL}
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade-devel
.endif

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_portaudit ${PREFIX}/libexec/nagios

.include <bsd.port.post.mk>
