# New ports collection makefile for:	www/p5-Catalyst-Example-InstantCRUD
# Date created:				11 Feb 2006
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Example-InstantCRUD
DISTVERSION=	v0.0.10
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/Z/ZB/ZBY
PKGNAMEPREFIX=	p5-

MAINTAINER=	lbr@FreeBSD.org
COMMENT=	Create a working CRUD Catalyst example with the least of effort

BUILD_DEPENDS=	\
	p5-Test-Simple>=0:${PORTSDIR}/devel/p5-Test-Simple \
	p5-version>=0:${PORTSDIR}/devel/p5-version \
	p5-URI>=0:${PORTSDIR}/net/p5-URI \
	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
	p5-HTML-Widget>=0:${PORTSDIR}/www/p5-HTML-Widget \
	p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
	p5-Catalyst>=5.66:${PORTSDIR}/www/p5-Catalyst \
	p5-Catalyst-View-TT>=0.21:${PORTSDIR}/www/p5-Catalyst-View-TT \
	p5-Template-Plugin-Class>=0:${PORTSDIR}/www/p5-Template-Plugin-Class \
	p5-Catalyst-Plugin-DefaultEnd>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-DefaultEnd \
	p5-Catalyst-Model-DBIC>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC \
	p5-Catalyst-Model-DBIC-Schema>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
	p5-DBIx-Class>=0:${PORTSDIR}/databases/p5-DBIx-Class \
	p5-DBIx-Class-Loader>=0:${PORTSDIR}/databases/p5-DBIx-Class-Loader
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=	instantcrud.pl.1
MAN3=	Catalyst::Example::Controller::InstantCRUD.3 \
	Catalyst::Example::InstantCRUD.3 \
	Catalyst::Helper::Controller::InstantCRUD.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif
.include <bsd.port.post.mk>
