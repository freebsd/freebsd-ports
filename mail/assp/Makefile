# Created by: J.R. Oldroyd <fbsd@opal.com>
# $FreeBSD$

PORTNAME=	assp
PORTVERSION=	1.9.9.13257
PORTEPOCH=	1
CATEGORIES=	mail
MASTER_SITES=	http://www.ringofsaturn.com/distfiles/
DISTNAME=	${PORTNAME:U}_${PORTVERSION}_Install

MAINTAINER=	rnejdl@ringofsaturn.com
COMMENT=	Anti-Spam SMTP Proxy

USES=		perl5 zip
NO_BUILD=	yes
USE_PERL5=	run

MAN8=		assp.8 assplog.8

ASSP_USER=	assp
ASSP_GROUP=	assp
USERS=		${ASSP_USER}
GROUPS=		${ASSP_GROUP}
ASSP_HOME=	/var/db/assp
ASSP_LOG=	/var/log/assp

PLIST_SUB=	ASSP_HOME="${ASSP_HOME}" ASSP_LOG="${ASSP_LOG}"

SUB_FILES=	510.assp assp.8 assplog.8 assplog.pl pkg-install
SUB_LIST=	ASSP_USER="${ASSP_USER}" ASSP_GROUP="${ASSP_GROUP}" \
		ASSP_HOME="${ASSP_HOME}" ASSP_LOG="${ASSP_LOG}" \
		DATADIR="${DATADIR}" PERL="${PERL}"

USE_RC_SUBR=	${PORTNAME}

OPTIONS_DEFINE=	EMVALID LDAP SPF SRS SEND FBACKW CLAMAV DNSBL MYSQL \
		MATCHRE SENDERB MIMEMOD SSL IPV6

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

OPTIONS_DEFAULT=	EMVALID SPF SRS SEND FBACKW CLAMAV DNSBL MATCHRE SENDERB MIMEMOD SSL IPV6

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/ASSP_1.9.9_13227_install/${PORTNAME:U}

NO_STAGE=	yes
.include <bsd.port.pre.mk>

RUN_DEPENDS+=	p5-Net-DNS>=0.68:${PORTSDIR}/dns/p5-Net-DNS \
		p5-libwww>=6.04:${PORTSDIR}/www/p5-libwww \
		p5-HTML-Parser>=3.69:${PORTSDIR}/www/p5-HTML-Parser

.if ${PORT_OPTIONS:MEMVALID}
RUN_DEPENDS+=	p5-Email-Valid>=0.190:${PORTSDIR}/mail/p5-Email-Valid
.endif

.if ${PORT_OPTIONS:MLDAP}
RUN_DEPENDS+=	p5-perl-ldap>=0.4400:${PORTSDIR}/net/p5-perl-ldap
.endif

.if ${PORT_OPTIONS:MSPF}
RUN_DEPENDS+=	p5-Mail-SPF>=2.007:${PORTSDIR}/mail/p5-Mail-SPF
.endif

.if ${PORT_OPTIONS:MSRS}
RUN_DEPENDS+=	p5-Mail-SRS>=0.31:${PORTSDIR}/mail/p5-Mail-SRS
.endif

.if ${PORT_OPTIONS:MSEND}
RUN_DEPENDS+=	p5-Email-Send>=2.198:${PORTSDIR}/mail/p5-Email-Send
.endif

.if ${PORT_OPTIONS:MFBACKW}
RUN_DEPENDS+=	p5-File-ReadBackwards>=1.05:${PORTSDIR}/devel/p5-File-ReadBackwards
.endif

.if ${PORT_OPTIONS:MCLAMAV}
RUN_DEPENDS+=	p5-File-Scan-ClamAV>=1.9.1:${PORTSDIR}/security/p5-File-Scan-ClamAV
PLIST_SUB+=	ASSP_CLAMAV=""
.else
PLIST_SUB+=	ASSP_CLAMAV="@comment "
.endif

.if ${PORT_OPTIONS:MDNSBL}
RUN_DEPENDS+=	p5-Net-DNS>=0.68:${PORTSDIR}/dns/p5-Net-DNS
.endif

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	p5-Tie-DBI>=1.05:${PORTSDIR}/databases/p5-Tie-DBI
.endif

.if ${PORT_OPTIONS:MMATCHRE}
RUN_DEPENDS+=	p5-Net-IP-Match-Regexp>=1.01:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-Regexp
.endif

.if ${PORT_OPTIONS:MSENDERB}
RUN_DEPENDS+=	p5-Net-SenderBase>=1.02:${PORTSDIR}/mail/p5-Net-SenderBase
.endif

.if ${PORT_OPTIONS:MMIMEMOD}
RUN_DEPENDS+=	p5-Email-MIME>=1.910:${PORTSDIR}/mail/p5-Email-MIME
.endif

.if ${PORT_OPTIONS:MSSL}
RUN_DEPENDS+=	p5-IO-Socket-SSL>=1.74:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if ${PORT_OPTIONS:MIPV6}
RUN_DEPENDS+=	p5-IO-Socket-INET6>=2.69:${PORTSDIR}/net/p5-IO-Socket-INET6
.endif

EXTRACT_AFTER_ARGS=	-d ${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/*.pl

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/assp.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rebuildspamdb.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/stat.pl ${DATADIR}

	( cd ${WRKSRC} && ${COPYTREE_SHARE} "files images reports" \
		${DATADIR}/ "! -name '*.orig' ! -name '*.bak'" )

	${INSTALL_SCRIPT} ${WRKDIR}/assplog.pl ${PREFIX}/sbin/assplog

	${INSTALL_MAN} ${WRKDIR}/assp.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/assplog.8 ${MAN8PREFIX}/man/man8

	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/510.assp ${PREFIX}/etc/periodic/daily/

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.htm ${DOCSDIR}
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
