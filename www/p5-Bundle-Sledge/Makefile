# New ports collection makefile for:	p5-Bundle-Sledge
# Date created:		26 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Bundle-Sledge
PORTVERSION=	0.04
PORTREVISION=	3
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bundle to install all modules used for Sledge

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2 \
		${SITE_PERL}/Test/Inline.pm:${PORTSDIR}/devel/p5-Test-Inline \
		${SITE_PERL}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert \
		${SITE_PERL}/Class/Fields.pm:${PORTSDIR}/devel/p5-Class-Fields \
		${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor \
		${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable \
		${SITE_PERL}/Class/Singleton.pm:${PORTSDIR}/devel/p5-Class-Singleton \
		${SITE_PERL}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger \
		${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/HTML/StickyQuery.pm:${PORTSDIR}/www/p5-HTML-StickyQuery \
		${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy \
		${JCODE}:${PORTSDIR}/japanese/p5-Jcode \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit \
		${SITE_PERL}/Data/Properties.pm:${PORTSDIR}/devel/p5-Data-Properties \
		${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_APACHE=	20+
PERL_CONFIGURE=	yes

MAN3=		Bundle::Sledge.3

JCODE=	${SITE_PERL}/Jcode.pm

.include <bsd.port.mk>
