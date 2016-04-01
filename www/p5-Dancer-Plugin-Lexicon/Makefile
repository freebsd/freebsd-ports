# Created by: Henk van Oers <hvo.pm@xs4all.nl>
# $FreeBSD$

PORTNAME=	Dancer-Plugin-Lexicon
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:DRTECH
PKGNAMEPREFIX=	p5-

MAINTAINER=	hvo.pm@xs4all.nl
COMMENT=	Flexible I18N using Locale::Maketext::Lexicon for Dancer apps

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Dancer>=1.3118:www/p5-Dancer \
		p5-Locale-Maketext-Lexicon>0:devel/p5-Locale-Maketext-Lexicon \
		p5-Package-Stash>0:devel/p5-Package-Stash \
		p5-PathTools>0:devel/p5-PathTools
BUILD_DEPENDS:=	${RUN_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
