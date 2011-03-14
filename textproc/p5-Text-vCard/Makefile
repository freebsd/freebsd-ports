# New ports collection makefile for:	p5-Text-vCard
# Date created:				22 Feb 2006
# Whom:					Emanuel Haupt <ehaupt@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=		Text-vCard
PORTVERSION=		2.10
CATEGORIES=		textproc perl5
MASTER_SITES=		CPAN
PKGNAMEPREFIX=		p5-

MAINTAINER=		ehaupt@FreeBSD.org
COMMENT=		A package to parse, edit and create multiple vCards (RFC 2426)

BUILD_DEPENDS=		${SITE_PERL}/File/Slurp.pm:${PORTSDIR}/devel/p5-File-Slurp \
			${SITE_PERL}/Text/vFile/asData.pm:${PORTSDIR}/devel/p5-Text-vFile-asData
RUN_DEPENDS=		${BUILD_DEPENDS}

PERL_CONFIGURE=		yes
MAKE_JOBS_SAFE=		yes

MAN3=			Text::vCard::Node.3 Text::vCard.3 \
			Text::vCard::Addressbook.3

.include <bsd.port.mk>
