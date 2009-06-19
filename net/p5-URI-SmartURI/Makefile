# New ports collection makefile for:	p5-URI-SmartURI
# Date created:				2008-07-09
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	URI-SmartURI
PORTVERSION=	0.029
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Subclassable and hostless URIs

BUILD_DEPENDS=	p5-Class-C3-Componentised>=0:${PORTSDIR}/devel/p5-Class-C3-Componentised	\
		p5-File-Find-Rule>=0:${PORTSDIR}/devel/p5-File-Find-Rule	\
		p5-Moose>=0:${PORTSDIR}/devel/p5-Moose				\
		p5-MRO-Compat>=0.09:${PORTSDIR}/devel/p5-MRO-Compat		\
		p5-URI>=0:${PORTSDIR}/net/p5-URI
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		URI::SmartURI.3

.include <bsd.port.mk>
