# Created by: Brian Somers <brian@FreeBSD.org>
# $FreeBSD$

PORTNAME=	arpwatch
PORTVERSION=	2.1.a15
PORTREVISION=	6
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		${MASTER_SITE_GENTOO}
MASTER_SITE_SUBDIR=	distfiles
DISTNAME=	${PORTNAME}-${PORTVERSION:C/\.([^\.]*)$/\1/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Monitor arp & rarp requests


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
	if [ ! -d ${STAGEDIR}${PREFIX}/arpwatch ]; then				\
		${MKDIR} ${STAGEDIR}${PREFIX}/arpwatch;				\
		${CHMOD} 755 ${STAGEDIR}${PREFIX}/arpwatch;			\
		${CHOWN} root:operator ${STAGEDIR}${PREFIX}/arpwatch;		\
	fi
	${TOUCH} ${STAGEDIR}${PREFIX}/arpwatch/arp.dat
	${CHMOD} 644 ${STAGEDIR}${PREFIX}/arpwatch/arp.dat
	for files in ethercodes.dat d.awk duplicates.awk euppertolower.awk e.awk p.awk; do \
		${INSTALL_DATA} ${WRKSRC}/$$files ${STAGEDIR}${PREFIX}/arpwatch;	\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/arp2ethers ${STAGEDIR}${PREFIX}/arpwatch
	${INSTALL_SCRIPT} ${WRKSRC}/massagevendor ${STAGEDIR}${PREFIX}/arpwatch

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
