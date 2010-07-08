# New ports collection makefile for:	Data-FormValidator-Constraints-DateTime
# Date created:	   17 August 2007
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Data-FormValidator-Constraints-DateTime
PORTVERSION=	1.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/W/WO/WONKO
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Data::FormValidator constraints for dates and times

BUILD_DEPENDS=	${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		${SITE_PERL}/${PERL_ARCH}/DateTime.pm:${PORTSDIR}/devel/p5-DateTime \
		${SITE_PERL}/DateTime/Format/Strptime.pm:${PORTSDIR}/devel/p5-DateTime-Format-Strptime \
		${SITE_PERL}/DateTime/Format/Builder.pm:${PORTSDIR}/devel/p5-DateTime-Format-Builder
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=		Data::FormValidator::Constraints::DateTime.3

.include <bsd.port.mk>
