# New ports collection makefile for:	www/p5-POE-Component-Server-SimpleHTTP
# Date created:				12 October 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Server-SimpleHTTP
PORTVERSION=	1.11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Perl extension to serve HTTP requests in POE

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable \
		${SITE_PERL}/HTTP/Date.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/POE.pm:${PORTSDIR}/devel/p5-POE
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		POE::Component::Server::SimpleHTTP.3 \
		POE::Component::Server::SimpleHTTP::Connection.3 \
		POE::Component::Server::SimpleHTTP::PreFork.3 \
		POE::Component::Server::SimpleHTTP::Response.3

OPTIONS=	SSL "SSL support (POE::Component::SSLify)" on \
		PREFORK "PreFork support (IRC::Shareable)" on

.include <bsd.port.pre.mk>

.ifdef(WITH_SSL)
BUILD_DEPENDS+=	${SITE_PERL}/POE/Component/SSLify.pm:${PORTSDIR}/security/p5-POE-Component-SSLify
.endif

.ifdef(WITH_PREFORK)
BUILD_DEPENDS+=	${SITE_PERL}/IPC/Shareable.pm:${PORTSDIR}/devel/p5-IPC-Shareable
.endif

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${FILESDIR}/500503-*

post-patch:
	@${PERL} -pi -e 's/^our ([\$$\@]\w+)/use vars qw($$1); $$1/;' \
		     -e '$$_ = "" if /use warnings/;' \
		$$(${FIND} ${WRKSRC} -name '*.pm')
	@${RM} ${WRKSRC}/lib/POE/Component/Server/SimpleHTTP.pm.orig
.endif

.include <bsd.port.post.mk>
