# New ports collection makefile for:	netscape (full communicator beta)
# Version required:     4.5
# Date created:         24 Feb 1997
# Whom:                 thepish
#
# $Id: Makefile,v 1.27 1998/10/20 06:45:18 asami Exp $
#

DISTNAME=	communicator-v45-export.x86-unknown-freebsd
PKGNAME=	netscape-communicator-4.5
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.5/english/unix/unsupported/freebsd/complete_install/

MAINTAINER=     thepish@FreeBSD.ORG

BROKEN=		PLIST

NO_LATEST_LINK=	yes
WRKSRC=         ${WRKDIR}/communicator-v45.x86-unknown-freebsd
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape.45
BINDIR=		${PREFIX}/bin

.if defined(USE_128BIT)
MASTER_SITES+=	ftp://ftp.fortify.net/pub/Fortify/ \
		ftp://ftp.za.freebsd.org/pub/Fortify/
DISTFILES+=	Fortify-1.3.0-unix-x86.tar.gz
RESTRICTED=     "Contains strong cryptography"
.else
pre-extract:
		@${ECHO} "You can make Netscape use 128-bit encryption by defining USE_128BIT"
.endif	# USE_128BIT

.if !defined(MULTIVERSION)
		@${ECHO} "you can define MULTIVERSION to install the script which runs communicator-v45"
		@${ECHO} "as ${BINDIR}/communicator-4.5 rather than ${BINDIR}/netscape."
		@${ECHO} "You may find this useful if you want to run the stable and pre release versions"
		@${ECHO} "concurrently."
.endif


do-install:
	cd ${WRKSRC} && \
	  yes "" | LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/communicator-4.5.bin
.if defined(MULTIVERSION)
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/communicator-4.5
.else
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
.endif
	if [ ! -f ${NDIR}/mailcap ] ; then \
	  ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/movemail-src
.if defined(USE_128BIT)
	cd ${WRKDIR}/Fortify-1.3.0-unix-x86 && \
		(${ECHO} yes ; ${ECHO} no) | ./Fortify.sh ${NDIR}/communicator-4.5.bin
.endif
	chown -R ${BINOWN}.${BINGRP} ${NDIR}

.include <bsd.port.mk>
