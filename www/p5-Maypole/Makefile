# New ports collection makefile for:	p5-Maypole
# Date created:				Apr 2 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Maypole
PORTVERSION=	2.13
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/T/TE/TEEJAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MVC web application framework

BUILD_DEPENDS=	p5-CGI-Simple>0:${PORTSDIR}/www/p5-CGI-Simple \
		p5-CGI-Untaint-date>0:${PORTSDIR}/www/p5-CGI-Untaint-date \
		p5-CGI-Untaint-email>0:${PORTSDIR}/www/p5-CGI-Untaint-email \
		p5-CGI-Untaint>=1.26:${PORTSDIR}/www/p5-CGI-Untaint \
		p5-Class-DBI-AbstractSearch>0:${PORTSDIR}/databases/p5-Class-DBI-AbstractSearch \
		p5-Class-DBI-Loader-Relationship>0:${PORTSDIR}/databases/p5-Class-DBI-Loader-Relationship \
		p5-Class-DBI-Loader>=0.02:${PORTSDIR}/databases/p5-Class-DBI-Loader \
		p5-Class-DBI-Pager>0:${PORTSDIR}/databases/p5-Class-DBI-Pager \
		p5-Class-DBI-Plugin-RetrieveAll>0:${PORTSDIR}/databases/p5-Class-DBI-Plugin-RetrieveAll \
		p5-Class-DBI-Plugin-Type>0:${PORTSDIR}/databases/p5-Class-DBI-Plugin-Type \
		p5-Class-DBI>=0.96:${PORTSDIR}/databases/p5-Class-DBI \
		p5-Digest-MD5>0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-File-MMagic-XS>=0.08:${PORTSDIR}/devel/p5-File-MMagic-XS \
		p5-HTML-Tree>0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-HTTP-Body>=0.5:${PORTSDIR}/www/p5-HTTP-Body \
		p5-Lingua-EN-Inflect-Number>0:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect-Number \
		p5-Template-Plugin-Class>0:${PORTSDIR}/www/p5-Template-Plugin-Class \
		p5-Template-Toolkit>0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-UNIVERSAL-moniker>0:${PORTSDIR}/devel/p5-UNIVERSAL-moniker \
		p5-UNIVERSAL-require>0:${PORTSDIR}/devel/p5-UNIVERSAL-require \
		p5-URI>0:${PORTSDIR}/net/p5-URI \
		p5-libwww>0:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

OPTIONS=	MODPERL "mod_perl support" on \
			MODPERL2 "mod_perl2 support" off

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_MODPERL2)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache2/Request.pm:${PORTSDIR}/www/p5-libapreq2
.endif
.if defined(WITH_MODPERL)
BUILD_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq
.endif

.if defined(WITH_MODPERL) && defined(WITH_MODPERL2)
IGNORE=	only 1 mod_perl at a time
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES+=	pkg-message

MAN3=		Apache::MVC.3 \
		CGI::Maypole.3 \
		CGI::Untaint::Maypole.3 \
		Maypole.3 \
		Maypole::Application.3 \
		Maypole::CLI.3 \
		Maypole::Config.3 \
		Maypole::Constants.3 \
		Maypole::HTTPD.3 \
		Maypole::HTTPD::Frontend.3 \
		Maypole::Headers.3 \
		Maypole::Manual.3 \
		Maypole::Manual::About.3 \
		Maypole::Manual::Beer.3 \
		Maypole::Manual::BuySpy.3 \
		Maypole::Manual::Cookbook.3 \
		Maypole::Manual::Flox.3 \
		Maypole::Manual::Inheritance.3 \
		Maypole::Manual::Install.3 \
		Maypole::Manual::Model.3 \
		Maypole::Manual::Plugins.3 \
		Maypole::Manual::StandardTemplates.3 \
		Maypole::Manual::View.3 \
		Maypole::Manual::Workflow.3 \
		Maypole::Model::Base.3 \
		Maypole::Model::CDBI.3 \
		Maypole::Model::CDBI::AsForm.3 \
		Maypole::Model::CDBI::Base.3 \
		Maypole::Model::CDBI::DFV.3 \
		Maypole::Model::CDBI::FromCGI.3 \
		Maypole::Model::CDBI::Plain.3 \
		Maypole::Session.3 \
		Maypole::View::Base.3 \
		Maypole::View::TT.3

DOC_FILES=	../Manual.pod \
		About.pod \
		Beer.pod \
		BuySpy.pod \
		Flox.pod \
		Model.pod \
		StandardTemplates.pod \
		View.pod \
		Workflow.pod

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}/
.for FILE in ${DOC_FILES}
	@ ${INSTALL_DATA} ${WRKSRC}/lib/Maypole/Manual/${FILE} ${DOCSDIR}/
.endfor
.endif
.if !defined(NOPORTEXAMPLES)
	@ ${MKDIR} ${EXAMPLESDIR}/
	@ ${CP} -R ${WRKSRC}/examples/ ${EXAMPLESDIR}/
.endif
	@ ${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
