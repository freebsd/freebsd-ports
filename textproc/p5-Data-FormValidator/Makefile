# New ports collection makefile for:	Data::FormValidator
# Date created:				27 Oct 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=		Data-FormValidator
PORTVERSION=		4.13
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Data
PKGNAMEPREFIX=		p5-

MAINTAINER=		perl@FreeBSD.org
COMMENT=		Validates user input (usually from an HTML form) based

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc \
		${SITE_PERL}/File/MMagic.pm:${PORTSDIR}/devel/p5-File-MMagic \
		${SITE_PERL}/Image/Size.pm:${PORTSDIR}/graphics/p5-Image-Size \
		${SITE_PERL}/Regexp/Common.pm:${PORTSDIR}/textproc/p5-Regexp-Common \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple \
		${SITE_PERL}/Test/Pod.pm:${PORTSDIR}/devel/p5-Test-Pod

PERL_MODBUILD=		yes

MAN3=		Data::FormValidator.3 \
		Data::FormValidator::ConstraintsFactory.3 \
		Data::FormValidator::Constraints.3 \
		Data::FormValidator::Constraints::Dates.3 \
		Data::FormValidator::Constraints::Upload.3 \
		Data::FormValidator::Filters.3 \
		Data::FormValidator::Results.3

.include <bsd.port.pre.mk>

# fails a lot of tests with 5.6.X, so require 5.8.X
.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.x or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
