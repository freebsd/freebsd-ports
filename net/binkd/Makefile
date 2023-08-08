PORTNAME=	binkd
DISTVERSION=	1.1a-115
CATEGORIES=	net

MAINTAINER=	dz@dolik.dev
COMMENT=	Fidonet TCP/IP mailer
WWW=		https://github.com/pgul/binkd/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	pgul
GH_TAGNAME=	3bf55d5

USE_RC_SUBR=	binkd
GNU_CONFIGURE=	yes

MAKE_JOBS_UNSAFE=yes

USERS=		fido
GROUPS=		fido

OPTIONS_DEFINE=	ASO DOCS PROXY BWLIM PERL AFF NTLM

ASO_DESC=	Amiga Style Outbound (ASO) support
AFF_DESC=	Enable soft IP address family force feature
BWLIM_DESC=	Bandwidth limiting support
NTLM_DESC=	Enable NTLM proxy authorization support

ASO_CONFIGURE_WITH=	aso
BWLIM_CONFIGURE_WITH=	bwlim
AFF_CONFIGURE_WITH=	af-force
PROXY_CONFIGURE_WITH=	proxy
NTLM_CONFIGURE_WITH=	ntlm
PERL_CONFIGURE_WITH=	perl

pre-configure:
	@${CP} ${WRKSRC}/mkfls/unix/* ${WRKSRC}/

.include <bsd.port.mk>
