# New ports collection makefile for:	p5-MogileFS-Client
# Date created:		2007-04-22
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	MogileFS-Client
PORTVERSION=	1.06
CATEGORIES=	sysutils net perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/B/BR/BRADFITZ
PKGNAMEPREFIX=	p5-

MAINTAINER=	gslin@gslin.org
COMMENT=	Client library for the MogileFS distributed file system

RUN_DEPENDS=	${SITE_PERL}/IO/WrapTie.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		MogileFS::Client.3

.include <bsd.port.mk>
