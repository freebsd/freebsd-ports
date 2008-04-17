# New ports collection makefile for:	p5-Catalyst-Model-CDBI-Plain
# Date created:		Oct 22, 2006
# Whom:			kuriyama@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Model-CDBI-Plain
PORTVERSION=	0.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Catalyst plain base class for Class::DBI models

BUILD_DEPENDS=	p5-Class-DBI>0:${PORTSDIR}/databases/p5-Class-DBI \
		${RUN_DEPENDS}
RUN_DEPENDS=	p5-Catalyst-Runtime>0:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>0:${PORTSDIR}/www/p5-Catalyst-Devel

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Model::CDBI::Plain.3 Catalyst::Helper::Model::CDBI::Plain.3

.include <bsd.port.mk>
