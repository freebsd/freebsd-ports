# New ports collection makefile for:	p5-Apache-Session-SharedMem
# Date created:				April 03 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-SharedMem
PORTVERSION=	0.31
PORTREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Apache
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/IPC/Cache.pm:${PORTSDIR}/devel/p5-IPC-Cache \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/Apache/Session.pm:${PORTSDIR}/www/p5-Apache-Session
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		Apache::Session::Store::SharedMem.3 \
		Apache::Session::SharedMem.3

post-patch:
	@${CP} ${WRKSRC}/Apache/Session/SharedMem.pm \
		${WRKSRC}/lib/Apache/Session

.include <bsd.port.mk>
