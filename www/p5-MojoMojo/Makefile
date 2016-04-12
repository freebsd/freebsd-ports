# Created by: Lars Balker Rasmussen <lbr@FreeBSD.org>
# $FreeBSD$

PORTNAME=	MojoMojo
PORTVERSION=	1.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:MRAMBERG
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Catalyst & DBIx::Class powered Wiki

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

# Please keep order as in Makefile.PL
BUILD_DEPENDS=	\
	p5-Plack>=0.9974:www/p5-Plack \
	p5-Algorithm-Diff>=1.1901:devel/p5-Algorithm-Diff \
	p5-Algorithm-Merge>=0:devel/p5-Algorithm-Merge \
	p5-Archive-Zip>=1.14:archivers/p5-Archive-Zip \
	p5-Cache-FastMmap>=1.31:devel/p5-Cache-FastMmap \
	p5-Catalyst-Runtime>=5.71001:www/p5-Catalyst-Runtime \
	p5-Catalyst-Action-RenderView>=0.07:www/p5-Catalyst-Action-RenderView \
	p5-Catalyst-Authentication-Store-DBIx-Class>=0.101:www/p5-Catalyst-Authentication-Store-DBIx-Class \
	p5-Catalyst-Controller-HTML-FormFu>=0.03007:www/p5-Catalyst-Controller-HTML-FormFu \
	p5-Catalyst-Model-DBIC-Schema>=0.01:www/p5-Catalyst-Model-DBIC-Schema \
	p5-Catalyst-Plugin-Authentication>=0.10005:www/p5-Catalyst-Plugin-Authentication \
	p5-Catalyst-Plugin-Cache>=0.08:www/p5-Catalyst-Plugin-Cache \
	p5-Catalyst-Plugin-ConfigLoader>=0.13:www/p5-Catalyst-Plugin-ConfigLoader \
	p5-Catalyst-Plugin-I18N>=0:www/p5-Catalyst-Plugin-I18N \
	p5-Catalyst-Plugin-SubRequest>=0.13:www/p5-Catalyst-Plugin-SubRequest \
	p5-Catalyst-Plugin-Session-State-Cookie>=0.11:www/p5-Catalyst-Plugin-Session-State-Cookie \
	p5-Catalyst-Plugin-Session-Store-Cache>=0:www/p5-Catalyst-Plugin-Session-Store-Cache \
	p5-Catalyst-Plugin-Setenv>=0:www/p5-Catalyst-Plugin-Setenv \
	p5-Catalyst-Plugin-Static-Simple>=0.07:www/p5-Catalyst-Plugin-Static-Simple \
	p5-Catalyst-Plugin-Unicode>=0.8:www/p5-Catalyst-Plugin-Unicode \
	p5-Catalyst-View-TT>=0.23:www/p5-Catalyst-View-TT \
	p5-Catalyst-View-JSON>=0.26:www/p5-Catalyst-View-JSON \
	p5-Catalyst-View-Email>=0:www/p5-Catalyst-View-Email \
	p5-Config-General>=0:devel/p5-Config-General \
	p5-Config-JFDI>=0:devel/p5-Config-JFDI \
	p5-Crypt-CBC>=2.12:security/p5-Crypt-CBC \
	p5-Data-Page>=2.00:databases/p5-Data-Page \
	p5-DateTime>=0.28:devel/p5-DateTime \
	p5-DateTime-Format-Mail>=0:devel/p5-DateTime-Format-Mail \
	p5-Directory-Scratch>=0.14:devel/p5-Directory-Scratch \
	p5-DBD-SQLite>=1.08:databases/p5-DBD-SQLite \
	p5-DBIx-Class>=0.08:databases/p5-DBIx-Class \
	p5-DBIx-Class-DateTime-Epoch>=0.04:databases/p5-DBIx-Class-DateTime-Epoch \
	p5-DBIx-Class-EncodedColumn>=0:databases/p5-DBIx-Class-EncodedColumn \
	p5-DBIx-Class-TimeStamp>=0.11:databases/p5-DBIx-Class-TimeStamp \
	p5-File-Copy-Recursive>=0:devel/p5-File-Copy-Recursive \
	p5-File-MMagic>=1.27:devel/p5-File-MMagic \
	p5-File-Slurp>=9999.13:devel/p5-File-Slurp \
	p5-HTML-Parser>=3.60:www/p5-HTML-Parser \
	p5-HTML-FormFu>=0.02000:www/p5-HTML-FormFu \
	p5-HTML-FormFu-Model-DBIC>=0:www/p5-HTML-FormFu-Model-DBIC \
	p5-HTML-Strip>=1.04:www/p5-HTML-Strip \
	p5-HTML-TagCloud>=0:www/p5-HTML-TagCloud \
	p5-HTML-Toc>=0:www/p5-HTML-Toc \
	p5-Image-ExifTool>=0:graphics/p5-Image-ExifTool \
	p5-Imager>=0:graphics/p5-Imager \
	p5-Image-Math-Constrain>=0:graphics/p5-Image-Math-Constrain \
	p5-IO-stringy>=0:devel/p5-IO-stringy \
	p5-KinoSearch1>=1.00:textproc/p5-KinoSearch1 \
	p5-Module-Pluggable-Ordered>=1.4:devel/p5-Module-Pluggable-Ordered \
	p5-Moose>=0:devel/p5-Moose \
	p5-MRO-Compat>=0.10:devel/p5-MRO-Compat \
	p5-Number-Format>=0:textproc/p5-Number-Format \
	p5-Template-Toolkit>=0:www/p5-Template-Toolkit \
	p5-Template-Plugin-JavaScript>=0:www/p5-Template-Plugin-JavaScript \
	p5-Text-Context>=3.5:textproc/p5-Text-Context \
	p5-Text-MultiMarkdown>=1.000031:textproc/p5-Text-MultiMarkdown \
	p5-Text-Password-Pronounceable>=0:security/p5-Text-Password-Pronounceable \
	p5-Text-Textile>=0:textproc/p5-Text-Textile \
	p5-URI>=1.37:net/p5-URI \
	p5-URI-Find>=0:textproc/p5-URI-Find \
	p5-WWW-Mechanize>=1.54:www/p5-WWW-Mechanize \
	p5-WWW-Mechanize-TreeBuilder>=1.10000:www/p5-WWW-Mechanize-TreeBuilder \
	p5-YAML>=0.36:textproc/p5-YAML \
	p5-Term-Prompt>=0:devel/p5-Term-Prompt \
	p5-Text-Emoticon-MSN>=0:textproc/p5-Text-Emoticon-MSN
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-Test-WWW-Mechanize-Catalyst>=0:devel/p5-Test-WWW-Mechanize-Catalyst

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

