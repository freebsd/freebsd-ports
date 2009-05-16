# New ports collection makefile for:	Apache-AuthenCache
# Date created:				Sun Dec 31 19:59:31 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenCache
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/C/CG/CGILMORE
PKGNAMEPREFIX=	p5-

MAINTAINER=	pgollucci@FreeBSD.org
COMMENT=	Perl module that implements authentication caching

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Object.pm:${PORTSDIR}/devel/p5-Time-Object \
		${SITE_PERL}/IPC/Cache.pm:${PORTSDIR}/devel/p5-IPC-Cache
RUN_DEPENDS=	${BUILD_DEPENDS}

MAKE_JOBS_SAFE=  yes

.if defined(WITH_APACHE2)
IGNORE=		this module is only for www/mod_perl
.else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthenCache.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

.include <bsd.port.mk>
