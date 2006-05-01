# New ports collection makefile for:	www/p5-Task-Catalyst
# Date created:				21 Nov 2005
# Whom:					Lars Balker Rasmussen <lars@balker.dk>
#
# $FreeBSD$
#

PORTNAME=	Task-Catalyst
PORTVERSION=	1.90
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/S/SR/SRI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lars@balker.dk
COMMENT=	All you need to start with Catalyst

BUILD_DEPENDS=	p5-Catalyst>=5.65:${PORTSDIR}/www/p5-Catalyst \
		p5-Params-Validate>=0:${PORTSDIR}/devel/p5-Params-Validate \
		p5-Catalyst-Log-Log4perl>=0.1:${PORTSDIR}/www/p5-Catalyst-Log-Log4perl \
		p5-Date-Calc>=0:${PORTSDIR}/devel/p5-Date-Calc \
		p5-Catalyst-Plugin-HTML-Widget>=1.1:${PORTSDIR}/www/p5-Catalyst-Plugin-HTML-Widget \
		p5-Catalyst-Plugin-StackTrace>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-StackTrace \
		p5-Catalyst-Plugin-Prototype>=1.32:${PORTSDIR}/www/p5-Catalyst-Plugin-Prototype \
		p5-Catalyst-Plugin-Singleton>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Singleton \
		p5-Catalyst-Plugin-DefaultEnd>=0.03:${PORTSDIR}/www/p5-Catalyst-Plugin-DefaultEnd \
		p5-Catalyst-Plugin-SubRequest>=0.10:${PORTSDIR}/www/p5-Catalyst-Plugin-SubRequest \
		p5-Catalyst-Plugin-Session>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Session \
		p5-Catalyst-Plugin-Session-Store-File>=0.07:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-Store-File \
		p5-Catalyst-Plugin-Session-State-Cookie>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-Cookie \
		p5-Catalyst-Plugin-Session-State-URI>=0.02:${PORTSDIR}/www/p5-Catalyst-Plugin-Session-State-URI \
		p5-Catalyst-Plugin-Authentication>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication \
		p5-Catalyst-Plugin-Authentication-Store-DBIC>=0.04:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication-Store-DBIC \
		p5-Catalyst-Plugin-Authentication-Store-Htpasswd>=0.020:${PORTSDIR}/www/p5-Catalyst-Plugin-Authentication-Store-Htpasswd \
		p5-Catalyst-Plugin-Authorization-ACL>=0.06:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-ACL \
		p5-Catalyst-Plugin-Authorization-Roles>=0.03:${PORTSDIR}/www/p5-Catalyst-Plugin-Authorization-Roles \
		p5-Catalyst-Plugin-I18N>=0.05:${PORTSDIR}/www/p5-Catalyst-Plugin-I18N \
		p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser \
		p5-Catalyst-Plugin-XMLRPC>=0.06:${PORTSDIR}/www/p5-Catalyst-Plugin-XMLRPC \
		p5-Catalyst-Plugin-Pluggable>=0.04:${PORTSDIR}/www/p5-Catalyst-Plugin-Pluggable \
		p5-Catalyst-Model-DBIC-Schema>=0.08:${PORTSDIR}/www/p5-Catalyst-Model-DBIC-Schema \
		p5-Catalyst-View-TT>=0.22:${PORTSDIR}/www/p5-Catalyst-View-TT \
		p5-Test-WWW-Mechanize-Catalyst>=0.35:${PORTSDIR}/devel/p5-Test-WWW-Mechanize-Catalyst \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	Task::Catalyst.3

post-extract:
	@${PERL} -i.bak -ne 'print unless m,^features, .. m,^\);,' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500800
IGNORE=	requires Perl 5.8. Install lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
