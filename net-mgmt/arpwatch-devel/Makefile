# New ports collection makefile for:    arpwatch-devel
# Date created:         11 November 2003
# Whom:                 Matthew George <mdg@secureworks.net>
#
# $FreeBSD$
#

PORTNAME=	arpwatch
PORTVERSION=	2.1.a11
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.Awfulhak.org/arpwatch/ \
		ftp://ftp.ee.lbl.gov/
PKGNAMESUFFIX=	-devel
DISTNAME=	arpwatch-2.1a11

MAINTAINER=	mdg@secureworks.net
COMMENT=	Monitor arp & rarp requests

CONFLICTS=	arpwatch-2.*

GNU_CONFIGURE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
INSTALL_TARGET=	install install-man
MAN8=		arpwatch.8 arpsnmp.8

MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" PTHREAD_LIBS="${PTHREAD_LIBS}"

post-install:
	if [ ! -d ${PREFIX}/arpwatch ]; then				\
		${MKDIR} ${PREFIX}/arpwatch;				\
		${CHMOD} 755 ${PREFIX}/arpwatch;			\
		${CHOWN} root:operator ${PREFIX}/arpwatch;		\
	fi
	${TOUCH} ${PREFIX}/arpwatch/arp.dat
	${CHMOD} 644 ${PREFIX}/arpwatch/arp.dat
	${TOUCH} ${PREFIX}/arpwatch/ether.dat
	${CHMOD} 644 ${PREFIX}/arpwatch/ether.dat
	for file in ethercodes.dat d.awk e.awk p.awk; do		\
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/arpwatch/.;	\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/arp2ethers ${PREFIX}/arpwatch/.
	${INSTALL_SCRIPT} ${FILESDIR}/arpwatch.sh ${PREFIX}/etc/rc.d/arpwatch.sh.sample

.include <bsd.port.mk>
