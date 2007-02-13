# ex:ts=8
# Ports collection makefile for:	Class::CSV
# Date created:			Dec 25, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Class-CSV
PORTVERSION=	1.03
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class based CSV parser/writer

RUN_DEPENDS=	p5-Text-CSV_XS>=0.23:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Class-Accessor>=0.18:${PORTSDIR}/devel/p5-Class-Accessor
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Class::CSV.3

.include <bsd.port.mk>
