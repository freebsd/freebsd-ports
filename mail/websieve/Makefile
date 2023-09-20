PORTNAME=	websieve
PORTVERSION=	0.63.a
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${SIEVEVERSION}
DISTNAME?=	${PORTNAME}-${SIEVEVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web based Cyrus IMAP user admin client
WWW=		https://sourceforge.net/projects/websieve/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/GPL

SIEVEVERSION=	${PORTVERSION:S/.//g}

USES=		cpe perl5 shebangfix
CPE_VENDOR=	${PORTNAME}_project
USE_PERL5=	run

SHEBANG_FILES=	websieve.pl

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	pkg-message

OPTIONS_DEFAULT=	CYRUS CYRUS_IMAPD_25
OPTIONS_RADIO=	CYRDEP
OPTIONS_RADIO_CYRDEP=	CYRUS_IMAPD_25 CYRUS_IMAPD_30
OPTIONS_SINGLE=	TYPE
OPTIONS_SINGLE_TYPE=	PERL CYRUS

CYRDEP_DESC=	Which version of Cyrus IMAPd to depend on
CYRUS_DESC=	Depend on Cyrus IMAPd Perl modules
CYRUS_IMAPD_25_DESC=	Cyrus IMAPd version 2.5.x
CYRUS_IMAPD_30_DESC=	Cyrus IMAPd version 3.0.x
PERL_DESC=	Depend on generic Perl modules
TYPE_DESC=	Choose which sieve backend to use

CYRUS_VARS=	FUNCLIB_PL=funclib.cyrus
CYRUS_VARS_OFF=	FUNCLIB_PL=funclib.pl
CYRUS_IMAPD_25_RUN_DEPENDS=	${SITE_ARCH}/Cyrus/SIEVE/managesieve.pm:mail/cyrus-imapd25
CYRUS_IMAPD_30_RUN_DEPENDS=	${SITE_ARCH}/Cyrus/SIEVE/managesieve.pm:mail/cyrus-imapd30
PERL_PREVENTS=	CYRUS_IMAPD_25 CYRUS_IMAPD_30
PERL_PREVENTS_MSG=You cannot select a dependency on cyrus with the PERL option
PERL_RUN_DEPENDS=	p5-IMAP-Admin>=0:mail/p5-IMAP-Admin \
			p5-IMAP-Sieve>=0:mail/p5-IMAP-Sieve

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
