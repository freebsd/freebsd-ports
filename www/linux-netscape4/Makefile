# New ports collection makefile for:    linux-netscape4
# Version required:     4.08
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $FreeBSD$
#

DISTNAME=	communicator-v408-export.x86-unknown-linux2.0_libc5
PKGNAME=	linux-netscape-4.08
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.netscape.com/pub/communicator/4.08/english/unix/supported/linux20/base_install/ \
		ftp://sunsite.doc.ic.ac.uk/Mirrors/ftp.netscape.com/pub/communicator/4.08/english/unix/supported/linux20/base_install/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.netscape.com/pub/communicator/4.08/english/unix/supported/linux20/base_install/ \
		ftp://ftp.sunsite.auc.dk/disk4/mirrorsite.netscape.com/pub/communicator/4.08/english/unix/supported/linux20/base_install/

MAINTAINER=	tom@eborcom.com

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/communicator-v408.x86-unknown-linux2.0
NO_BUILD=	Yes

NDIR=		${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/netscape.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/nls ${NDIR}/movemail-src ${NDIR}/XKeysymDB
	${CHOWN} -R ${BINOWN}.${BINGRP} ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
