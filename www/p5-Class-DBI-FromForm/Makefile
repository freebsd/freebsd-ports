# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Class-DBI-FromForm
PORTVERSION=	0.04
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Update Class::DBI using Data::FormValidator or HTML::Widget

BUILD_DEPENDS=	p5-Class-DBI>=0:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Data-FormValidator>=0:${PORTSDIR}/textproc/p5-Data-FormValidator
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Class::DBI::FromForm.3

.include <bsd.port.mk>
