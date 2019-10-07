# Created by: Oliver Eikemeier
# $FreeBSD$

PORTNAME=	swaks
PORTVERSION=	20190914.0
CATEGORIES=	mail
MASTER_SITES=	http://jetmore.org/john/code/swaks/

MAINTAINER=	beat@FreeBSD.org
COMMENT=	Swiss Army Knife SMTP transaction tester

LICENSE=	GPLv2

PLIST_FILES=	bin/${PORTNAME}

OPTIONS_DEFINE=	PERL_NET_DNS PERL_NET_SSLEAY PERL_AUTHEN_NTLM
PERL_NET_DNS_DESC=	Add MX lookup support
PERL_NET_SSLEAY_DESC=	Add TLS support
PERL_AUTHEN_NTLM_DESC=	Add support for AUTH NTLM

USES=		perl5 shebangfix
SHEBANG_FILES=	${PORTNAME}
USE_PERL5=	run
NO_BUILD=	yes

PERL_NET_DNS_RUN_DEPENDS=	p5-Net-DNS>=0:dns/p5-Net-DNS
PERL_NET_SSLEAY_RUN_DEPENDS=	p5-Net-SSLeay>=0:security/p5-Net-SSLeay
PERL_AUTHEN_NTLM_RUN_DEPENDS=	p5-Authen-NTLM>=0:security/p5-Authen-NTLM

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
