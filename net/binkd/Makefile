PORTNAME=	binkd
DISTVERSION=	1.1a-115
PORTREVISION=	1
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

MAKE_JOBS_UNSAFE=	yes

USERS=		fido
GROUPS=		fido

OPTIONS_DEFINE=	AFF ASO BWLIM DOCS NTLM PERL PROXY

AFF_DESC=	Enable soft IP address family force feature
ASO_DESC=	Amiga Style Outbound (ASO) support
BWLIM_DESC=	Bandwidth limiting support
NTLM_DESC=	Enable NTLM proxy authorization support

AFF_CONFIGURE_WITH=	af-force
ASO_CONFIGURE_WITH=	aso
BWLIM_CONFIGURE_WITH=	bwlim
NTLM_CONFIGURE_WITH=	ntlm
PERL_CONFIGURE_WITH=	perl
PROXY_CONFIGURE_WITH=	proxy

pre-configure:
	@${CP} ${WRKSRC}/mkfls/unix/* ${WRKSRC}/

post-install:
	${INSTALL_DATA} ${FILESDIR}/binkd.conf ${STAGEDIR}${PREFIX}/etc/binkd.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/binkd.conf-dist ${STAGEDIR}${PREFIX}/share/doc/binkd
	${MKDIR} ${STAGEDIR}/var/log
	${TOUCH} ${STAGEDIR}/var/log/binkd.log
	${MKDIR} ${STAGEDIR}/var/run/binkd
	${MKDIR} ${STAGEDIR}/var/spool/binkd
	${MKDIR} ${STAGEDIR}/var/spool/binkd/outbound
	${MKDIR} ${STAGEDIR}/var/spool/binkd/inbound-secure
	${MKDIR} ${STAGEDIR}/var/spool/binkd/inbound-unsecure
	${MKDIR} ${STAGEDIR}/var/spool/binkd/inbound-temp

.include <bsd.port.mk>
