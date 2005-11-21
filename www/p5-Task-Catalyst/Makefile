# New ports collection makefile for:	www/p5-Task-Catalyst
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Task-Catalyst
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	All you need to start with Catalyst

BUILD_DEPENDS=	p5-Catalyst>=0:${PORTSDIR}/www/p5-Catalyst \
		p5-Catalyst-Plugin-FormValidator>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-FormValidator \
		p5-Catalyst-Plugin-FormValidator-Simple>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-FormValidator-Simple \
		p5-Catalyst-Plugin-FillInForm>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-FillInForm \
		p5-Catalyst-Plugin-Prototype>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Prototype \
		p5-Catalyst-Plugin-Singleton>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Singleton \
		p5-Catalyst-Plugin-DefaultEnd>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-DefaultEnd \
		p5-Catalyst-Plugin-SubRequest>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-SubRequest \
		p5-Catalyst-Plugin-Session>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-State-Cookie>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-State-URI>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-URI \
		p5-Catalyst-Plugin-Session-Store-File>=0:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-Model-DBIC>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC \
		p5-Catalyst-Model-DBIC-Plain>=0:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Plain \
		p5-Catalyst-View-TT>=0:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Task::Catalyst.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
