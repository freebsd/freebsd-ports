# New ports collection makefile for:    linux-netscape4
# Version required:     4.08
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.5 1998/06/16 13:34:24 asami Exp $
#

DISTNAME=       linux-netscape-4.08
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.08/english/unix/supported/linux12/base_install/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.netscape.com/pub/communicator/4.08/english/unix/supported/linux12/base_install/
DISTFILES=      communicator-v408-export.x86-unknown-linux1.2.tar.gz

MAINTAINER=     tom@eborcom.com

RUN_DEPENDS=    /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
BUILD_DEPENDS=  /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib

WRKSRC=		${WRKDIR}/communicator-v408.x86-unknown-linux1.2
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} ${NDIR}/netscape ${NDIR}/netscape.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/nls ${NDIR}/movemail-src ${NDIR}/XKeysymDB
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
