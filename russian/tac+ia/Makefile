# New ports collection makefile for:   tas
# Date created:        11 Jan 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	tac+ia
PORTVERSION=	0.96p9.3
CATEGORIES=	russian net
MASTER_SITES=	ftp://ftp.vsu.ru/pub/hardware/cisco/tacacs/
DISTNAME=	tac+ia-0.96pre9.3

MAINTAINER=	anton@chelcom.ru
COMMENT=	The Cisco remote aaa server (inet-admins edition)

WRKSRC=		${WRKDIR}/tac+ia-0.96pre9.3

MANCOMPRESSED=	no
MAN1=		macct.1 parrot.1
MAN8=		tac_plus.8

HAS_CONFIGURE=	yes

# Default prefix for config files
CONFIGURE_ARGS+=	--enable-confpath=${PREFIX}/etc/tac_plus
# Default prefix for pid files
CONFIGURE_ARGS+=	--enable-runpath=/var/run
# Default prefix for log files
CONFIGURE_ARGS+=	--enable-logpath=/var/log/tac_plus
#
CONFIGURE_ARGS+=	--enable-ttysfile=${PREFIX}/etc/tac_plus/ttys
# This file tac+ will use for accounting records.
# Can be redefined in config file ('accounting file' directive)
CONFIGURE_ARGS+=	--enable-acctfile=/var/log/tac_plus/tac_plus.acct
# If you want to block access for users, which not exist in base
CONFIGURE_ARGS+=	--enable-db-strict
#
CONFIGURE_ARGS+=	--enable-aliasesfile=${PREFIX}/etc/tac_plus/aliases
# register NAS users on SIGUSR1
CONFIGURE_ARGS+=	--enable-regnas
# Support for ACL
CONFIGURE_ARGS+=	--enable-acl
#
CONFIGURE_ARGS+=	--disable-deny
CONFIGURE_ARGS+=	--disable-cron

post-build:
	@mv ${WRKSRC}/tac_plus/tac_plus.1 ${WRKSRC}/tac_plus/tac_plus.8

post-install:
	@if [ ! -f ${PREFIX}/etc/rc.d/tac_plus.sh ]; then \
		${ECHO} "Installing ${PREFIX}/etc/rc.d/tac_plus.sh startup file."; \
		${INSTALL_SCRIPT} -m 751 ${FILESDIR}/tac_plus.sh ${PREFIX}/etc/rc.d/tac_plus.sh; \
	fi
	${INSTALL_SCRIPT} -m 644 ${WRKSRC}/lib/libutil/ttys ${PREFIX}/etc/tac_plus/ttys.example
	${INSTALL_SCRIPT} -m 644 ${WRKSRC}/tac_plus/aliases ${PREFIX}/etc/tac_plus/aliases.example
	${INSTALL_SCRIPT} -m 644 ${WRKSRC}/tac_plus/tac_plus.conf ${PREFIX}/etc/tac_plus/tac_plus.conf.example
	-@mkdir -p ${PREFIX}/share/doc/tac_plus
	${INSTALL_SCRIPT} -m 644 ${WRKSRC}/tac_plus/users_guide ${PREFIX}/share/doc/tac_plus/users_guide
	${INSTALL_SCRIPT} -m 644 ${WRKSRC}/README ${PREFIX}/share/doc/tac_plus/README

.include <bsd.port.mk>
