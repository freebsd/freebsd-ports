# New ports collection makefile for:	Net-SNPP
# Date created:		6 Jun 2002
# Whom:			devin@spamcop.net
#
# $FreeBSD$
#

PORTNAME=	Net-SNPP
PORTVERSION=	1.17
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Net
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	Net::SNPP - Perl Simple Network Pager Protocol Client

PERL_CONFIGURE=	yes

MAN3=		Net::SNPP.3 \
		Net::SNPP::Server.3

post-patch:
	@${PERL} -pi -e '$$_="" if /warnings/;' \
		${WRKSRC}/lib/Net/SNPP/Server.pm
	@${RM} ${WRKSRC}/lib/Net/SNPP/Server.pm.orig

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS=	${SITE_PERL}/Net/Cmd.pm:${PORTSDIR}/net/p5-Net
RUN_DEPENDS=	${BUILD_DEPENDS}
.endif

.include <bsd.port.post.mk>
