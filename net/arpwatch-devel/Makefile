# New ports collection makefile for:    arpwatch
# Version required:     2.0.2a1
# Date created:         March 24 1997
# Whom:                 Brian Somers <brian@awfulhak.org>
#
# $Id: Makefile,v 1.4 1997/04/13 16:01:12 brian Exp $
#

DISTNAME=	arpwatch-2.0.2a1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ee.lbl.gov/ \
		ftp://ftp.cso.uiuc.edu/pub/security/coast/unix/arpwatch/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	brian@awfulhak.org

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
MAKE_FLAGS=	CCOPT="-O2 -DPATH_SENDMAIL=\\\"/usr/sbin/sendmail\\\""
INSTALL_TARGET=	install install-man
MAN8=		arpwatch.8 arpsnmp.8


post-install:
	if [ ! -d ${PREFIX}/arpwatch ]; then	\
		${MKDIR} ${PREFIX}/arpwatch;	\
		chmod 775 ${PREFIX}/arpwatch;	\
		/usr/sbin/chown root.operator ${PREFIX}/arpwatch;	\
	fi
	touch ${PREFIX}/arpwatch/arp.dat
	chmod 644 ${PREFIX}/arpwatch/arp.dat

.include <bsd.port.mk>
