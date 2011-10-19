# New ports collection makefile for:    postgrey
# Date created:				24 August 2004
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postgrey
PORTVERSION=	1.34
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/ \
		http://postgrey.schweikert.ch/pub/old/

MAINTAINER=	ports.maintainer@evilphi.com
COMMENT=	Greylisting policy server for Postfix

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
SUB_FILES=	pkg-install
SUB_LIST=	USER=${PGY_USERNAME} UID=${PGY_USERID} GROUP=${PGY_GROUPNAME} \
		GID=${PGY_GROUPID} ETCFILES="${ETCFILES}" \
		POSTGREYDIR=${PGY_DIR}
ETCFILES=	whitelist_clients whitelist_recipients
PGY_USERNAME?=	postgrey
PGY_USERID?=	225
PGY_GROUPNAME?=	${PGY_USERNAME}
PGY_GROUPID?=	${PGY_USERID}
PGY_DIR?=	/var/db/postgrey

USERS=		${PGY_USERNAME}
GROUPS=		${PGY_GROUPNAME}
MAN1=		${PORTNAME}.1 policy-test.1 postgreyreport.1

post-patch:
	@${REINPLACE_CMD} -e 's#/etc/main.cf#/etc/postfix/main.cf#' ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e 's#/etc/postfix#${PREFIX}&#' ${WRKSRC}/postgrey ${WRKSRC}/postgrey_whitelist_*
	@${REINPLACE_CMD} -e 's#/var/spool/postfix/postgrey#${PGY_DIR}#' ${WRKSRC}/postgrey ${WRKSRC}/contrib/postgreyreport

do-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL
	@${POD2MAN} ${WRKSRC}/${PORTNAME} ${WRKSRC}/${PORTNAME}.1
	@${POD2MAN} ${WRKSRC}/policy-test ${WRKSRC}/policy-test.1
	@${POD2MAN} ${WRKSRC}/contrib/postgreyreport ${WRKSRC}/postgreyreport.1
	@${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/policy-test ${PREFIX}/sbin
	@${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport ${PREFIX}/sbin
	@${INSTALL} -d ${PREFIX}/etc/postfix
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} ${PREFIX}/etc/postfix/dist-postgrey_${i}
.endfor

.if !defined(NOPORTDOCS)
	@${INSTALL} -d ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif
	@cd ${WRKSRC} && ${INSTALL_MAN} ${MAN1} ${MANPREFIX}/man/man1

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
