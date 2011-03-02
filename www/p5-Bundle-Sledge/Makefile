# New ports collection makefile for:	p5-Bundle-Sledge
# Date created:		26 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Bundle-Sledge
PORTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A bundle to install all modules used for Sledge

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

USE_APACHE=	13+
.include <bsd.port.pre.mk>

.if ${APACHE_VERSION} == 13
PM_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.else
PM_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2
.endif
PM_DEPENDS+=	${SITE_PERL}/Apache/Reload.pm:${PORTSDIR}/www/p5-Apache-Reload
PM_DEPENDS+=	${SITE_PERL}/Test/Inline.pm:${PORTSDIR}/devel/p5-Test-Inline
PM_DEPENDS+=	${SITE_PERL}/Carp/Assert.pm:${PORTSDIR}/devel/p5-Carp-Assert
PM_DEPENDS+=	${SITE_PERL}/Class/Fields.pm:${PORTSDIR}/devel/p5-Class-Fields
PM_DEPENDS+=	${SITE_PERL}/Class/Accessor.pm:${PORTSDIR}/devel/p5-Class-Accessor
PM_DEPENDS+=	${SITE_PERL}/Class/Data/Inheritable.pm:${PORTSDIR}/devel/p5-Class-Data-Inheritable
PM_DEPENDS+=	${SITE_PERL}/Class/Singleton.pm:${PORTSDIR}/devel/p5-Class-Singleton
PM_DEPENDS+=	${SITE_PERL}/Class/Trigger.pm:${PORTSDIR}/devel/p5-Class-Trigger
PM_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1
PM_DEPENDS+=	${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm
PM_DEPENDS+=	${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template
PM_DEPENDS+=	${SITE_PERL}/HTML/StickyQuery.pm:${PORTSDIR}/www/p5-HTML-StickyQuery
PM_DEPENDS+=	${SITE_PERL}/IO/Stringy.pm:${PORTSDIR}/devel/p5-IO-stringy
PM_DEPENDS+=	${JCODE}:${PORTSDIR}/japanese/p5-Jcode
PM_DEPENDS+=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
PM_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Template.pm:${PORTSDIR}/www/p5-Template-Toolkit
PM_DEPENDS+=	${SITE_PERL}/Data/Properties.pm:${PORTSDIR}/devel/p5-Data-Properties
PM_DEPENDS+=	${SITE_PERL}/Error.pm:${PORTSDIR}/lang/p5-Error
PM_DEPENDS+=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww

PERL_CONFIGURE=	yes

MAN3=		Bundle::Sledge.3

JCODE=	${SITE_PERL}/Jcode.pm

.include <bsd.port.post.mk>
