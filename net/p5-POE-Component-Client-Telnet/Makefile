# New ports collection makefile for:	p5-POE-Component-Client-Telnet
# Date created:		2006-07-31
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Telnet
PORTVERSION=	0.06
PORTREVISION=	1
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	POE
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	A POE component that provides non-blocking access to Net::Telnet

BUILD_DEPENDS=	p5-POE>=0.31:${PORTSDIR}/devel/p5-POE \
		${SITE_PERL}/Net/Telnet.pm:${PORTSDIR}/net/p5-Net-Telnet \
		${SITE_PERL}/Devel/Symdump.pm:${PORTSDIR}/devel/p5-Devel-Symdump
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Client::Telnet.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
post-patch:
	@${PERL} -pi -e '$$_ = "" if /use warnings/;' \
		${WRKSRC}/Makefile.PL
.endif

.if ${PERL_LEVEL} < 500602
BUILD_DEPENDS+=	p5-Test-Simple>=0.32:${PORTSDIR}/devel/p5-Test-Simple
.endif

.include <bsd.port.post.mk>
