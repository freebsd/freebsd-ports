# New ports collection makefile for:	www/p5-WWW-Mechanize
# Date created:				02 April 2003
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Mechanize
PORTVERSION=	1.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	This module is to help you automate interaction with a website

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Mechanize.3 WWW::Mechanize::Cookbook.3 \
		WWW::Mechanize::Examples.3 WWW::Mechanize::FAQ.3 \
		WWW::Mechanize::Link.3 WWW::Mechanize::Image.3
MAN1=		mech-dump.1

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp \
		${SITE_PERL}/Pod/Usage.pm:${PORTSDIR}/textproc/p5-PodParser
.if ${PERL_LEVEL} < 500601
BUILD_DEPENDS+=	${SITE_PERL}/File/Spec.pm:${PORTSDIR}/devel/p5-File-Spec

post-patch:
	@${PERL} -pi \
		-e 's/^our\s+([\$$\@]\w+)/use vars qw($$1);$$1/;' \
		-e 's/^our\s+([\%]\w+)/use vars qw($$1)/;' \
		-e 's/(?:my )?\$$fh/FH/;' \
		-e 's/FH, ">",/FH, ">"./;' \
		-e '$$_="" if /use warnings/;' \
		${WRKSRC}/lib/WWW/Mechanize.pm ${WRKSRC}/lib/WWW/Mechanize/Link.pm
.endif
.endif

.include <bsd.port.post.mk>
