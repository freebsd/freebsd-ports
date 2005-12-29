# New ports collection makefile for:	Digest-SHA2
# Date created:	   06 August 2003
# Whom:		   Sergey Skvortsov <skv@protey.ru>
#
# $FreeBSD$
#

PORTNAME=	Digest-SHA2
PORTVERSION=	1.1.0
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Digest
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to the SHA-2 algorithms

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Digest/base.pm:${PORTSDIR}/security/p5-Digest
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Digest::SHA2.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
EXTRA_PATCHES=	${PATCHDIR}/extrapatch-SHA2.xs

post-patch:
	${PERL} -pi -e 's/^our\s+([\$$\@\%]\w+)/use vars qw($$1); $$1/;' ${WRKSRC}/SHA2.pm
	${PERL} -pi -e '$$_="" if m{warnings}' ${WRKSRC}/SHA2.pm ${WRKSRC}/t/*.t
	${PERL} -pi -e 's/\)/, char **env\)/ if m{int main}' ${WRKSRC}/_sha2.c
.endif

.include <bsd.port.post.mk>
