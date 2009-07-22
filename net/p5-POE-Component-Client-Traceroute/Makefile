# New ports collection makefile for:	p5-POE-Component-Client-Traceroute
# Date created:		2006-08-09
# Whom:			Jin-Shan Tseng <tjs@cdpa.nsysu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	POE-Component-Client-Traceroute
PORTVERSION=	0.21
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	tjs@cdpa.nsysu.edu.tw
COMMENT=	A non-blocking traceroute client

RUN_DEPENDS=	p5-POE>=0.11:${PORTSDIR}/devel/p5-POE
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	POE::Component::Client::Traceroute.3

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>   Installing examples for ${PKGNAME}"
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif

.include <bsd.port.mk>
