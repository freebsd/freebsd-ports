# New ports collection makefile for:    linux-netscape4
# Version required:     4.05
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1998/06/10 12:19:28 jkh Exp $
#

DISTNAME=       linux-netscape-4.05
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.05/shipping/english/unix/linux12/base_install/
DISTFILES=      communicator-v405-export.x86-unknown-linux1.2.tar.gz

MAINTAINER=     ports@FreeBSD.ORG

RUN_DEPENDS=    /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
BUILD_DEPENDS=  /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib

WRKSRC=		${WRKDIR}/communicator-v405.x86-unknown-linux1.2
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv ${NDIR}/netscape ${NDIR}/netscape.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	rm -rf ${NDIR}/nls ${NDIR}/movemail-src ${NDIR}/XKeysymDB
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
