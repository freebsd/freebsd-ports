# $FreeBSD$

PORTNAME=	Email-Outlook-Message
PORTVERSION=	0.919
CATEGORIES=	mail perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Read e-mail messages stored as .msg files

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

RUN_DEPENDS=	p5-Email-MIME>=0:mail/p5-Email-MIME \
	p5-Email-Sender>=0:mail/p5-Email-Sender \
	p5-Email-Simple>=2.206:mail/p5-Email-Simple \
	p5-IO-String>=0:devel/p5-IO-String \
	p5-OLE-Storage_Lite>=0:devel/p5-OLE-Storage_Lite

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
