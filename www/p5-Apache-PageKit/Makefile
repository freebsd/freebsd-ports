# New ports collection makefile for:	Apache::PageKit
# Date created:				27 Oct 2001
# Whom:					Seamus Venasse <svenasse@polaris.ca>
#
# $FreeBSD$
#

PORTNAME=	Apache-PageKit
PORTVERSION=	1.18
PORTREVISION=	0
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	MVCC web framework using mod_perl, XML and HTML::Template

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/mod_perl.pm:${PORTSDIR}/www/mod_perl \
		${SITE_PERL}/${PERL_ARCH}/Apache/Request.pm:${PORTSDIR}/www/p5-libapreq \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session \
		${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib \
		${SITE_PERL}/Data/FormValidator.pm:${PORTSDIR}/textproc/p5-Data-FormValidator \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/HTML/FillInForm.pm:${PORTSDIR}/www/p5-HTML-FillInForm \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/HTML/Clean.pm:${PORTSDIR}/www/p5-HTML-Clean \
		${SITE_PERL}/Mail/Mailer.pm:${PORTSDIR}/mail/p5-Mail-Tools \
		${SITE_PERL}/${PERL_ARCH}/Text/Iconv.pm:${PORTSDIR}/converters/p5-Text-Iconv \
		${SITE_PERL}/MD5.pm:${PORTSDIR}/security/p5-MD5 \
		${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser \
		${SITE_PERL}/XML/XPath.pm:${PORTSDIR}/textproc/p5-XML-XPath \
		${SITE_PERL}/Apache/DBI.pm:${PORTSDIR}/www/p5-Apache-DBI \
		${SITE_PERL}/MIME/Types.pm:${PORTSDIR}/mail/p5-MIME-Types \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXML.pm:${PORTSDIR}/textproc/p5-XML-LibXML \
		${SITE_PERL}/${PERL_ARCH}/XML/LibXSLT.pm:${PORTSDIR}/textproc/p5-XML-LibXSLT \
		${SITE_PERL}/${PERL_ARCH}/Apache/Test.pm:${PORTSDIR}/www/p5-Apache-Test
RUN_DEPENDS=	${BUILD_DEPENDS}

EXAMPLESDIR?=	${PREFIX}/share/examples/${PORTNAME}
PERL_CONFIGURE=	5.8.0+

MAN3=		Apache::ErrorReport.3 \
		Apache::PageKit.3 \
		Apache::PageKit::FAQ.3 \
		Apache::PageKit::Model.3 \
		Apache::PageKit::Session.3

post-build:
	@${FIND} ${WRKSRC} -name '*.orig' -delete

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR} ${EXAMPLESDIR} \
		${EXAMPLESDIR}/Config ${EXAMPLESDIR}/Content \
		${EXAMPLESDIR}/Model ${EXAMPLESDIR}/Model/MyPageKit \
		${EXAMPLESDIR}/View ${EXAMPLESDIR}/View/Default \
		${EXAMPLESDIR}/View/Default/pkit_edit ${EXAMPLESDIR}/View/pdf \
		${EXAMPLESDIR}/View/print ${EXAMPLESDIR}/View/wml \
		${EXAMPLESDIR}/View/xml ${EXAMPLESDIR}/contrib \
		${EXAMPLESDIR}/contrib/bin ${EXAMPLESDIR}/contrib/locale \
		${EXAMPLESDIR}/contrib/locale/templates \
		${EXAMPLESDIR}/contrib/locale/templates/empty \
		${EXAMPLESDIR}/contrib/locale/templates/po
	@${INSTALL_DATA} ${WRKSRC}/docsrc/* ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/eg/Config/* ${EXAMPLESDIR}/Config
	@${INSTALL_DATA} ${WRKSRC}/eg/Content/* ${EXAMPLESDIR}/Content
	@${INSTALL_DATA} ${WRKSRC}/eg/Model/MyPageKit/* ${EXAMPLESDIR}/Model/MyPageKit
	@${INSTALL_DATA} ${WRKSRC}/eg/README ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/eg/View/Default/*.tmpl ${EXAMPLESDIR}/View/Default
	@${INSTALL_DATA} ${WRKSRC}/eg/View/Default/*.xsl ${EXAMPLESDIR}/View/Default
	@${INSTALL_DATA} ${WRKSRC}/eg/View/Default/pkit_edit/* ${EXAMPLESDIR}/View/Default/pkit_edit
	@${INSTALL_DATA} ${WRKSRC}/eg/View/pdf/* ${EXAMPLESDIR}/View/pdf
	@${INSTALL_DATA} ${WRKSRC}/eg/View/print/* ${EXAMPLESDIR}/View/print
	@${INSTALL_DATA} ${WRKSRC}/eg/View/wml/* ${EXAMPLESDIR}/View/wml
	@${INSTALL_DATA} ${WRKSRC}/eg/View/xml/* ${EXAMPLESDIR}/View/xml
	@${INSTALL_DATA} ${WRKSRC}/eg/contrib/bin/* ${EXAMPLESDIR}/contrib/bin
	@${INSTALL_DATA} ${WRKSRC}/eg/contrib/locale/README ${EXAMPLESDIR}/contrib/locale
	@${INSTALL_DATA} ${WRKSRC}/eg/contrib/locale/templates/empty/* ${EXAMPLESDIR}/contrib/locale/templates/empty
	@${INSTALL_DATA} ${WRKSRC}/eg/contrib/locale/templates/po/* ${EXAMPLESDIR}/contrib/locale/templates/po
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
