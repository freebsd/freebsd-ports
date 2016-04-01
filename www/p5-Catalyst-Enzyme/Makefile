# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Catalyst-Enzyme
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	CRUD framework for Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7000:www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.00:www/p5-Catalyst-Devel \
		p5-Catalyst-Model-CDBI>=0.1:www/p5-Catalyst-Model-CDBI \
		p5-Catalyst-Plugin-DefaultEnd>=0:www/p5-Catalyst-Plugin-DefaultEnd \
		p5-Catalyst-Plugin-FormValidator>=0:www/p5-Catalyst-Plugin-FormValidator \
		p5-Catalyst-View-TT-ControllerLocal>=0:www/p5-Catalyst-View-TT-ControllerLocal \
		p5-Class-DBI>=0.96:databases/p5-Class-DBI \
		p5-Class-DBI-AsForm>=2.42:databases/p5-Class-DBI-AsForm \
		p5-Class-DBI-FromForm>=0.03:www/p5-Class-DBI-FromForm \
		p5-Class-DBI-Pager>=0:databases/p5-Class-DBI-Pager \
		p5-Class-DBI-Plugin-Type>=0.02:databases/p5-Class-DBI-Plugin-Type \
		p5-Class-DBI-SQLite>=0.09:databases/p5-Class-DBI-SQLite \
		p5-Data-FormValidator>=4.02:textproc/p5-Data-FormValidator \
		p5-DBI-Shell>=0:databases/p5-DBI-Shell \
		p5-File-Slurp>=0:devel/p5-File-Slurp \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Path-Class>=0:devel/p5-Path-Class \
		p5-URI>=0:net/p5-URI
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
