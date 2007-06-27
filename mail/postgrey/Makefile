# New ports collection makefile for:    postgrey
# Date created:				24 August 2004
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	postgrey
PORTVERSION=	1.28
CATEGORIES=	mail
MASTER_SITES=	http://postgrey.schweikert.ch/pub/ LOCAL/beech

MAINTAINER=	haroldp@internal.org
COMMENT=	Greylisting policy server for Postfix

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

USE_PERL5_RUN=	yes
USE_RC_SUBR=	postgrey
NO_BUILD=	yes
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

post-patch:
	@${REINPLACE_CMD} -e "s#/etc/#${PREFIX}/etc/#" ${WRKSRC}/postgrey
	@${REINPLACE_CMD} -e '/^my.*DEFAULT_DBDIR/s|/var/spool/postfix/postgrey|${PGY_DIR}|' \
	${WRKSRC}/postgrey

pre-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/policy-test ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport ${PREFIX}/sbin
	${MKDIR} ${PREFIX}/etc/postfix
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} ${PREFIX}/etc/postfix/dist-postgrey_${i}
.endfor

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
