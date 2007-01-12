# ex:ts=8
# Ports collection makefile for:	Class::CSV
# Date created:			Dec 25, 2006
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	Class-CSV
PORTVERSION=	1.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Class based CSV parser/writer

BUILD_DEPENDS=	p5-Text-CSV_XS>=0.23:${PORTSDIR}/textproc/p5-Text-CSV_XS \
		p5-Class-Accessor>=0.18:${PORTSDIR}/devel/p5-Class-Accessor
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Class::CSV.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires perl5.6. Install lang/perl5 or lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
