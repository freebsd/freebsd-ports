# New ports collection makefile for:    arpwatch
# Date created:         March 24 1997
# Whom:                 Brian Somers <brian@Awfulhak.org>
#
# $FreeBSD$
#

PORTNAME=	arpwatch
PORTVERSION=	2.1.a4
CATEGORIES=	net
MASTER_SITES=	http://www.Awfulhak.org/arpwatch/ \
		ftp://ftp.ee.lbl.gov/ \
		ftp://ftp.cso.uiuc.edu/pub/security/coast/unix/arpwatch/
DISTNAME=	arpwatch-2.1a4
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	brian@Awfulhak.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
INSTALL_TARGET=	install install-man
MAN8=		arpwatch.8 arpsnmp.8

post-install:
	if [ ! -d ${PREFIX}/arpwatch ]; then				\
		${MKDIR} ${PREFIX}/arpwatch;				\
		${CHMOD} 775 ${PREFIX}/arpwatch;				\
		${CHOWN} root.operator ${PREFIX}/arpwatch;			\
	fi
	${TOUCH} ${PREFIX}/arpwatch/arp.dat
	${CHMOD} 644 ${PREFIX}/arpwatch/arp.dat
	for file in ethercodes.dat d.awk e.awk p.awk; do		\
		${INSTALL_DATA} ${WRKSRC}/$$file ${PREFIX}/arpwatch/.;	\
	done
	${INSTALL_SCRIPT} ${WRKSRC}/arp2ethers ${PREFIX}/arpwatch/.
	${INSTALL_SCRIPT} ${FILESDIR}/arpwatch.sh ${PREFIX}/etc/rc.d/.

.include <bsd.port.mk>
