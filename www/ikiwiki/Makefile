# Created by: Henrik Brix Andersen <henrik@brixandersen.dk>
# $FreeBSD$

PORTNAME=	ikiwiki
PORTVERSION=	3.20140815
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL} \
		http://kitenet.net/~joey/debian/unstable/ \
		LOCAL/mat/${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	brix@FreeBSD.org
COMMENT=	Wiki compiler

LICENSE=	GPLv2

BUILD_DEPENDS=	p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser \
		p5-Locale-gettext>=0:${PORTSDIR}/devel/p5-Locale-gettext \
		p5-CGI-FormBuilder>=0:${PORTSDIR}/www/p5-CGI-FormBuilder \
		p5-CGI-Session>=0:${PORTSDIR}/www/p5-CGI-Session \
		p5-TimeDate>=0:${PORTSDIR}/devel/p5-TimeDate \
		p5-HTML-Scrubber>=0:${PORTSDIR}/www/p5-HTML-Scrubber \
		p5-HTML-Template>=0:${PORTSDIR}/www/p5-HTML-Template \
		p5-Mail-Sendmail>=0:${PORTSDIR}/mail/p5-Mail-Sendmail \
		p5-Text-Markdown>=0:${PORTSDIR}/textproc/p5-Text-Markdown \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-XML-Simple>=0:${PORTSDIR}/textproc/p5-XML-Simple \
		p5-YAML>=0:${PORTSDIR}/textproc/p5-YAML \
		p5-YAML-LibYAML>=0:${PORTSDIR}/textproc/p5-YAML-LibYAML
RUN_DEPENDS:=	${BUILD_DEPENDS} \
		p5-File-MimeInfo>=0:${PORTSDIR}/devel/p5-File-MimeInfo \
		p5-RPC-XML>=0:${PORTSDIR}/net/p5-RPC-XML \
		p5-XML-Feed>=0:${PORTSDIR}/textproc/p5-XML-Feed \
		p5-Authen-Passphrase>=0:${PORTSDIR}/security/p5-Authen-Passphrase

WRKSRC=		${WRKDIR}/${PORTNAME}

USES=		gettext perl5 gmake
USE_PERL5=	configure

OPTIONS_DEFINE=	PO4A SEARCH W3M DOCS EXAMPLES
OPTIONS_DEFAULT=	PO4A SEARCH
OPTIONS_SUB=

PO4A_DESC=	Install translated underlays
SEARCH_DESC=	Install search backend
W3M_DESC=	Install w3m CGI wrapper

PO4A_RUN_DEPENDS=	po4a>=0.39:${PORTSDIR}/textproc/po4a
PO4A_BUILD_DEPENDS=	po4a>=0.39:${PORTSDIR}/textproc/po4a
SEARCH_RUN_DEPENDS=	p5-Digest-SHA1>=0:${PORTSDIR}/security/p5-Digest-SHA1 \
		p5-Search-Xapian>=0:${PORTSDIR}/databases/p5-Search-Xapian \
		${LOCALBASE}/www/xapian-omega/cgi-bin/omega:${PORTSDIR}/www/xapian-omega
W3M_MAKE_ENV=	W3M_CGI_BIN=${PREFIX}/libexec/w3m/cgi-bin

PORTDOCS=	CHANGELOG NEWS README
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

post-patch:
	@${GREP} -rl '^#!/usr/bin/perl' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i '' \
		-e "s|#!/usr/bin/perl|#!${PERL}|"
	@${REINPLACE_CMD} -i '' \
		-e "s|/usr/bin/markdown|${LOCALBASE}/bin/markdown|" \
		${WRKSRC}/IkiWiki/Plugin/mdwn.pm
	@${REINPLACE_CMD} -i '' \
		-e "s|/etc/ikiwiki|${ETCDIR}|" \
		${WRKSRC}/auto.setup ${WRKSRC}/auto-blog.setup \
		${WRKSRC}/ikiwiki-mass-rebuild \
		${WRKSRC}/doc/ikiwiki-mass-rebuild.mdwn \
		${WRKSRC}/ikiwiki-update-wikilist \
		${WRKSRC}/doc/ikiwiki-update-wikilist.mdwn
	@${REINPLACE_CMD} -i '' \
		-e 's|$$(PREFIX)/share/man|$$(PREFIX)/man|' \
		-e 's|-wholename|-path|' \
		-e 's|\(-install -d $$(DESTDIR)$$(SYSCONFDIR)\)|#\1|' \
		-e 's|\(-install -m 0644 wikilist\)|#\1|' \
		-e 's|\(-install -m 0644 auto.setup\)|#\1|' \
		-e 's|\(-install -m 0644 auto-blog.setup\)|#\1|' \
		-e 's|/share/ikiwiki/examples|${EXAMPLESDIR:S/${PREFIX}//}|' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -i '' \
		-e "s|share/ikiwiki/examples|share/examples/ikiwiki|" \
		${WRKSRC}/IkiWiki/Setup/Automator.pm
	@${REINPLACE_CMD} -i '' \
		-e "s|/usr/lib/cgi-bin/omega/omega|${LOCALBASE}/www/xapian-omega/cgi-bin/omega|g" \
		${WRKSRC}/IkiWiki/Plugin/search.pm
	@${REINPLACE_CMD} -i '' \
		-e "s|/etc/highlight|${LOCALBASE}/etc/highlight|" \
		-e "s|/usr/share/highlight|${LOCALBASE}/share/highlight|" \
		${WRKSRC}/IkiWiki/Plugin/highlight.pm
.if ! ${PORT_OPTIONS:MPO4A}
	@${REINPLACE_CMD} -i '' \
		-e 's|^\(TRANSLATED_UNDERLAYS=\).*|\1|' \
		${WRKSRC}/po/Makefile
.endif
.if ! ${PORT_OPTIONS:MW3M}
	@${REINPLACE_CMD} -i '' \
		-e '/w3m/d' \
		-e '/W3M/d' \
		 ${WRKSRC}/Makefile.PL
.endif
.if ! ${PORT_OPTIONS:MEXAMPLES}
	@${REINPLACE_CMD} -i '' \
		-e 's|\(install -d ${EXAMPLESDIR}\)|#\1|' \
		-e 's|\(cp -aL doc/examples\)|#\1|' \
		-e 's|\(install -m 644 doc/examples\)|#\1|' \
		${WRKSRC}/Makefile.PL
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/auto.setup ${STAGEDIR}${ETCDIR}/auto.setup.sample
	${INSTALL_DATA} ${WRKSRC}/auto-blog.setup ${STAGEDIR}${ETCDIR}/auto-blog.setup.sample
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${STAGEDIR}${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ikiwiki.setup ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wikilist ${STAGEDIR}${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
