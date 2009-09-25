# New ports collection makefile for:	p5-IO-Socket-Multicast
# Date created:		21 March 2002
# Whom:	      		Janos.Mohacsi@dante.org.uk
#
# $FreeBSD$
#

PORTNAME=	IO-Socket-Multicast
PORTVERSION=	1.07
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	janos.mohacsi@bsd.hu
COMMENT=	Perl module to send and receive multicast messages

RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/IO/Interface.pm:${PORTSDIR}/net/p5-IO-Interface
BUILD_DEPENDS=	${RUN_DEPENDS}

MAN3=		IO::Socket::Multicast.3

PERL_CONFIGURE=	yes

post-install:
.ifndef(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
		${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
