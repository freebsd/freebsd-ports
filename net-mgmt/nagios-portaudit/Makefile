# New ports collection makefile for:	nagios-portaudit
# Date created:				19 August 2008
# Whom:					rea-fbsd@codelabs.ru
#
# $FreeBSD$
#

PORTNAME=	portaudit
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://codelabs.ru/fbsd/distfiles/ \
		http://fbsd.inse.ru/distfiles/
PKGNAMEPREFIX=	nagios-
DISTNAME=	check_portaudit-${PORTVERSION}

MAINTAINER=	rea-fbsd@codelabs.ru
COMMENT=	Nagios plug-in to get portaudit/portupgrade status

OPTIONS=	PORTAUDIT "Enable portaudit check" ON \
		PORTUPGRADE "Enable portupgrade check" ON \
		PORTUPGRADE_DEVEL "Use portupgrade-devel" OFF

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

.include <bsd.port.pre.mk>

.if !defined(WITH_PORTUPGRADE) && !defined(WITH_PORTAUDIT) && !defined(WITH_PORTAUDIT_DEVEL)
IGNORE=		unusable without portupgrade and portaudit
.endif

.if defined(WITH_PORTUPGRADE) && defined(WITH_PORTUPGRADE_DEVEL)
IGNORE=		choose either portupgrade or portupgrade-devel, not both
.endif

.if defined(WITH_PORTAUDIT)
RUN_DEPENDS+=	portaudit:${PORTSDIR}/ports-mgmt/portaudit
.endif

.if defined(WITH_PORTUPGRADE)
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade
.endif

.if defined(WITH_PORTUPGRADE_DEVEL)
RUN_DEPENDS+=	portupgrade:${PORTSDIR}/ports-mgmt/portupgrade-devel
.endif

do-install:
	@${MKDIR} ${PREFIX}/libexec/nagios
	${INSTALL_SCRIPT} ${WRKSRC}/check_portaudit ${PREFIX}/libexec/nagios

.include <bsd.port.post.mk>
