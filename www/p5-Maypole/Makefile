# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Maypole
PORTVERSION=	2.13
PORTREVISION=	5
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEEJAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	MVC web application framework

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-CGI-Simple>=0:www/p5-CGI-Simple \
		p5-CGI-Untaint>=1.26:www/p5-CGI-Untaint \
		p5-CGI-Untaint-date>=0:www/p5-CGI-Untaint-date \
		p5-CGI-Untaint-email>=0:www/p5-CGI-Untaint-email \
		p5-Class-DBI>=0.96:databases/p5-Class-DBI \
		p5-Class-DBI-AbstractSearch>=0:databases/p5-Class-DBI-AbstractSearch \
		p5-Class-DBI-Loader-Relationship>=0:databases/p5-Class-DBI-Loader-Relationship \
		p5-Class-DBI-Loader>=0.02:databases/p5-Class-DBI-Loader \
		p5-Class-DBI-Pager>=0:databases/p5-Class-DBI-Pager \
		p5-Class-DBI-Plugin-RetrieveAll>=0:databases/p5-Class-DBI-Plugin-RetrieveAll \
		p5-Class-DBI-Plugin-Type>=0:databases/p5-Class-DBI-Plugin-Type \
		p5-File-MMagic-XS>=0.08:devel/p5-File-MMagic-XS \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-HTTP-Body>=0.5:www/p5-HTTP-Body \
		p5-Lingua-EN-Inflect-Number>=0:textproc/p5-Lingua-EN-Inflect-Number \
		p5-Template-Plugin-Class>=0:www/p5-Template-Plugin-Class \
		p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
		p5-UNIVERSAL-moniker>=0:devel/p5-UNIVERSAL-moniker \
		p5-UNIVERSAL-require>=0:devel/p5-UNIVERSAL-require \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockModule>=0:devel/p5-Test-MockModule \
		p5-DBD-SQLite>=0:databases/p5-DBD-SQLite

PORTSCOUT=	skipv:2.111,2.121

OPTIONS_DEFINE=	MODPERL2 DOCS EXAMPLES
OPTIONS_DEFAULT=MODPERL2
MODPERL2_DESC=	mod_perl2 support

USES=		perl5
USE_PERL5=	configure

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES=	pkg-message
DOC_FILES=	../Manual.pod \
		About.pod \
		Beer.pod \
		BuySpy.pod \
		Flox.pod \
		Model.pod \
		StandardTemplates.pod \
		View.pod \
		Workflow.pod
PORTDOCS=	*
PORTEXAMPLES=	*

MODPERL2_USE=		APACHE_RUN=22+
MODPERL2_BUILD_DEPENDS=	p5-libapreq2>=0:www/p5-libapreq2

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC}/lib/Maypole/Manual/ && ${INSTALL_DATA} ${DOC_FILES} ${STAGEDIR}${DOCSDIR}/
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
