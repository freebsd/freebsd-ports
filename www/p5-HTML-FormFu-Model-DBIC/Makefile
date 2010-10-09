# New ports collection makefile for:	p5-HTML-FormFu-Model-DBIC
# Date created:				2008-08-13
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-FormFu-Model-DBIC
PORTVERSION=	0.08002
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Set a forms default values from a DBIx::Class row object

BUILD_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBIx-Class>=0.08108:${PORTSDIR}/databases/p5-DBIx-Class \
		p5-HTML-FormFu>=0.05000:${PORTSDIR}/www/p5-HTML-FormFu \
		p5-List-MoreUtils>=0:${PORTSDIR}/lang/p5-List-MoreUtils \
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-YAML-Syck>=0:${PORTSDIR}/textproc/p5-YAML-Syck
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		HTML::FormFu::Constraint::DBIC::Unique.3 \
		HTML::FormFu::Model::DBIC.3

.include <bsd.port.mk>
