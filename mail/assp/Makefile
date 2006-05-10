# New ports collection makefile for:	assp
# Date created:				16 May 2005
# Whom:					J.R. Oldroyd <fbsd@opal.com>
#
# $FreeBSD$
#

PORTNAME=	assp
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	assp

MAINTAINER=	fbsd@opal.com
COMMENT=	Anti-Spam SMTP Proxy

USE_ZIP=	yes
NO_BUILD=	yes
USE_PERL5_RUN=	yes

MAN8=		assp.8 assplog.8

ASSP_USER=	nobody
ASSP_GROUP=	nobody
ASSP_HOME=	/var/db/assp

PLIST_SUB=	ASSP_HOME="${ASSP_HOME}"

SUB_FILES=	assp.8 assplog.8 assp.sh periodic-assp.sh pkg-install
SUB_LIST=	ASSP_HOME="${ASSP_HOME}" ASSP_USER="${ASSP_USER}" \
		ASSP_GROUP="${ASSP_GROUP}" PERL="${PERL}"

USE_RC_SUBR=	assp.sh

OPTIONS=	EMVALID	"RFC822 recipient address validator" on \
		LDAP	"LDAP validation of recipient addresses" on \
		SPF	"SPF validation of client IP" on \
		CLAMAV	"ClamAV virus scanner" on \
		DNSBL	"DNS block list checking" on

.include <bsd.port.pre.mk>

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

.if !defined(WITHOUT_DNSBL)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS
.endif

.if !defined(WITHOUT_CLAMAV)
RUN_DEPENDS+=	wget:${PORTSDIR}/ftp/wget
PLIST_SUB+=	ASSP_CLAMAV=""
.else
PLIST_SUB+=	ASSP_CLAMAV="@comment "
.endif

EXTRACT_AFTER_ARGS=	-d ${PORTNAME}-${PORTVERSION}

pre-patch:
	@${REINPLACE_CMD} -e 's|.$$||' ${WRKSRC}/stats.sh

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
