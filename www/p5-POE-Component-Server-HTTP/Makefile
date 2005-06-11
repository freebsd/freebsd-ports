# New ports collection makefile for:	POE-Component-Server-HTTP
# Date created:		03 Apr 2004
# Whom:			Zach Thompson <lin-chi@lastamericanempire.com>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-HTTP
PORTVERSION=	0.07
PORTREVISION=	1
CATEGORIES=	www devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	POE Component to create HTTP Servers

BUILD_DEPENDS=	${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/POE/API/Peek.pm:${PORTSDIR}/devel/p5-POE-API-Peek \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/YAML.pm:${PORTSDIR}/textproc/p5-YAML \
		${SITE_PERL}/HTTP/Status.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::HTTP.3

.include <bsd.port.mk>
