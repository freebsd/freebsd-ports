# New ports collection makefile for:	CGI-Cache
# Date created:				Mon Jan  1 11:26:17 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	CGI-Cache
PORTVERSION=	1.42.00
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	CGI
PKGNAMEPREFIX=	p5-
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.(..)$/\1/}

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl extension to cache output of time-intensive CGI scripts

RUN_DEPENDS=	${SITE_PERL}/Tie/Restore.pm:${PORTSDIR}/devel/p5-Tie-Restore \
		${SITE_PERL}/${PERL_ARCH}/File/Spec.pm:${PORTSDIR}/devel/p5-PathTools \
		${SITE_PERL}/Cache/SizeAwareFileCache.pm:${PORTSDIR}/devel/p5-Cache-Cache \
		${SITE_PERL}/${PERL_ARCH}/Storable.pm:${PORTSDIR}/devel/p5-Storable
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=		CGI::Cache.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
RUN_DEPENDS+=	${SITE_PERL}/File/Temp.pm:${PORTSDIR}/devel/p5-File-Temp
post-configure:
	${PERL} -pi -e 's/-I\S+PERL\S+ //g if m{PERL_DL_NONLAZY}' ${WRKSRC}/Makefile
.endif

.include <bsd.port.post.mk>
