# New ports collection makefile for:    arpwatch
# Date created:         March 24 1997
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arpwatch
PORTVERSION=	2.1.a15
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([^\.]*)$/\1/}

MAINTAINER=	tabthorpe@FreeBSD.org
COMMENT=	Monitor arp & rarp requests

MAKE_JOBS_SAFE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
MAKE_ENV+=	BINOWN="${BINOWN}" BINGRP="${BINGRP}"
INSTALL_TARGET=	install install-man
MAN8=		arpwatch.8 arpsnmp.8

SUB_FILES=	pkg-message
USE_RC_SUBR=	arpwatch

.ifdef ARPDIR
MAKE_ARGS=	ARPDIR=${ARPDIR}
.endif

post-install:
	if [ ! -d ${PREFIX}/arpwatch ]; then				\
		${MKDIR} ${PREFIX}/arpwatch;				\
		${CHMOD} 755 ${PREFIX}/arpwatch;			\
		${CHOWN} root:operator ${PREFIX}/arpwatch;		\
	fi
	${TOUCH} ${PREFIX}/arpwatch/arp.dat
	${CHMOD} 644 ${PREFIX}/arpwatch/arp.dat
	for files in ethercodes.dat d.awk duplicates.awk euppertolower.awk e.awk p.awk; do \
		${INSTALL_DATA} ${WRKSRC}/$$files ${PREFIX}/arpwatch;	\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/arp2ethers ${PREFIX}/arpwatch
	${INSTALL_SCRIPT} ${WRKSRC}/massagevendor ${PREFIX}/arpwatch

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