OPTIONS_DEFINE=	DEPLOY FASTCGI TOCGEN RECAPTCHA SYNTAX_HIGHLIGHT RSS_FORMATTER \
		DOCBOOK_FORMATTER POD_FORMATTER TRANSCLUSION AMAZON
DEPLOY_DESC=		Automatic database deployment
TOCGEN_DESC=		Table of Contents generator
RECAPTCHA_DESC=		reCAPTCHA for anonymous edits
SYNTAX_HIGHLIGHT_DESC=	Syntax highlighter
RSS_FORMATTER_DESC=	RSS formatter
DOCBOOK_FORMATTER_DESC=	DocBook formatter
POD_FORMATTER_DESC=	POD formatter
TRANSCLUSION_DESC=	Transclusion support
AMAZON_DESC=		Amazon boxes

DEPLOY_BUILD_DEPENDS=		p5-SQL-Translator>=0.09006:databases/p5-SQL-Translator
DEPLOY_RUN_DEPENDS=		p5-SQL-Translator>=0.09006:databases/p5-SQL-Translator
FASTCGI_BUILD_DEPENDS=		p5-FCGI-ProcManager>=0:www/p5-FCGI-ProcManager
FASTCGI_RUN_DEPENDS=		p5-FCGI-ProcManager>=0:www/p5-FCGI-ProcManager
TOCGEN_BUILD_DEPENDS=		p5-HTML-Toc>=1.10:www/p5-HTML-Toc
TOCGEN_RUN_DEPENDS=		p5-HTML-Toc>=1.10:www/p5-HTML-Toc
RECAPTCHA_BUILD_DEPENDS=	p5-HTML-FormFu>=0:www/p5-HTML-FormFu
RECAPTCHA_RUN_DEPENDS=		p5-HTML-FormFu>=0:www/p5-HTML-FormFu
SYNTAX_HIGHLIGHT_BUILD_DEPENDS=	p5-Syntax-Highlight-Engine-Kate>=0:textproc/p5-Syntax-Highlight-Engine-Kate
SYNTAX_HIGHLIGHT_RUN_DEPENDS=	p5-Syntax-Highlight-Engine-Kate>=0:textproc/p5-Syntax-Highlight-Engine-Kate
RSS_FORMATTER_BUILD_DEPENDS=	p5-XML-Feed>=0:textproc/p5-XML-Feed
RSS_FORMATTER_RUN_DEPENDS=	p5-XML-Feed>=0:textproc/p5-XML-Feed
DOCBOOK_FORMATTER_BUILD_DEPENDS=p5-XML-LibXML>=1.66:textproc/p5-XML-LibXML \
				p5-XML-LibXSLT>=1.66:textproc/p5-XML-LibXSLT
DOCBOOK_FORMATTER_RUN_DEPENDS=	p5-XML-LibXML>=1.66:textproc/p5-XML-LibXML \
				p5-XML-LibXSLT>=1.66:textproc/p5-XML-LibXSLT
POD_FORMATTER_BUILD_DEPENDS=	p5-Pod-Simple>=3.01:textproc/p5-Pod-Simple
POD_FORMATTER_RUN_DEPENDS=	p5-Pod-Simple>=3.01:textproc/p5-Pod-Simple
TRANSCLUSION_BUILD_DEPENDS=	p5-URI-Fetch>=0:www/p5-URI-Fetch \
				p5-libwww>=0:www/p5-libwww
TRANSCLUSION_RUN_DEPENDS=	p5-URI-Fetch>=0:www/p5-URI-Fetch \
				p5-libwww>=0:www/p5-libwww
AMAZON_BUILD_DEPENDS=		p5-Net-Amazon>=0:net/p5-Net-Amazon
AMAZON_RUN_DEPENDS=		p5-Net-Amazon>=0:net/p5-Net-Amazon

.include <bsd.port.mk>
