PORTNAME=	ikiwiki
DISTVERSION=	3.20250501
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	DEBIAN_POOL \
		LOCAL/mat/${PORTNAME}
DISTNAME=	${PORTNAME}_${DISTVERSION}
EXTRACT_SUFX=	.orig.tar.xz

MAINTAINER=	mat@FreeBSD.org
COMMENT=	Wiki compiler
WWW=		https://ikiwiki.info/

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-CGI-FormBuilder>=0:www/p5-CGI-FormBuilder \
		p5-CGI-Session>=0:www/p5-CGI-Session \
		p5-HTML-Parser>=0:www/p5-HTML-Parser \
		p5-HTML-Scrubber>=0:www/p5-HTML-Scrubber \
		p5-HTML-Template>=0:www/p5-HTML-Template \
		p5-HTML-Tree>=0:www/p5-HTML-Tree \
		p5-Locale-gettext>=0:devel/p5-Locale-gettext \
		p5-Mail-Sendmail>=0:mail/p5-Mail-Sendmail \
		p5-Net-OpenID-Consumer>=0:net/p5-Net-OpenID-Consumer \
		p5-Text-Markdown>=0:textproc/p5-Text-Markdown \
		p5-TimeDate>=0:devel/p5-TimeDate \
		p5-URI>=0:net/p5-URI \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-XML-Twig>=0:textproc/p5-XML-Twig \
		p5-YAML-LibYAML>=0:textproc/p5-YAML-LibYAML \
		p5-YAML>=0:textproc/p5-YAML
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils@${PY_FLAVOR} \
		p5-Authen-Passphrase>=0:security/p5-Authen-Passphrase \
		p5-File-MimeInfo>=0:devel/p5-File-MimeInfo \
		p5-LWPx-ParanoidAgent>=0:www/p5-LWPx-ParanoidAgent \
		p5-RPC-XML>=0:net/p5-RPC-XML \
		p5-XML-Feed>=0:textproc/p5-XML-Feed
TEST_DEPENDS=	p5-IPC-Run>=0:devel/p5-IPC-Run

USES=		cpe gettext gmake perl5 python shebangfix
USE_PERL5=	configure

SHEBANG_FILES=	plugins/* pm_filter

CONFIGURE_ARGS=	FULLPERL=${PERL} \
		PERL=${PERL}
MAKE_ENV=	SYSCONFDIR=${ETCDIR} \
		W3M_CGI_BIN=${PREFIX}/libexec/w3m/cgi-bin
NO_ARCH=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S/_/-/}

PORTDOCS=	CHANGELOG NEWS README
PORTEXAMPLES=	*

OPTIONS_DEFINE=		DOCS EXAMPLES IMG MULTI PO4A SEARCH W3M
OPTIONS_DEFAULT=	IMG MULTI PO4A SEARCH
OPTIONS_SUB=

IMG_DESC=	Allow image manipulation (using Image::Magick)
MULTI_DESC=	Install Text::MultiMarkdown
PO4A_DESC=	Install translated underlays
SEARCH_DESC=	Install search backend
W3M_DESC=	Install w3m CGI wrapper

IMG_USES=		magick:run,test
MULTI_RUN_DEPENDS=	p5-Text-MultiMarkdown>=0:textproc/p5-Text-MultiMarkdown
PO4A_BUILD_DEPENDS=	po4a>=0.39:textproc/po4a
PO4A_RUN_DEPENDS=	po4a>=0.39:textproc/po4a
SEARCH_RUN_DEPENDS=	${LOCALBASE}/www/xapian-omega/cgi-bin/omega:www/xapian-omega \
			p5-Digest-SHA1>=0:security/p5-Digest-SHA1 \
			p5-Search-Xapian>=0:databases/p5-Search-Xapian

post-patch:
	@${REINPLACE_CMD} -i '' \
		-e 's|/usr/bin/markdown|${LOCALBASE}/bin/markdown|' \
		${WRKSRC}/IkiWiki/Plugin/mdwn.pm
	@${REINPLACE_CMD} -i '' \
		-e 's|/etc/ikiwiki|${ETCDIR}|' \
		${WRKSRC}/auto.setup ${WRKSRC}/auto-blog.setup \
		${WRKSRC}/doc/ikiwiki-mass-rebuild.mdwn \
		${WRKSRC}/doc/ikiwiki-update-wikilist.mdwn
	@${REINPLACE_CMD} -i '' \
		-e 's|share/ikiwiki/examples|${EXAMPLESDIR_REL}|' \
		${WRKSRC}/Makefile.PL \
		${WRKSRC}/IkiWiki/Setup/Automator.pm
	@${REINPLACE_CMD} -i '' \
		-e 's|/usr/lib/cgi-bin/omega/omega|${LOCALBASE}/www/xapian-omega/cgi-bin/omega|g' \
		${WRKSRC}/IkiWiki/Plugin/search.pm
	@${REINPLACE_CMD} -i '' \
		-e 's|/etc/highlight|${LOCALBASE}/etc/highlight|; \
		    s|/usr/share/highlight|${LOCALBASE}/share/highlight|' \
		${WRKSRC}/IkiWiki/Plugin/highlight.pm
	@${REINPLACE_CMD} -i '' \
		-e 's|python3|${PYTHON_CMD}|g' \
		${WRKSRC}/t/rst.t

post-install:
	for i in ${STAGEDIR}${ETCDIR}/*; do ${MV} $$i $$i.sample; done

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ikiwiki.setup ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wikilist ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
