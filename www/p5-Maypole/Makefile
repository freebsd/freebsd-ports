# Created by: Lars Thegler <lars@thegler.dk>
# $FreeBSD$

PORTNAME=	Maypole
PORTVERSION=	2.13
PORTREVISION=	4
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:TEEJAY
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
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-MockModule>=0:${PORTSDIR}/devel/p5-Test-MockModule \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite

PORTSCOUT=	skipv:2.121

OPTIONS_DEFINE=	MODPERL2 DOCS EXAMPLES
OPTIONS_DEFAULT=	MODPERL2
MODPERL2_DESC=	mod_perl2 support

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMODPERL2}
USE_APACHE_RUN=	22+
BUILD_DEPENDS+=	p5-libapreq2>=0:${PORTSDIR}/www/p5-libapreq2
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_FILES+=	pkg-message

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
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
.for FILE in ${DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/lib/Maypole/Manual/${FILE} ${STAGEDIR}${DOCSDIR}/
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}/
	${CP} -R ${WRKSRC}/examples/ ${STAGEDIR}${EXAMPLESDIR}/

.include <bsd.port.mk>
