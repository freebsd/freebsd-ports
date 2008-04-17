# New ports collection makefile for:	p5-Authen-CyrusSASL
# Date created:				October 05 2005
# Whom:					Attila Nagy <bra@fsn.hu>
#
# $FreeBSD$
#

PORTNAME=	Authen-CyrusSASL
PORTVERSION=	0.01
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bra@fsn.hu
COMMENT=	Perl5 module for accessing the SASL authentication daemon

PERL_CONFIGURE=	yes

MAN3=	Authen::CyrusSASL.3

post-patch:
	@${MKDIR} ${WRKSRC}/lib
	@${RM} ${WRKSRC}/Authen/*.orig
	@${CP} -vpR ${WRKSRC}/Authen ${WRKSRC}/lib/

.include <bsd.port.mk>
