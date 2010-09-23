# New ports collection makefile for:	sysutils/p5-BSD-Jail-Object
# Date created:		2006-08-07
# Whom:			Mahlon E. Smith <mahlon@martini.nu>
#
# $FreeBSD$
#

PORTNAME=	BSD-Jail-Object
PORTVERSION=	0.02
PORTREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	mahlon@martini.nu
COMMENT=	An object oriented perl interface to jail(2)

BUILD_DEPENDS=\
	${SITE_PERL}/Inline.pm:${PORTSDIR}/devel/p5-Inline

MAKE_JOBS_UNSAFE=	yes

PERL_CONFIGURE=	5.8.6+

MAN3=		BSD::Jail::Object.3

.include <bsd.port.mk>
