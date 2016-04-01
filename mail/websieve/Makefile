# Created by: Oliver Eikemeier <eikemeier@fillmore-labs.com>
# $FreeBSD$

PORTNAME=	websieve
PORTVERSION=	0.63.a
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${DISTVERSION}
DISTNAME?=	${PORTNAME}-${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based Cyrus IMAP user admin client

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

DISTVERSION=	063a

USES=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	websieve.pl

NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_SINGLE=	TYPE
OPTIONS_SINGLE_TYPE=	PERL CYRUS
OPTIONS_RADIO=	CYRDEP
OPTIONS_RADIO_CYRDEP=	CYRUS_IMAPD_23 CYRUS_IMAPD_24 CYRUS_IMAPD_25
OPTIONS_DEFAULT=	CYRUS CYRUS_IMAPD_24

TYPE_DESC=	Choose which sieve backend to use
PERL_DESC=	Depend on generic Perl modules
CYRUS_DESC=	Depend on Cyrus IMAPd Perl modules
CYRDEP_DESC=	Which version of Cyrus IMAPd to depend on
CYRUS_IMAPD_23_DESC=	Cyrus IMAPd version 2.3.x
CYRUS_IMAPD_24_DESC=	Cyrus IMAPd version 2.4.x
CYRUS_IMAPD_25_DESC=	Cyrus IMAPd version 2.5.x

CYRUS_IMAPD_25_RUN_DEPENDS=	${SITE_ARCH}/Cyrus/SIEVE/managesieve.pm:mail/cyrus-imapd25
CYRUS_IMAPD_24_RUN_DEPENDS=	${SITE_ARCH}/Cyrus/SIEVE/managesieve.pm:mail/cyrus-imapd24
CYRUS_IMAPD_23_RUN_DEPENDS=	${SITE_ARCH}/Cyrus/SIEVE/managesieve.pm:mail/cyrus-imapd23

PERL_RUN_DEPENDS=	p5-IMAP-Admin>=0:mail/p5-IMAP-Admin \
			p5-IMAP-Sieve>=0:mail/p5-IMAP-Sieve

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCYRUS}
FUNCLIB_PL=	funclib.cyrus
.else
FUNCLIB_PL=	funclib.pl
.endif

SUB_FILES=	pkg-message

_check-config: my-check-config
my-check-config:
.if ${PORT_OPTIONS:MPERL}
.if !empty(PORT_OPTIONS:MCYRUS_IMAPD_23) || !empty(PORT_OPTIONS:MCYRUS_IMAPD_24) || !empty(PORT_OPTIONS:MCYRUS_IMAPD_25)
	@${ECHO_MSG} "====> You cannot select a dependency on cyrus with the PERL option"
_CHECK_CONFIG_ERROR=	true
.endif
.endif

post-configure:
	@${REINPLACE_CMD} -e "s,require[ 	]*'\./\([^']*\)',require '${PREFIX}/etc/websieve/\1'," \
		${WRKSRC}/websieve.pl

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/websieve.pl ${STAGEDIR}${WWWDIR}/websieve.pl
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/websieve
	${INSTALL_DATA} ${WRKSRC}/websieve.conf ${STAGEDIR}${PREFIX}/etc/websieve/websieve.conf.sample
	${INSTALL_DATA} ${WRKSRC}/${FUNCLIB_PL} ${STAGEDIR}${PREFIX}/etc/websieve/funclib.pl

.include <bsd.port.mk>
