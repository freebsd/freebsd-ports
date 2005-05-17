# New ports collection makefile for:	Apache-AuthenCache
# Date created:				Sun Dec 31 19:59:31 2000
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	Apache-AuthenCache
PORTVERSION=	1.00
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/C/CG/CGILMORE
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl module that implements authentication caching

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Time/Object.pm:${PORTSDIR}/devel/p5-Time-Object \
		${SITE_PERL}/IPC/Cache.pm:${PORTSDIR}/devel/p5-IPC-Cache
RUN_DEPENDS=	${BUILD_DEPENDS}

.if defined(WITH_APACHE2)
BROKEN=		Broken due the new mod_perl2 API
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache2/mod_perl.so:${PORTSDIR}/www/mod_perl2
.else
BUILD_DEPENDS+=	${LOCALBASE}/libexec/apache/libperl.so:${PORTSDIR}/www/mod_perl
.endif

PERL_CONFIGURE=	yes

MAN3=		Apache::AuthenCache.3

post-patch:
	@${FIND} ${WRKSRC} -name "*.orig" -a -exec ${RM} -f {} \;

.include <bsd.port.mk>
