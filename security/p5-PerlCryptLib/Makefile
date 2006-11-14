# New ports collection makefile for:	p5-PerlCryptLib
# Date created:		2006-08-08
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	PerlCryptLib
PORTVERSION=	1.03
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/A/AL/ALVAROL
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl interface to Peter Guttman cryptlib API

LIB_DEPENDS=	cl:${PORTSDIR}/security/cryptlib
RUN_DEPENDS=	${SITE_PERL}/enum.pm:${PORTSDIR}/devel/p5-enum

PERL_CONFIGURE=	yes

MAN3=		PerlCryptLib.3

post-patch:
	${PERL} -pi -e 's,^use 5\.008.*$$,,' ${WRKSRC}/Makefile.PL
	${PERL} -pi -e 's,\.\./cryptlib322,${LOCALBASE}/include,' \
		${WRKSRC}/PerlCryptLib.xs

post-configure:
	${PERL} -pi -e 's,-lpthread,${PTHREAD_LIBS},' ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		requires Perl 5.6.0 or newer. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
