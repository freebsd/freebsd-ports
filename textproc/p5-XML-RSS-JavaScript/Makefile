# New ports collection makefile for:    p5-XML-RSS-JavaScript
# Date created:				31 Oct 2003
# Whom:					Foxfair Hu <foxfair@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-RSS-JavaScript
PORTVERSION=	0.41
CATEGORIES=	textproc www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl extension to serialize your RSS as JavaScript

BUILD_DEPENDS=	${SITE_PERL}/XML/RSS.pm:${PORTSDIR}/textproc/p5-XML-RSS

PERL_CONFIGURE=	yes

MAN3=		XML::RSS::JavaScript.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e 's/^our (\S+)/use vars qw{$$1};$$1/g;' \
		     -e 's/\r//g;' \
		${WRKSRC}/lib/XML/RSS/JavaScript.pm
.endif

.include <bsd.port.post.mk>
