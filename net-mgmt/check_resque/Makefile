# New ports collection makefile for:	check_resque
# Date created:		2011-02-16
# Whom:			Tomoyuki Sakurai <tomoyukis@reallyenglish.com>
#
# $FreeBSD$
#

PORTNAME=	check_resque
PORTVERSION=	1.1
CATEGORIES=	net-mgmt

MAINTAINER=	tomoyukis@reallyenglish.com
COMMENT=	Nagios/Icinga plugins for resque

RUN_DEPENDS=	${SITE_PERL}/Nagios/Plugin.pm:${PORTSDIR}/net-mgmt/p5-Nagios-Plugin \
	${SITE_PERL}/Redis.pm:${PORTSDIR}/databases/p5-Redis

USE_GITHUB=	Yes
GH_ACCOUNT=	trombik
GH_PROJECT=	check_resque
GH_TAGNAME=	master
GH_COMMIT=	a0b6c3b
USE_PERL5=	Yes

MAKE_ARGS=	DESTDIR=${PREFIX}
LICENSE=	BSD

.include <bsd.port.mk>
