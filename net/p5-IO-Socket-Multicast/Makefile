# Created by: Janos.Mohacsi@dante.org.uk
# $FreeBSD$

PORTNAME=	IO-Socket-Multicast
PORTVERSION=	1.12
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jmohacsi@bsd.hu
COMMENT=	Perl module to send and receive multicast messages

RUN_DEPENDS=	p5-IO-Interface>=0:${PORTSDIR}/net/p5-IO-Interface
BUILD_DEPENDS:=	${RUN_DEPENDS}

MAN3=		IO::Socket::Multicast.3

PERL_CONFIGURE=	yes

post-install:
.ifndef(NOPORTEXAMPLES)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
