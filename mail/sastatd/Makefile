# New ports collection makefile for:	sastatd
# Date created:				2010-01-12
# Whom:					Oleg A. Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=		sastatd
PORTVERSION=		0.05
CATEGORIES=		mail perl5
MASTER_SITES=		CPAN
MASTER_SITE_SUBDIR=	../by-authors/id/L/LO/LONERR

MAINTAINER=		oleg@mamontov.net
COMMENT=		SpamAssassin statistic collecting server

BUILD_DEPENDS=		p5-JSON-Any>=0:${PORTSDIR}/converters/p5-JSON-Any \
			p5-Log-Dispatch>=2.26:${PORTSDIR}/devel/p5-Log-Dispatch \
			p5-Pid-File-Flock>=0:${PORTSDIR}/devel/p5-Pid-File-Flock \
			p5-POE>=0:${PORTSDIR}/devel/p5-POE \
			p5-Sys-Syslog>=0.16:${PORTSDIR}/sysutils/p5-Sys-Syslog \

RUN_DEPENDS=		${BUILD_DEPENDS}

PERL_CONFIGURE=		yes

SASTATD_DBDIR?=		/var/db/sastatd
SASTATD_RUNDIR?=	/var/run/sastatd
SASTATD_USER?=		sastatd

USE_RC_SUBR=		sastatd

SUB_LIST+=		SASTATD_DBDIR=${SASTATD_DBDIR} \
			SASTATD_RUNDIR=${SASTATD_RUNDIR} \
			SASTATD_USER=${SASTATD_USER} \
			CHMOD="${CHMOD}" CHOWN="${CHOWN}" MKDIR="${MKDIR}" PW="${PW}"

PKGINSTALL=		${WRKDIR}/pkg-install
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall

SUB_FILES+=		pkg-install pkg-deinstall

MAN1=			sastatd.1

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
