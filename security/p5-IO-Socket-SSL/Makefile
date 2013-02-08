# Created by: scrappy
# $FreeBSD$

PORTNAME=	IO-Socket-SSL
PORTVERSION=	1.83
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:SULLR
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 interface to SSL sockets

BUILD_DEPENDS=	p5-Net-SSLeay>=1.21:${PORTSDIR}/security/p5-Net-SSLeay
RUN_DEPENDS:=	${BUILD_DEPENDS}

OPTIONS_DEFINE=	EXAMPLES IDN IPV6

PERL_CONFIGURE=	yes
INSTALL_TARGET=	pure_install

MAN3=		IO::Socket::SSL.3
PORTEXAMPLES=	*

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIDN}
RUN_DEPENDS+=	p5-URI>=1.50:${PORTSDIR}/net/p5-URI
.endif

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-IP>=0.11:${PORTSDIR}/net/p5-IO-Socket-IP \
		p5-Socket>=1.95:${PORTSDIR}/net/p5-Socket
.endif

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	${MKDIR} ${EXAMPLESDIR}/
	${INSTALL_SCRIPT} ${WRKSRC}/example/* ${EXAMPLESDIR}/
.endif

regression-test: build
	cd ${WRKSRC}/ && ${MAKE} test

.include <bsd.port.mk>
