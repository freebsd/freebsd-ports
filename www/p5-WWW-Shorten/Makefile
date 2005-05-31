# New ports collection makefile for:	p5-WWW-Shorten
# Date created:				August 29 2003
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$
#

PORTNAME=	WWW-Shorten
PORTVERSION=	1.95
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Abstract interface to URL shortening sites

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Shorten.3 \
		WWW::Shorten::BabyURL.3 \
		WWW::Shorten::EkDk.3 \
		WWW::Shorten::Linkz.3 \
		WWW::Shorten::MakeAShorterLink.3 \
		WWW::Shorten::Metamark.3 \
		WWW::Shorten::NotLong.3 \
		WWW::Shorten::OneShortLink.3 \
		WWW::Shorten::Shorl.3 \
		WWW::Shorten::ShortLink.3 \
		WWW::Shorten::SmLnk.3 \
		WWW::Shorten::SnipURL.3 \
		WWW::Shorten::TinyClick.3 \
		WWW::Shorten::TinyURL.3 \
		WWW::Shorten::Tinylink.3 \
		WWW::Shorten::URLjr.3 \
		WWW::Shorten::V3.3 \
		WWW::Shorten::qURL.3

DOCS=		AUTHORS Artistic COPYING CREDITS ChangeLog.SPOON Changes \
		INSTALL LICENCE MANIFEST MANIFEST.SKIP META.yml \
		README SIGNATURE
EXAMPLES=	shorten shortenrc

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing docs for ${PKGNAME}"
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	${MKDIR} ${EXAMPLESDIR}
	cd ${WRKSRC}/bin && ${INSTALL_SCRIPT} ${EXAMPLES} ${EXAMPLESDIR}
.endif

test:
	cd ${WRKSRC} ; make test

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our ([\$$\@]\w+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use 5.006/;' \
		     -e '$$_ = "" if /use warnings/;' \
		 $$(${FIND} ${WRKSRC} -name '*.pm')
.endif

.include <bsd.port.post.mk>
