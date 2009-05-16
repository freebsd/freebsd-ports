# New ports collection makefile for:	p5-Mail-Audit-Attach
# Date created:				28 May 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Mail-Audit-Attach
PORTVERSION=	0.94
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Mail::Audit plugin for attachment handling

BUILD_DEPENDS=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Mail/Audit.pm:${PORTSDIR}/mail/p5-Mail-Audit \
		${SITE_PERL}/MIME/Entity.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/MIME/Head.pm:${PORTSDIR}/mail/p5-MIME-Tools \
		${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Mail/Header.pm:${PORTSDIR}/mail/p5-Mail-Tools
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

MAN3=	Mail::Audit::Attach.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
