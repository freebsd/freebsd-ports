# New ports collection makefile for:   NOCOL
# Version required:     4.2.2beta1
# Date created:                21 Nov 1998
# Whom:                        bradh
#
# $FreeBSD$
#

DISTNAME=	nocol-4.2.2beta1
PKGNAME=	nocol-4.2.2b1
CATEGORIES=	net
MASTER_SITES=	http://www.netplex-tech.com/software/nocol/downloads/

MAINTAINER=	bradh@iafrica.com

MANPREFIX=	${PREFIX}/nocol/
MAN1=		netconsole.1
MAN3=		nocol-prog.3 perlnocol.3
MAN8=		etherload.8 eventselect.8 genmon.8 multiping.8 noclogd.8 \
		nocol-overview.8 nocol-utility.8 nsmon.8 ntpmon.8 pingmon.8 \
		portmon.8 tpmon.8 trapmon.8

IS_INTERACTIVE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_SCRIPT=	Configure

NO_PACKAGE=	Hostname is needed.

post-install:
		@cd ${WRKSRC} && make root

.include <bsd.port.mk>
