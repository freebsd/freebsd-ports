# New ports collection makefile for:	Socket::GetAddrInfo
# Date created:				29 November 2009
# Whom:					Sahil Tandon <sahil@tandon.net>
#
# $FreeBSD$
#

PORTNAME=	Socket-GetAddrInfo
PORTVERSION=	0.22
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	RFC 2553's getaddrinfo and getnameinfo functions

BUILD_DEPENDS=	p5-ExtUtils-CChecker>=0.06:${PORTSDIR}/devel/p5-ExtUtils-CChecker

MAN1=		getaddrinfo.1 \
		getnameinfo.1

MAN3=		Socket::GetAddrInfo.3 \
		Socket::GetAddrInfo::Emul.3 \
		Socket::GetAddrInfo::Socket6api.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501400
PLIST_SUB+=	OLD_PERL="" NEW_PERL="@comment "
.else
PLIST_SUB+=	OLD_PERL="@comment " NEW_PERL=""
.endif

.include <bsd.port.post.mk>
