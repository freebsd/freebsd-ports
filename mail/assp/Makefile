# New ports collection makefile for:	assp
# Date created:				16 May 2005
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	assp
PORTVERSION=	1.5.1.2
PORTREVISION=	3
CATEGORIES=	mail
MASTER_SITES=	SF/${PORTNAME}/OldFiles
DISTNAME=	${PORTNAME:U}_${PORTVERSION}-Install

MAINTAINER=	fbsd@opal.com
COMMENT=	Anti-Spam SMTP Proxy

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN8=		assp.8 assplog.8

ASSP_USER=	assp
ASSP_GROUP=	assp
ASSP_UID=	587
ASSP_GID=	587
ASSP_HOME=	/var/db/assp
ASSP_LOG=	/var/log/assp

PLIST_SUB=	ASSP_HOME="${ASSP_HOME}" ASSP_LOG="${ASSP_LOG}"

SUB_FILES=	assp.8 assplog.8 assplog.pl periodic-assp.sh
SUB_LIST=	ASSP_USER="${ASSP_USER}" ASSP_GROUP="${ASSP_GROUP}" \
		ASSP_HOME="${ASSP_HOME}" ASSP_LOG="${ASSP_LOG}" \
		DATADIR="${DATADIR}" PERL="${PERL}"

USE_RC_SUBR=	${PORTNAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}

OPTIONS=	EMVALID	"RFC822 recipient address validator" on \
		LDAP	"LDAP validation of recipient addresses" off \
		SPF	"SPF validation of client IP" on \
		SRS	"Sender Rewriting Scheme" on \
		SEND	"Resending .eml files" on \
		FBACKW	"File Reading Backwards" on \
		ZLIB	"HTTP Header Compression on Admin Interface" on \
		CLAMAV	"ClamAV virus scanner" on \
		DNSBL	"DNS block list checking" on \
		MYSQL	"Use MySQL db to store white/red/delaylists" off \
		MATCHRE	"Match IP ranges and CIDR blocks in lists" on \
		SENDERB	"Country Code checks" on \
		MIMEMOD	"Multiple Attachement detection" on \
		SSL	"SSL secure sockets support" on \
		IPV6	"IPv6 sockets support" on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${DISTNAME}/${PORTNAME:U}

.include <bsd.port.pre.mk>

SUB_LIST+=	RC_SCRIPT=${RC_SCRIPT}${RC_SUBR_SUFFIX}

RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS+=	${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww

.if !defined(WITHOUT_EMVALID)
RUN_DEPENDS+=	${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid
.endif

.if !defined(WITHOUT_LDAP)
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.if !defined(WITHOUT_SPF)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SPF.pm:${PORTSDIR}/mail/p5-Mail-SPF
.endif

.if !defined(WITHOUT_SRS)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SRS.pm:${PORTSDIR}/mail/p5-Mail-SRS
.endif

.if !defined(WITHOUT_SEND)
RUN_DEPENDS+=	${SITE_PERL}/Email/Send.pm:${PORTSDIR}/mail/p5-Email-Send
.endif

.if !defined(WITHOUT_FBACKW)
RUN_DEPENDS+=	${SITE_PERL}/File/ReadBackwards.pm:${PORTSDIR}/devel/p5-File-ReadBackwards
.endif

.if !defined(WITHOUT_ZLIB)
RUN_DEPENDS+=	${SITE_PERL}/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	${SITE_PERL}/File/Scan/ClamAV.pm:${PORTSDIR}/security/p5-File-Scan-ClamAV
PLIST_SUB+=	ASSP_CLAMAV=""
.else
PLIST_SUB+=	ASSP_CLAMAV="@comment "
.endif

.if !defined(WITHOUT_DNSBL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
.endif

.if !defined(WITHOUT_MYSQL)
RUN_DEPENDS+=	${SITE_PERL}/Tie/RDBM.pm:${PORTSDIR}/databases/p5-Tie-DBI
.endif

.if !defined(WITHOUT_MATCHRE)
RUN_DEPENDS+=	${SITE_PERL}/Net/IP/Match/Regexp.pm:${PORTSDIR}/net-mgmt/p5-Net-IP-Match-Regexp
.endif

.if !defined(WITHOUT_SENDERB)
RUN_DEPENDS+=	${SITE_PERL}/Net/SenderBase.pm:${PORTSDIR}/mail/p5-Net-SenderBase
.endif

.if !defined(WITHOUT_MIMEMOD)
RUN_DEPENDS+=	${SITE_PERL}/Email/MIME/Modifier.pm:${PORTSDIR}/mail/p5-Email-MIME-Modifier
.endif

.if !defined(WITHOUT_SSL)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/SSL.pm:${PORTSDIR}/security/p5-IO-Socket-SSL
.endif

.if !defined(WITHOUT_IPV6)
RUN_DEPENDS+=	${SITE_PERL}/IO/Socket/INET6.pm:${PORTSDIR}/net/p5-IO-INET6
.endif

EXTRACT_AFTER_ARGS=	-d ${PORTNAME}-${PORTVERSION}

post-extract:
	@echo "===>  Removing incorrect group/other write permissions"
	@${FIND} ${WRKDIR}/${PORTNAME}-${PORTVERSION} -type d -exec ${CHMOD} go-w {} \;
	@${FIND} ${WRKDIR}/${PORTNAME}-${PORTVERSION} -type f -exec ${CHMOD} a-wx {} \;

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/*.pl

pre-install:
	if ! /usr/sbin/pw groupshow ${ASSP_GROUP}; then \
		/usr/sbin/pw groupadd ${ASSP_GROUP} -g ${ASSP_GID}; \
	else \
		${ECHO_CMD} "Using exsing ${ASSP_GROUP} group"; \
	fi; \
	if ! /usr/sbin/pw usershow ${ASSP_USER}; then \
		/usr/sbin/pw useradd ${ASSP_USER} -g ${ASSP_GROUP} -u ${ASSP_UID} -h - -d ${ASSP_HOME} -s /usr/sbin/nologin -c "ASSP Anti-Spam Proxy"; \
	else \
		${ECHO_CMD} "Using exsing ${ASSP_USER} user"; \
	fi

do-install:
	${MKDIR} ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/assp.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/move2num.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/rebuildspamdb.pl ${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/stat.pl ${DATADIR}
	${MKDIR} ${DATADIR}/files
	${INSTALL_DATA} ${WRKSRC}/files/* ${DATADIR}/files
	${MKDIR} ${DATADIR}/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${DATADIR}/images
	${MKDIR} ${DATADIR}/reports
	${INSTALL_DATA} ${WRKSRC}/reports/* ${DATADIR}/reports

	${LN} -s ${DATADIR}/assp.pl ${PREFIX}/sbin/assp

	${INSTALL_SCRIPT} ${WRKDIR}/assplog.pl ${PREFIX}/sbin/assplog

	${INSTALL_MAN} ${WRKDIR}/assp.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/assplog.8 ${MAN8PREFIX}/man/man8

	${MKDIR} ${ASSP_LOG}
	${CHOWN} ${ASSP_USER}:${ASSP_GROUP} ${ASSP_LOG}
	${CHMOD} 750 ${ASSP_LOG}

	${MKDIR} ${ASSP_HOME}
	${CHOWN} ${ASSP_USER}:${ASSP_GROUP} ${ASSP_HOME}
	${CHMOD} 700 ${ASSP_HOME}
	${LN} -s ${DATADIR}/files ${ASSP_HOME}
	${LN} -s ${DATADIR}/images ${ASSP_HOME}
	${LN} -s ${DATADIR}/reports ${ASSP_HOME}
	${LN} -s ${ASSP_LOG} ${ASSP_HOME}/logs

	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/periodic-assp.sh ${PREFIX}/etc/periodic/daily/510.assp

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.htm ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
