# New ports collection makefile for:	www/p5-HTTP-Server-Simple
# Date created:				30 March 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	HTTP-Server-Simple
PORTVERSION=	0.26
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	HTTP
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	A very simple standalone HTTP daemon

PERL_CONFIGURE=	yes

MAN3=	HTTP::Server::Simple.3 \
	HTTP::Server::Simple::CGI.3 \
	HTTP::Server::Simple::CGI::Environment.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e '$$_ = "" if m!(use|no) warnings!' \
		${WRKSRC}/lib/HTTP/Server/Simple/CGI/Environment.pm \
		${WRKSRC}/lib/HTTP/Server/Simple/CGI.pm \
		${WRKSRC}/lib/HTTP/Server/Simple.pm
.endif
.include <bsd.port.post.mk>
