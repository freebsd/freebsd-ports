# New ports collection makefile for:	p5-Apache-Session-SharedMem
# Date created:				April 03 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-SharedMem
PORTVERSION=	0.5
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache::Session extension that store session in shared memory

BUILD_DEPENDS=	${SITE_PERL}/IPC/Cache.pm:${PORTSDIR}/devel/p5-IPC-Cache \
		${SITE_PERL}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Apache::Session::Store::SharedMem.3 \
		Apache::Session::SharedMem.3

#post-patch:
#	@${CP} ${WRKSRC}/Apache/Session/SharedMem.pm \
#		${WRKSRC}/lib/Apache/Session

.include <bsd.port.mk>
