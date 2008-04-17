# New ports collection makefile for:	p5-WWW-Hotmail
# Date created:		2006-07-20
# Whom:			Steven Kreuzer <skreuzer@f2o.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Hotmail
PORTVERSION=	0.10
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skreuzer@exit2shell.com
COMMENT=	This module simplifies access to hotmail

BUILD_DEPENDS=	${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/Mail/Audit.pm:${PORTSDIR}/mail/p5-Mail-Audit
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Hotmail.3

.include <bsd.port.mk>
