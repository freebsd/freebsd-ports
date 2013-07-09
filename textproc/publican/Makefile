# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	publican
PORTVERSION=	2.8
CATEGORIES=	textproc perl5
MASTER_SITES=	http://pkgs.fedoraproject.org/repo/pkgs/publican/Publican-${PORTVERSION}.tar.gz/1ddcf8e93e96d0e49868f21df41b53a4/
DISTNAME=	Publican-${PORTVERSION}

MAINTAINER=	doceng@FreeBSD.org
COMMENT=	Single source publishing tool based on DocBook XML.

USE_JAVA=	yes
PERL_MODBUILD=	yes

MAKE_JOBS_UNSAFE=	yes

BUILD_DEPENDS=	\
		p5-Archive-Tar>=0:${PORTSDIR}/archivers/p5-Archive-Tar \
		p5-Archive-Zip>=0:${PORTSDIR}/archivers/p5-Archive-Zip \
		p5-Carp>=0:${PORTSDIR}/devel/p5-Carp \
		p5-Config-Simple>=0:${PORTSDIR}/devel/p5-Config-Simple \
		p5-PathTools>=0:${PORTSDIR}/devel/p5-PathTools \
		p5-DBD-SQLite>=0:${PORTSDIR}/databases/p5-DBD-SQLite \
		p5-DBI>=0:${PORTSDIR}/databases/p5-DBI \
		p5-Data-Dumper>=0:${PORTSDIR}/devel/p5-Data-Dumper \
		p5-DateTime>=0:${PORTSDIR}/devel/p5-DateTime \
		p5-DateTime-Format-DateParse>=0:${PORTSDIR}/devel/p5-DateTime-Format-DateParse \
		p5-Encode>=0:${PORTSDIR}/converters/p5-Encode \
		p5-File-Copy-Recursive>=0.38:${PORTSDIR}/devel/p5-File-Copy-Recursive \
		p5-File-Find-Rule>=0:${PORTSDIR}/devel/p5-File-Find-Rule \
		p5-File-Path>=0:${PORTSDIR}/devel/p5-File-Path \
		p5-File-Which>=0:${PORTSDIR}/sysutils/p5-File-Which \
		p5-File-pushd>=0:${PORTSDIR}/devel/p5-File-pushd \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-HTML-Format>=0:${PORTSDIR}/textproc/p5-HTML-Format \
		p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree \
		p5-IO-String>=0:${PORTSDIR}/devel/p5-IO-String \
		convert:${PORTSDIR}/graphics/ImageMagick \
		p5-Image-Size>=0:${PORTSDIR}/graphics/p5-Image-Size \
		p5-Locale-Codes>=0:${PORTSDIR}/misc/p5-Locale-Codes \
		p5-Locale-Maketext-Gettext>=0:${PORTSDIR}/devel/p5-Locale-Maketext-Gettext \
		p5-Locale-PO>=0:${PORTSDIR}/devel/p5-Locale-PO \
		p5-Makefile-Parser>=0:${PORTSDIR}/textproc/p5-Makefile-Parser \
		p5-Syntax-Highlight-Engine-Kate>=0:${PORTSDIR}/textproc/p5-Syntax-Highlight-Engine-Kate \
		p5-Template-Toolkit>=0:${PORTSDIR}/www/p5-Template-Toolkit \
		p5-Term-ANSIColor>=0:${PORTSDIR}/devel/p5-Term-ANSIColor \
		p5-Text-Tabs+Wrap>=0:${PORTSDIR}/textproc/p5-Text-Tabs+Wrap \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-XML-LibXML>=1.67:${PORTSDIR}/textproc/p5-XML-LibXML \
		p5-XML-LibXSLT>=1.67:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-XML-TreeBuilder>=4.0:${PORTSDIR}/textproc/p5-XML-TreeBuilder \
		${LOCALBASE}/share/xml/docbook/4.5/docbookx.dtd:${PORTSDIR}/textproc/docbook-xml-450 \
		${LOCALBASE}/share/sgml/docbook/4.2:${PORTSDIR}/textproc/docbook-420 \
		${LOCALBASE}/share/xsl/docbook/html/chunk.xsl:${PORTSDIR}/textproc/docbook-xsl \
		librsvg2>=2.0:${PORTSDIR}/graphics/librsvg2 \
		fop:${PORTSDIR}/textproc/fop \
		${JAVALIBDIR}/xmlgraphics-commons.jar:${PORTSDIR}/graphics/xmlgraphics-commons \
		${JAVALIBDIR}/xml-apis-ext.jar:${PORTSDIR}/textproc/xml-commons \
		${LOCALBASE}/share/java/batik/lib/batik-all.jar:${PORTSDIR}/graphics/batik

RUN_DEPENDS:=	${BUILD_DEPENDS}

TEST_DEPENDS=	p5-Devel-Cover>=0:${PORTSDIR}/devel/p5-Devel-Cover \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Perl-Critic>=0:${PORTSDIR}/textproc/p5-Test-Perl-Critic \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage

MAN1=	publican.1
MAN3=	Publican.3 Publican::Builder.3 Publican::CreateBook.3 \
	Publican::CreateBrand.3 Publican::Localise.3 Publican::Translate.3 \
	Publican::TreeView.3 Publican::WebSite.3 Publican::XmlClean.3

post-patch:
	@${REINPLACE_CMD} -e 's,%%PREFIX%%,${PREFIX},g' \
			-e 's,%%DATADIR%%,${DATADIR},g' \
			-e 's,%%LOCALBASE%%,${LOCALBASE},g' \
			${WRKSRC}/Build.PL \
			${WRKSRC}/bin/publican \
			${WRKSRC}/completion/_publican \
			${WRKSRC}/datadir/xsl/eclipse.xsl \
			${WRKSRC}/datadir/xsl/epub.xsl \
			${WRKSRC}/datadir/xsl/html-single.xsl \
			${WRKSRC}/datadir/xsl/html.xsl \
			${WRKSRC}/datadir/xsl/man.xsl \
			${WRKSRC}/datadir/xsl/pdf.xsl \
			${WRKSRC}/etc/publican-website.cfg \
			${WRKSRC}/fop-ttc-metric.pl \
			${WRKSRC}/lib/Publican.pm \
			${WRKSRC}/lib/Publican/Builder.pm \
			${WRKSRC}/lib/Publican/WebSite.pm

.include <bsd.port.mk>
