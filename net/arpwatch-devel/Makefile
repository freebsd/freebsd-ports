# New ports collection makefile for:    arpwatch
# Version required:     2.0.1a1
# Date created:         March 24 1997
# Whom:                 Brian Somers <brian@awfulhak.demon.co.uk>
#
# $Id$
#

DISTNAME=       arpwatch-2.0.1a1
PKGNAME=        arpwatch-2.0.1a1
CATEGORIES+=    net
MASTER_SITES=   ftp://ftp.ee.lbl.gov/ \
		ftp://ftp.cso.uiuc.edu/pub/security/coast/unix/arpwatch/
EXTRACT_SUFX=	.tar.Z
MAINTAINER=     brian@awfulhak.demon.co.uk
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--quiet
MAKE_FLAGS+=	CCOPT="-O2 -DPATH_SENDMAIL=\\\"/usr/sbin/sendmail\\\""

post-install:
	cd ${WRKSRC}; make install-man
	if [ ! -d ${PREFIX}/arpwatch ]; then	\
		mkdir ${PREFIX}/arpwatch;	\
		chmod 775 ${PREFIX}/arpwatch;	\
		chown root.operator ${PREFIX}/arpwatch;	\
	fi
	touch ${PREFIX}/arpwatch/arp.dat
	chmod 644 ${PREFIX}/arpwatch/arp.dat

.include <bsd.port.mk>
