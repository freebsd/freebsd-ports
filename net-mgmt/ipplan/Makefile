# Ports collection makefile for:  ipplan
# Date created:			  26 Nov 2004
# Whom:				  Maxim Tuliuk <mt@primats.org.ua>
#
# $FreeBSD$
#

PORTNAME=	ipplan
PORTVERSION=	4.92
CATEGORIES=	net-mgmt
MASTER_SITES=	SF/iptrack

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	IP address management and tracking

RUN_DEPENDS=	nmap:${PORTSDIR}/security/nmap

MAKE_JOBS_SAFE=	yes
USE_PERL5_RUN=	yes
USE_PHP=	gettext pcre xml zlib

NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}
IPPLANDIR?=	share/${PORTNAME}
CONFIG=		config.php
SUB_FILES=	pkg-message
PLIST_SUB=	IPPLANDIR=${IPPLANDIR}
SUB_LIST+=	IPPLANDIR=${IPPLANDIR}

.if !defined(WITHOUT_MYSQL)
USE_PHP+=	mysql
.endif

.if defined(WITH_PGSQL)
USE_PHP+=	pgsql
.endif

.if defined(WITH_SNMP)
USE_PHP+=	snmp
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/bin/perl|${PERL}|" \
		-e "s|/usr/bin/xsltproc|${LOCALBASE}/bin/xsltproc|" \
		${WRKSRC}/contrib/process-exports.pl
	@${REINPLACE_CMD} -e "s|/usr/local/bin/php|${LOCALBASE}/bin/php|" \
		${WRKSRC}/contrib/ipplan-poller.php
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" \
		${WRKSRC}/config.php
	@${FIND} ${WRKSRC} -name '*.orig' -delete -o -name '*.bak' -delete

pre-install:
	@${MV} ${WRKSRC}/${CONFIG} ${WRKSRC}/${CONFIG}.sample

do-install:
	@${MKDIR} ${PREFIX}/${IPPLANDIR}
	@cd ${WRKSRC} && ${FIND} * | \
	${CPIO} -dlmp -R ${SHAREOWN}:${SHAREGRP} ${PREFIX}/${IPPLANDIR}

post-install:
.if !exists(${PREFIX}/${IPPLANDIR}/${CONFIG})
	@${INSTALL_DATA} ${WRKSRC}/${CONFIG}.sample \
	${PREFIX}/${IPPLANDIR}/${CONFIG}
.endif
	@${MKDIR} -m 700 /var/spool/ipplan/uploads \
		/var/spool/ipplan/exportdns
	@${CHOWN} -R www:www /var/spool/ipplan
.if defined(WITH_PGSQL)
	@${REINPLACE_CMD} -e 's|INSTALL|INSTALL-POSTGRESQL|g' ${PKGMESSAGE}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
