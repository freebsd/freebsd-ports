# New ports collection makefile for:    postgrey
# Date created:				24 August 2004
# Whom:					Will Andrews <will@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	postgrey
PORTVERSION=	1.24
CATEGORIES=	mail
MASTER_SITES=	http://isg.ee.ethz.ch/tools/postgrey/pub/

MAINTAINER=	haroldp@internal.org
COMMENT=	Greylisting policy server for Postfix

RUN_DEPENDS=	${SITE_PERL}/Net/Server.pm:${PORTSDIR}/net/p5-Net-Server \
		${SITE_PERL}/IO/Multiplex.pm:${PORTSDIR}/devel/p5-IO-Multiplex \
		${SITE_PERL}/${PERL_ARCH}/BerkeleyDB.pm:${PORTSDIR}/databases/p5-BerkeleyDB

USE_PERL5_RUN=	yes
USE_RC_SUBR=	yes
NO_BUILD=	yes

ETCFILES=	whitelist_clients whitelist_recipients
PGY_USERNAME?=	postgrey
PGY_USERID?=	225
PGY_GROUPNAME?=	${PGY_USERNAME}
PGY_GROUPID?=	${PGY_USERID}
PGY_DIR?=	/var/db/postgrey

PKGINSTALL=	${WRKDIR}/pkg-install
PKGDEINSTALL=	${WRKDIR}/pkg-deinstall

.include <bsd.port.pre.mk>

# Sys::Syslog::openlog won't return 1 for success in perl 5.00503, and causes
# "Couldn't open syslog[] at ... Net/Server.pm line ..." problem.
# See the thread of http://lists.ee.ethz.ch/postgrey/msg00001.html
.if ${PERL_LEVEL} < 500600
IGNORE=	needs perl 5.6.0 or higher, install lang/perl5.8 and try again
.endif

post-patch:
	${REINPLACE_CMD} -e "s#/etc/#${PREFIX}/etc/#" ${WRKSRC}/postgrey

pre-install:
	${SED}	-e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%RC_SUBR%%#${RC_SUBR}#g' \
		${FILESDIR}/postgrey.sh > ${WRKDIR}/postgrey.sh
	${SED}	-e 's#%%USER%%#${PGY_USERNAME}#g' -e 's#%%UID%%#${PGY_USERID}#g' \
		-e 's#%%GROUP%%#${PGY_GROUPNAME}#g' -e 's#%%GID%%#${PGY_GROUPID}#g' \
		-e 's#%%PREFIX%%#${PREFIX}#g' -e 's#%%ETCFILES%%#${ETCFILES}#g' \
		-e 's#%%POSTGREYDIR%%#${PGY_DIR}#g' ${MASTERDIR}/pkg-install > \
		${PKGINSTALL}
	${SH} ${PKGINSTALL} ${PKGNAME} PRE-INSTALL

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/postgrey ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/postgreyreport ${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKDIR}/postgrey.sh ${PREFIX}/etc/rc.d
	${MKDIR} ${PREFIX}/etc/postfix
.for i in ${ETCFILES}
	${INSTALL_DATA} ${WRKSRC}/postgrey_${i} ${PREFIX}/etc/postfix/dist-postgrey_${i}
.endfor

post-install:
	${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
