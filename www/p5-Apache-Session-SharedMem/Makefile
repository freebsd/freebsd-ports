# New ports collection makefile for:	p5-Apache-Session-SharedMem
# Date created:				April 03 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	Apache-Session-SharedMem
PORTVERSION=	0.6
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Apache::Session extension that store session in shared memory

BUILD_DEPENDS=	p5-IPC-Cache>=0:${PORTSDIR}/devel/p5-IPC-Cache \
		p5-Apache-Session>=0:${PORTSDIR}/www/p5-Apache-Session
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

MAN3=		Apache::Session::Store::SharedMem.3 \
		Apache::Session::SharedMem.3

#post-patch:
#	@${CP} ${WRKSRC}/Apache/Session/SharedMem.pm \
#		${WRKSRC}/lib/Apache/Session

.include <bsd.port.mk>
