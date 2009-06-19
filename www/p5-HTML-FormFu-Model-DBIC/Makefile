# New ports collection makefile for:	p5-HTML-FormFu-Model-DBIC
# Date created:				2008-08-13
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	HTML-FormFu-Model-DBIC
PORTVERSION=	0.05000
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Set a forms default values from a DBIx::Class row object

BUILD_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite		\
		p5-DBIx-Class>=0.08002:${PORTSDIR}/databases/p5-DBIx-Class	\
		p5-DateTime-Format-MySQL>=0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL	\
		p5-HTML-FormFu>=0.03001:${PORTSDIR}/www/p5-HTML-FormFu		\
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken \
		p5-Test-MockObject>=0:${PORTSDIR}/devel/p5-Test-MockObject
RUN_DEPENDS=	p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite		\
		p5-DBIx-Class>=0.08002:${PORTSDIR}/databases/p5-DBIx-Class	\
		p5-DateTime-Format-MySQL>=0:${PORTSDIR}/devel/p5-DateTime-Format-MySQL	\
		p5-HTML-FormFu>=0.03001:${PORTSDIR}/www/p5-HTML-FormFu		\
		p5-Task-Weaken>=0:${PORTSDIR}/devel/p5-Task-Weaken

PERL_CONFIGURE=	yes

MAN3=		HTML::FormFu::Model::DBIC.3

.include <bsd.port.mk>
