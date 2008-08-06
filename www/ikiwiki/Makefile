# New ports collection makefile for:	ikiwiki
# Date created:		21 Apr 2007
# Whom:			Henrik Brix Andersen <henrik@brixandersen.dk>
#
# $FreeBSD$

PORTNAME=	ikiwiki
PORTVERSION=	2.56
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
		${SITE_PERL}/RPC/XML.pm:${PORTSDIR}/net/p5-RPC-XML \
		${SITE_PERL}/XML/Feed.pm:${PORTSDIR}/textproc/p5-XML-Feed \
		${SITE_PERL}/Authen/Passphrase.pm:${PORTSDIR}/security/p5-Authen-Passphrase

WRKSRC=		${WRKDIR}/${PORTNAME}

PERL_CONFIGURE=	yes
USE_GMAKE=	yes
USE_GETTEXT=	yes

OPTIONS=	SEARCH "Install search backend" On \
		W3M "Install w3m CGI wrapper" Off

MAN1=		ikiwiki.1 ikiwiki-makerepo.1 ikiwiki-transition.1 ikiwiki-update-wikilist.1
MAN8=		ikiwiki-mass-rebuild.8
PORTDOCS=	CHANGELOG NEWS README
PORTEXAMPLES=	ikiwiki.setup

.include <bsd.port.pre.mk>

.if defined(WITH_SEARCH)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Digest/SHA1.pm:${PORTSDIR}/security/p5-Digest-SHA1 \
		${SITE_PERL}/${PERL_ARCH}/Search/Xapian.pm:${PORTSDIR}/databases/p5-Search-Xapian \
		${LOCALBASE}/www/xapian-omega/cgi-bin/omega:${PORTSDIR}/www/xapian-omega
.endif

.if defined(WITH_W3M)
PLIST_SUB=	W3M=""
.else
PLIST_SUB=	W3M="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		"s|/usr/bin/markdown|${LOCALBASE}/bin/markdown|" \
		${WRKSRC}/IkiWiki/Plugin/mdwn.pm
	@${RM} ${WRKSRC}/IkiWiki/Plugin/mdwn.pm.bak
	@${REINPLACE_CMD} -e \
		"s|/etc/ikiwiki/wikilist|${LOCALBASE}/etc/ikiwiki/wikilist|" \
		${WRKSRC}/ikiwiki-mass-rebuild \
		${WRKSRC}/doc/ikiwiki-mass-rebuild.mdwn \
		${WRKSRC}/ikiwiki-update-wikilist \
		${WRKSRC}/doc/ikiwiki-update-wikilist.mdwn
	@${REINPLACE_CMD} \
		-e 's|$$(PREFIX)/share/man|$$(PREFIX)/man|' \
		-e 's|$$(PREFIX)/lib/w3m|$$(PREFIX)/libexec/w3m|' \
		-e 's|-wholename|-path|' \
		${WRKSRC}/Makefile.PL
	@${REINPLACE_CMD} -e \
		"s|/usr/lib/cgi-bin/omega/omega|${LOCALBASE}/www/xapian-omega/cgi-bin/omega|" \
		${WRKSRC}/doc/ikiwiki.setup
.ifndef(WITH_W3M)
	@${REINPLACE_CMD} -e '/w3m/d' ${WRKSRC}/Makefile.PL
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S@^@${WRKSRC}/@} ${DOCSDIR}
.endif
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${PORTEXAMPLES:S@^@${WRKSRC}/doc/@} ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
