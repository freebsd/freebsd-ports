PORTNAME=	Authen-CyrusSASL
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	bra@fsn.hu
COMMENT=	Perl5 module for accessing the SASL authentication daemon

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${MKDIR} ${WRKSRC}/lib
	@${RM} ${WRKSRC}/Authen/*.orig
	@${CP} -vpR ${WRKSRC}/Authen ${WRKSRC}/lib/

.include <bsd.port.mk>
