# New ports collection makefile for:	www/p5-Jemplate
# Date created:				05 April 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jemplate
PORTVERSION=	0.20
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/I/IN/INGY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	JavaScript Templating with Template Toolkit

RUN_DEPENDS=	p5-File-Find-Rule>=0.30:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-Template-Toolkit>=2.14:${PORTSDIR}/www/p5-Template-Toolkit
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	jemplate.1
MAN3=	Jemplate.3 \
	Jemplate::Directive.3

.include <bsd.port.mk>
