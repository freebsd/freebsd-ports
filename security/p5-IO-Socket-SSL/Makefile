# New ports collection makefile for:	p5-IO-Socket-SSL
# Date created:				October 27th 2000
# Whom:	      				Marc G. Fournier <scrappy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-SSL
PORTVERSION=	1.27
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	jadawin@FreeBSD.org
COMMENT=	Perl5 interface to SSL sockets

RUN_DEPENDS=	p5-Net-SSLeay>=1.21:${PORTSDIR}/security/p5-Net-SSLeay
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		IO::Socket::SSL.3

OPTIONS=	IDN "International Domain Names (IDN) support" off

.if !defined(NOPORTEXAMPLES)
PORTEXAMPLES=	*
post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/example/* ${EXAMPLESDIR}
.endif

.if defined(WITH_IDN)
RUN_DEPENDS+=	p5-Net-LibIDN>=0:${PORTSDIR}/dns/p5-Net-LibIDN
.endif

.include <bsd.port.mk>
