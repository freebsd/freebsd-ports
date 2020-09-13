# $FreeBSD$

PORTNAME=	Email-Outlook-Message
PORTVERSION=	0.920
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Read e-mail messages stored as .msg files

LICENSE=	ART10 GPLv1+
LICENSE_COMB=	dual

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Email-Address>=0:mail/p5-Email-Address \
		p5-Email-MIME>=1.949:mail/p5-Email-MIME \
		p5-Email-MIME-ContentType>=1.014:mail/p5-Email-MIME-ContentType \
		p5-Email-Sender>=1.3:mail/p5-Email-Sender \
		p5-Email-Simple>=2.206:mail/p5-Email-Simple \
		p5-IO-All>=0:devel/p5-IO-All \
		p5-IO-String>=0:devel/p5-IO-String \
		p5-OLE-Storage_Lite>=0.14:devel/p5-OLE-Storage_Lite

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
