# New ports collection makefile for:    arpwatch
# Date created:         March 24 1997
# Whom:                 Brian Somers <brian@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	arpwatch
PORTVERSION=	2.1.a11
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	http://www.Awfulhak.org/arpwatch/ \
		ftp://ftp.ee.lbl.gov/
DISTNAME=	arpwatch-2.1a11

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Monitor arp & rarp requests

CONFLICTS=	arpwatch-devel-2.*

USE_SIZE=	yes
GNU_CONFIGURE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
INSTALL_TARGET=	install install-man
MAN8=		arpwatch.8 arpsnmp.8

post-install:
	if [ ! -d ${PREFIX}/arpwatch ]; then				\
		${MKDIR} ${PREFIX}/arpwatch;				\
		${CHMOD} 755 ${PREFIX}/arpwatch;			\
		${CHOWN} root:operator ${PREFIX}/arpwatch;		\
	fi
	${TOUCH} ${PREFIX}/arpwatch/arp.dat
	${CHMOD} 644 ${PREFIX}/arpwatch/arp.dat
	for file in ethercodes.dat d.awk e.awk p.awk; do		\
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/arpwatch;	\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/arp2ethers ${PREFIX}/arpwatch
	${INSTALL_SCRIPT} ${FILESDIR}/arpwatch.sh ${PREFIX}/etc/rc.d/arpwatch.sh.sample
	@${ECHO_MSG} "#####################################################################"
	@${ECHO_MSG} "Installing ${PREFIX}/etc/rc.d/arpwatch.sh.sample file."
	@${ECHO_MSG} "#####################################################################"

.include <bsd.port.mk>
