# New ports collection makefile for:	textproc/p5-String-Flogger
# Date created:				03 December 2010
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	String-Flogger
PORTVERSION=	1.101241
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/../../authors/id/R/RJ/RJBS
MASTER_SITE_SUBDIR=	String
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	String munging for loggers

BUILD_DEPENDS=	p5-Params-Util>0:${PORTSDIR}/devel/p5-Params-Util \
		p5-Sub-Exporter>0:${PORTSDIR}/devel/p5-Sub-Exporter \
		p5-JSON>0:${PORTSDIR}/converters/p5-JSON
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	String::Flogger.3

.include <bsd.port.mk>
