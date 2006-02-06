# New ports collection makefile for:	security/p5-Authen-Libwrap
# Date created:				05 February 2006
# Whom:					Zach Thompson <hideo@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	Authen-Libwrap
PORTVERSION=	0.20
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Authen
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Authen::Libwrap - access to TCP Wrappers library

BUILD_DEPENDS=	${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Authen::Libwrap.3

.include <bsd.port.mk>
