# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	assp
PORTVERSION=	1.9.9.14158
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ringofsaturn.com/distfiles/
DISTNAME=	${PORTNAME:tu}_${PORTVERSION}_Install

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Anti-Spam SMTP Proxy

RUN_DEPENDS=	p5-Net-DNS>=0.68:dns/p5-Net-DNS \
		p5-libwww>=6.04:www/p5-libwww \
		p5-HTML-Parser>=3.69:www/p5-HTML-Parser

USES=		perl5 zip:infozip shebangfix
SHEBANG_FILES=	*.pl
NO_BUILD=	yes
NO_ARCH=	yes
USE_PERL5=	run

ASSP_USER=	assp
ASSP_GROUP=	assp
USERS=		${ASSP_USER}
GROUPS=		${ASSP_GROUP}
ASSP_HOME=	/var/db/assp
ASSP_LOG=	/var/log/assp

PLIST_SUB=	ASSP_HOME="${ASSP_HOME}" ASSP_LOG="${ASSP_LOG}" \
		ASSP_USER="${ASSP_USER}" ASSP_GROUP="${ASSP_GROUP}"

SUB_FILES=	510.assp assp.8 assplog.8 assplog.pl
SUB_LIST=	ASSP_USER="${ASSP_USER}" ASSP_GROUP="${ASSP_GROUP}" \
		ASSP_HOME="${ASSP_HOME}" ASSP_LOG="${ASSP_LOG}" \
		DATADIR="${DATADIR}" PERL="${PERL}"

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	EMVALID LDAP SPF SRS SEND FBACKW CLAMAV DNSBL MYSQL \
		MATCHRE SENDERB MIMEMOD SSL IPV6 DOCS

EMVALID_DESC=	RFC822 recipient address validator
LDAP_DESC=	LDAP validation of recipient addresses
SPF_DESC=	SPF validation of client IP
SRS_DESC=	Sender Rewriting Scheme
SEND_DESC=	Resending .eml files
FBACKW_DESC=	File Reading Backwards
CLAMAV_DESC=	ClamAV virus scanner
DNSBL_DESC=	DNS block list checking
MYSQL_DESC=	Use MySQL db to store white/red/delaylists
MATCHRE_DESC=	Match IP ranges and CIDR blocks in lists
SENDERB_DESC=	Country Code checks
MIMEMOD_DESC=	Multiple Attachement detection
SSL_DESC=	SSL secure sockets support
IPV6_DESC=	IPv6 sockets support

OPTIONS_DEFAULT=	EMVALID SPF SRS SEND FBACKW CLAMAV DNSBL MATCHRE SENDERB MIMEMOD SSL

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ASSP_1.9.9_14158_install/${PORTNAME:tu}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEMVALID}
RUN_DEPENDS+=	p5-Email-Valid>=0.190:mail/p5-Email-Valid
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-perl-ldap>=0.4400:net/p5-perl-ldap
.endif

.if ${PORT_OPTIONS:MSPF}
RUN_DEPENDS+=	p5-Mail-SPF>=2.007:mail/p5-Mail-SPF
.endif

.if ${PORT_OPTIONS:MSRS}
RUN_DEPENDS+=	p5-Mail-SRS>=0.31:mail/p5-Mail-SRS
.endif

.if ${PORT_OPTIONS:MSEND}
RUN_DEPENDS+=	p5-Email-Send>=2.198:mail/p5-Email-Send
.endif

.if ${PORT_OPTIONS:MFBACKW}
RUN_DEPENDS+=	p5-File-ReadBackwards>=1.05:devel/p5-File-ReadBackwards
.endif

.if ${PORT_OPTIONS:MCLAMAV}
RUN_DEPENDS+=	p5-File-Scan-ClamAV>=1.9.1:security/p5-File-Scan-ClamAV
PLIST_SUB+=	ASSP_CLAMAV=""
.else
PLIST_SUB+=	ASSP_CLAMAV="@comment "
.endif

.if ${PORT_OPTIONS:MDNSBL}
RUN_DEPENDS+=	p5-Net-DNS>=0.68:dns/p5-Net-DNS
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-Tie-DBI>=1.05:databases/p5-Tie-DBI
RUN_DEPENDS+=	p5-DBD-mysql>=0:databases/p5-DBD-mysql
.endif

.if ${PORT_OPTIONS:MMATCHRE}
RUN_DEPENDS+=	p5-Net-IP-Match-Regexp>=1.01:net-mgmt/p5-Net-IP-Match-Regexp
.endif

.if ${PORT_OPTIONS:MSENDERB}
RUN_DEPENDS+=	p5-Net-SenderBase>=1.02:mail/p5-Net-SenderBase
.endif

.if ${PORT_OPTIONS:MMIMEMOD}
RUN_DEPENDS+=	p5-Email-MIME>=1.910:mail/p5-Email-MIME
.endif

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=1.74:security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>=2.69:net/p5-IO-Socket-INET6
.endif

EXTRACT_AFTER_ARGS=	-d ${PORTNAME}-${PORTVERSION}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}/images \
		${STAGEDIR}${DATADIR}/logs ${STAGEDIR}${DATADIR}/reports
	${INSTALL_SCRIPT} ${WRKSRC}/assp.pl ${STAGEDIR}${DATADIR}
	(cd ${STAGEDIR} && ${LN} -sf ${DATADIR}/assp.pl ${STAGEDIR}${PREFIX}/sbin/assp)
	${INSTALL_SCRIPT} ${WRKSRC}/rebuildspamdb.pl ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/stat.pl ${STAGEDIR}${DATADIR}

	( cd ${WRKSRC} && ${COPYTREE_SHARE} "files images reports" \
		${STAGEDIR}${DATADIR}/ "! -name '*.orig' ! -name '*.bak'" )

	${INSTALL_SCRIPT} ${WRKDIR}/assplog.pl ${STAGEDIR}${PREFIX}/sbin/assplog

	${INSTALL_MAN} ${WRKDIR}/assp.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/assplog.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/510.assp ${STAGEDIR}${PREFIX}/etc/periodic/daily/
	@${MKDIR} ${STAGEDIR}${ASSP_HOME}
	@${MKDIR} ${STAGEDIR}${ASSP_LOG}
.for f in files images rebuildspamdb.pl reports
	${LN} -sf ${DATADIR}/${f} ${STAGEDIR}${ASSP_HOME}/
.endfor
	${LN} -sf ${ASSP_LOG} ${STAGEDIR}${ASSP_HOME}/logs

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.htm ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
