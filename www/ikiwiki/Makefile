# New ports collection makefile for:	ikiwiki
# Date created:		21 Apr 2007
# Whom:			Henrik Brix Andersen <henrik@brixandersen.dk>
#
# $FreeBSD$

PORTNAME=	ikiwiki
PORTVERSION=	3.20100722
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_DEBIAN_POOL} \
		http://kitenet.net/~joey/debian/unstable/
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	brix@FreeBSD.org
COMMENT=	A wiki compiler

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext \
		${SITE_PERL}/CGI/FormBuilder.pm:${PORTSDIR}/www/p5-CGI-FormBuilder \
		${SITE_PERL}/CGI/Session.pm:${PORTSDIR}/www/p5-CGI-Session \
		${SITE_PERL}/Date/Parse.pm:${PORTSDIR}/devel/p5-TimeDate \
		${SITE_PERL}/HTML/Scrubber.pm:${PORTSDIR}/www/p5-HTML-Scrubber \
		${SITE_PERL}/HTML/Template.pm:${PORTSDIR}/www/p5-HTML-Template \
		${SITE_PERL}/Mail/Sendmail.pm:${PORTSDIR}/mail/p5-Mail-Sendmail \
		${SITE_PERL}/Text/Markdown.pm:${PORTSDIR}/textproc/p5-Text-Markdown \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${SITE_PERL}/File/MimeInfo.pm:${PORTSDIR}/devel/p5-File-MimeInfo \
		po4a>=0.39:${PORTSDIR}/textproc/po4a \
		${SITE_PERL}/RPC/XML.pm:${PORTSDIR}/net/p5-RPC-XML \
		${SITE_PERL}/XML/Feed.pm:${PORTSDIR}/textproc/p5-XML-Feed \
		${SITE_PERL}/Authen/Passphrase.pm:${PORTSDIR}/security/p5-Authen-Passphrase

WRKSRC=		${WRKDIR}/${PORTNAME}

LICENSE=	GPLv2
PERL_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

OPTIONS=	SEARCH "Install search backend" On \
		W3M "Install w3m CGI wrapper" Off

MAN1=		ikiwiki.1 ikiwiki-calendar.1 ikiwiki-makerepo.1 ikiwiki-transition.1 ikiwiki-update-wikilist.1
MAN8=		ikiwiki-mass-rebuild.8
PORTDOCS=	CHANGELOG NEWS README
PORTEXAMPLES=	*

.include <bsd.port.pre.mk>

.if defined(WITH_SEARCH)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Search/Xapian.pm:${PORTSDIR}/databases/p5-Search-Xapian \
		${LOCALBASE}/www/xapian-omega/cgi-bin/omega:${PORTSDIR}/www/xapian-omega
.endif

.if defined(WITH_W3M)
MAKE_ENV+=	W3M_CGI_BIN=${PREFIX}/libexec/w3m/cgi-bin
PLIST_SUB=	W3M=""
.else
PLIST_SUB=	W3M="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -i '' \
		-e "s|/usr/bin/markdown|${LOCALBASE}/bin/markdown|" \
		${WRKSRC}/IkiWiki/Plugin/mdwn.pm
	@${REINPLACE_CMD} -i '' \
		-e "s|/etc/ikiwiki/wikilist|${PREFIX}/etc/ikiwiki/wikilist|" \
		${WRKSRC}/ikiwiki-mass-rebuild \
		${WRKSRC}/doc/ikiwiki-mass-rebuild.mdwn \
		${WRKSRC}/ikiwiki-update-wikilist \
		${WRKSRC}/doc/ikiwiki-update-wikilist.mdwn
	@${REINPLACE_CMD} -i '' \
		-e 's|$$(PREFIX)/share/man|$$(PREFIX)/man|' \
		-e 's|-wholename|-path|' \
		-e 's|\(-install -d $$(DESTDIR)/etc/ikiwiki\)|#\1|' \
		-e 's|\(-install -m 0644 wikilist\)|#\1|' \
		-e 's|\(-install -m 0644 auto.setup\)|#\1|' \
		-e 's|\(-install -m 0644 auto-blog.setup\)|#\1|' \
		-e 's|$$(DESTDIR)$$(PREFIX)/share/ikiwiki/examples|${EXAMPLESDIR}|' \
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
.ifndef(WITH_W3M)
	@${REINPLACE_CMD} -i '' \
		-e '/w3m/d' \
		-e '/W3M/d' \
		 ${WRKSRC}/Makefile.PL
.endif
.if defined(NOPORTEXAMPLES)
	@${REINPLACE_CMD} -i '' \
		-e 's|\(install -d ${EXAMPLESDIR}\)|#\1|' \
		-e 's|\(cp -aL doc/examples\)|#\1|' \
		-e 's|\(install -m 644 doc/examples\)|#\1|' \
		${WRKSRC}/Makefile.PL
.endif

post-install:
	${MKDIR} ${PREFIX}/etc/ikiwiki
	${INSTALL_DATA} ${WRKSRC}/auto.setup ${PREFIX}/etc/ikiwiki
	${INSTALL_DATA} ${WRKSRC}/auto-blog.setup ${PREFIX}/etc/ikiwiki
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/ikiwiki.setup ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/wikilist ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
