# Created by: Sahil Tandon <sahil@tandon.net>
# $FreeBSD$

PORTNAME=	Socket-GetAddrInfo
PORTVERSION=	0.22
PORTREVISION=	2
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
		Socket::GetAddrInfo::Socket6api.3 \
		Socket::GetAddrInfo::Strict.3

USES=		perl5 shebangfix
USE_PERL5=	modbuild
SHEBANG_FILES=	bin/getaddrinfo bin/getnameinfo

NO_STAGE=	yes
.include <bsd.port.pre.mk>

# It only needs to compile stuff on perl older than 5.16.
.if ${PERL_LEVEL} < 501600
PLIST_SUB+=	OLD_PERL="" NEW_PERL="@comment "
.else
PLIST_SUB+=	OLD_PERL="@comment " NEW_PERL=""
.endif

.include <bsd.port.post.mk>
