# New ports collection makefile for:	www/p5-Task-Catalyst
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lbr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Task-Catalyst
PORTVERSION=	4.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	All you need to start with Catalyst

BUILD_DEPENDS=	p5-Catalyst-Runtime>=5.7007:${PORTSDIR}/www/p5-Catalyst-Runtime \
		p5-Catalyst-Devel>=1.02:${PORTSDIR}/www/p5-Catalyst-Devel \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Catalyst-Log-Log4perl>=0.1:${PORTSDIR}/www/p5-Catalyst-Log-Log4perl \
		p5-Catalyst-Controller-HTML-FormFu>=0.03:${PORTSDIR}/www/p5-Catalyst-Controller-HTML-FormFu \
		p5-Catalyst-Controller-FormBuilder>=0.03:${PORTSDIR}/www/p5-Catalyst-Controller-FormBuilder \
		p5-Catalyst-Plugin-StackTrace>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-StackTrace \
		p5-Catalyst-Plugin-Session>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-Store-File>=0.07:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-Plugin-Session-State-Cookie>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-State-URI>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-URI \
		p5-Catalyst-Plugin-Authentication>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Authentication-Store-DBIx-Class>=0.106:${PORTSDIR}/www/p5-Catalyst-Authentication-Store-DBIx-Class \
		p5-Catalyst-Plugin-Authorization-ACL>=0.06:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-ACL \
		p5-Catalyst-Plugin-Authorization-Roles>=0.03:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-Roles \
		p5-Catalyst-Plugin-I18N>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-I18N \
		p5-Catalyst-Model-DBIC-Schema>=0.08:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-View-TT>=0.22:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Test-WWW-Mechanize-Catalyst>=0.35:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	Task::Catalyst.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^feature, .. m,;\s*$$,' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
