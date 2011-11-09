# New ports collection makefile for:    postgrey
# Date created:				24 August 2004
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postgrey
PORTVERSION=	1.34
PORTREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/ \
		http://postgrey.schweikert.ch/pub/old/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	Greylisting policy server for Postfix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex \
		${SITE_PERL}/Parse/Syslog.pm:${PORTSDIR}/textproc/p5-Parse-Syslog \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB \
		${SITE_PERL}/${PERL_ARCH}/Net/DNS.pm:${PORTSDIR}/dns/p5-Net-DNS

USE_PERL5_RUN=	yes
USE_RC_SUBR=	${PORTNAME}
NO_BUILD=	yes
POD2MAN?=	pod2man
PORTDOCS=	README Changes README.exim
MAN1=		${PORTNAME}.1 policy-test.1 postgreyreport.1

PGY_DBDIR=	/var/db/postgrey

USERS?=		postgrey
GROUPS?=	postgrey

PLIST_SUB=	DBDIR=${PGY_DBDIR} 

SUB_FILES=	${PORTNAME} pkg-install pkg-message
SUB_LIST=	USER=${USERS} GROUP=${GROUPS} DBDIR=${PGY_DBDIR}

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/main.cf#/etc/postfix/main.cf#' ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e 's#/etc/postfix#${ETCDIR}#' ${WRKSRC}/postgrey ${WRKSRC}/postgrey_whitelist_*
	@${REINPLACE_CMD} -e 's#/var/spool/postfix/postgrey#${PGY_DBDIR}#' ${WRKSRC}/postgrey ${WRKSRC}/contrib/postgreyreport
	@${REINPLACE_CMD} -e 's#nogroup#${GROUPS}#' ${WRKSRC}/postgrey

do-install:
	@${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	@${POD2MAN} ${WRKSRC}/policy-test ${WRKSRC}/policy-test.1
	@${POD2MAN} ${WRKSRC}/contrib/postgreyreport ${WRKSRC}/postgreyreport.1
	@${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/policy-test ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport ${PREFIX}/sbin
	@${INSTALL} -d ${ETCDIR}
.for file in postgrey_whitelist_clients postgrey_whitelist_recipients
	${INSTALL_DATA} ${WRKSRC}/${file} ${ETCDIR}/dist-${file}
	@${CP} -n ${ETCDIR}/dist-${file} ${ETCDIR}/${file}
.endfor

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
