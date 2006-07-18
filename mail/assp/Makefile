# New ports collection makefile for:	assp
# Date created:				16 May 2005
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	assp
PORTVERSION=	1.2.2
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME:U}_${PORTVERSION}-install

MAINTAINER=	fbsd@opal.com
COMMENT=	Anti-Spam SMTP Proxy

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

USE_DOS2UNIX=	addservice.pl \
		assp.pl \
		changelog.txt \
		freshclam.sh \
		move2num.pl \
		nodelay.txt \
		notspamreport.txt \
		rebuildspamdb.pl \
		redre.txt \
		redremovereport.txt \
		redreport.txt \
		repair.pl \
		spamreport.txt \
		stat.pl \
		stats.sh \
		whiteremovereport.txt \
		whitereport.txt

MAN8=		assp.8 assplog.8

ASSP_USER=	nobody
ASSP_GROUP=	nobody
ASSP_HOME=	/var/db/assp

PLIST_SUB=	ASSP_HOME="${ASSP_HOME}"

SUB_FILES=	assp.8 assplog.8 periodic-assp.sh pkg-install
SUB_LIST=	ASSP_HOME="${ASSP_HOME}" ASSP_USER="${ASSP_USER}" \
		ASSP_GROUP="${ASSP_GROUP}" PERL="${PERL}"

USE_RC_SUBR=	${PORTNAME}
RC_SCRIPT=	${PREFIX}/etc/rc.d/${PORTNAME}

OPTIONS=	EMVALID	"RFC822 recipient address validator" on \
		LDAP	"LDAP validation of recipient addresses" on \
		SPF	"SPF validation of client IP" on \
		SRS	"Sender Rewriting Scheme" on \
		FBACKW	"File Reading Backwards" on \
		ZLIB	"HTTP Header Compression on Admin Interface" on \
		CLAMAV	"ClamAV virus scanner" on \
		DNSBL	"DNS block list checking" on

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/${PORTNAME:U}

.include <bsd.port.pre.mk>

.if (${OSVERSION} >= 700007 || ( ${OSVERSION} < 700000 && ${OSVERSION} >= 600101 ))
SUB_LIST+=	RC_SCRIPT=${RC_SCRIPT}
.else
SUB_LIST+=	RC_SCRIPT=${RC_SCRIPT}.sh
.endif

.if !defined(WITHOUT_EMVALID)
RUN_DEPENDS+=	${SITE_PERL}/Email/Valid.pm:${PORTSDIR}/mail/p5-Email-Valid
.endif

.if !defined(WITHOUT_LDAP)
RUN_DEPENDS+=	${SITE_PERL}/Net/LDAP.pm:${PORTSDIR}/net/p5-perl-ldap
.endif

.if !defined(WITHOUT_SPF)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
RUN_DEPENDS+=	${SITE_PERL}/Mail/SPF/Query.pm:${PORTSDIR}/mail/p5-Mail-SPF-Query
.endif

.if !defined(WITHOUT_SRS)
RUN_DEPENDS+=	${SITE_PERL}/Mail/SRS.pm:${PORTSDIR}/mail/p5-Mail-SRS
.endif

.if !defined(WITHOUT_FBACKW)
RUN_DEPENDS+=	${SITE_PERL}/File/ReadBackwards.pm:${PORTSDIR}/devel/p5-File-ReadBackwards
.endif

.if !defined(WITHOUT_ZLIB)
RUN_DEPENDS+=	${SITE_PERL}/mach/Compress/Zlib.pm:${PORTSDIR}/archivers/p5-Compress-Zlib
.endif

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
PLIST_SUB+=	ASSP_CLAMAV=""
.else
PLIST_SUB+=	ASSP_CLAMAV="@comment "
.endif

.if !defined(WITHOUT_DNSBL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
.endif

EXTRACT_AFTER_ARGS=	-d ${PORTNAME}-${PORTVERSION}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/bin/perl|${PERL}|' ${WRKSRC}/*.pl

do-install:
	${MKDIR} ${PREFIX}/lib/assp
	${INSTALL_SCRIPT} ${WRKSRC}/*.pl ${PREFIX}/lib/assp
	${INSTALL_SCRIPT} ${WRKSRC}/stats.sh ${PREFIX}/lib/assp
.if defined(WITH_CLAMAV)
	${INSTALL_SCRIPT} ${WRKSRC}/freshclam.sh ${PREFIX}/lib/assp
.endif
	${INSTALL_DATA} ${WRKSRC}/*report.txt ${PREFIX}/lib/assp
	${INSTALL_DATA} ${WRKSRC}/nodelay.txt ${PREFIX}/lib/assp
	${INSTALL_DATA} ${WRKSRC}/redre.txt ${PREFIX}/lib/assp

	${MKDIR} ${PREFIX}/lib/assp/images
	${INSTALL_DATA} ${WRKSRC}/images/* ${PREFIX}/lib/assp/images

	${LN} -s ${PREFIX}/lib/assp/assp.pl ${PREFIX}/sbin/assp
	${LN} -s ${PREFIX}/lib/assp/stats.sh ${PREFIX}/sbin/assplog

	${INSTALL_MAN} ${WRKDIR}/assp.8 ${MAN8PREFIX}/man/man8
	${INSTALL_MAN} ${WRKDIR}/assplog.8 ${MAN8PREFIX}/man/man8

	${MKDIR} ${PREFIX}/etc/periodic/daily
	${INSTALL_SCRIPT} ${WRKDIR}/periodic-assp.sh ${PREFIX}/etc/periodic/daily/510.assp

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.htm ${DOCSDIR}
.endif

post-install:
	@PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
