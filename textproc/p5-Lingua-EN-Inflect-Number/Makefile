# New ports collection makefile for:	p5-Lingua-EN-Inflect-Number
# Date created:				Apr 4 2004
# Whom:					Lars Thegler <lars@thegler.dk>
#
# $FreeBSD$

PORTNAME=	Lingua-EN-Inflect-Number
PORTVERSION=	1.1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Lingua
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Force number of words to singular or plural

BUILD_DEPENDS=	${SITE_PERL}/Lingua/EN/Inflect.pm:${PORTSDIR}/textproc/p5-Lingua-EN-Inflect
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Lingua::EN::Inflect::Number.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1);$$1/;' \
		    -e '$$_="" if /use 5.006/;' \
		    -e '$$_="" if /use warnings/;' \
		${WRKSRC}/Number.pm

post-configure:
	${PERL} -pi -e 's,/usr/local/,\$$(PREFIX)/,g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
