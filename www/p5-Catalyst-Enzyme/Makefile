# New ports collection makefile for:	www/p5-Catalyst-Enzyme
# Date created:				12 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Enzyme
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Catalyst
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	CRUD framework for Catalyst

BUILD_DEPENDS=	\
	p5-Catalyst>=0:${PORTSDIR}/www/p5-Catalyst \
	p5-Catalyst-Model-CDBI>=0.1:${PORTSDIR}/www/p5-Catalyst-Model-CDBI \
	p5-Catalyst-Plugin-DefaultEnd>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-DefaultEnd \
	p5-Catalyst-Plugin-FormValidator>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-FormValidator \
	p5-Catalyst-View-TT-ControllerLocal>=0:${PORTSDIR}/www/p5-Catalyst-View-TT-ControllerLocal \
	p5-Class-DBI>=0.96:${PORTSDIR}/databases/p5-Class-DBI \
	p5-Class-DBI-AsForm>=2.42:${PORTSDIR}/databases/p5-Class-DBI-AsForm \
	p5-Class-DBI-FromForm>=0.03:${PORTSDIR}/www/p5-Class-DBI-FromForm \
	p5-Class-DBI-Pager>=0:${PORTSDIR}/databases/p5-Class-DBI-Pager \
	p5-Class-DBI-Plugin-Type>=0.02:${PORTSDIR}/databases/p5-Class-DBI-Plugin-Type \
	p5-Class-DBI-SQLite>=0.09:${PORTSDIR}/databases/p5-Class-DBI-SQLite \
	p5-Data-FormValidator>=4.02:${PORTSDIR}/textproc/p5-Data-FormValidator \
	p5-DBI-Shell>=0:${PORTSDIR}/databases/p5-DBI-Shell \
	p5-File-Slurp>=0:${PORTSDIR}/devel/p5-File-Slurp \
	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
	p5-Scalar-List-Utils>=0:${PORTSDIR}/lang/p5-Scalar-List-Utils \
	p5-Path-Class>=0:${PORTSDIR}/devel/p5-Path-Class \
	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
	p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Catalyst::Enzyme.3 \
	Catalyst::Enzyme::CRUD::Controller.3 \
	Catalyst::Enzyme::CRUD::Model.3 \
	Catalyst::Enzyme::CRUD::View.3 \
	Catalyst::Enzyme::Controller.3 \
	Catalyst::Helper::Controller::Enzyme::CRUD.3 \
	Catalyst::Helper::Model::Enzyme::CDBI.3 \
	Catalyst::Helper::View::Enzyme::TT.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
