# New ports collection makefile for:	p5-Text-WikiFormat
# Date created:				Sat Jan 17 18:15:01 UTC 2004
# Whom:					Alexander Zhuravlev <zaa@zaa.pp.ru>
#
# $FreeBSD$
#

PORTNAME=	Text-WikiFormat
PORTVERSION=	0.71
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Text
PKGNAMEPREFIX=	p5-

MAINTAINER=	zaa@ulstu.ru
COMMENT=	Module for translating Wiki formatted text into other formats

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/Module/Build.pm:${PORTSDIR}/devel/p5-Module-Build
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Text::WikiFormat.3
PLIST_FILES=	%%SITE_PERL%%/Text/WikiFormat.pm

.include <bsd.port.mk>
