# New ports collection makefile for:    linux-netscape4
# Version required:     4.01b6
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.3 1997/06/01 00:06:17 ache Exp $
#

DISTNAME=       linux-netscape-4.01b6
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.01/4.01b6/english/unix/other/
DISTFILES=      communicator-v401b6-export.x86-unknown-linux1.2.tar.gz
NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

RUN_DEPENDS=    /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
BUILD_DEPENDS=  /compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib

NDIR=           ${PREFIX}/lib/netscape
NLSDIR=		${X11BASE}/lib/X11/nls
BINDIR=		${PREFIX}/bin

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software"

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	mv ${NDIR}/netscape ${NDIR}/netscape.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	-test -d ${NLSDIR} || mkdir -p ${NLSDIR}
	if [ ! -f ${NLSDIR}/C ] ; then \
	    ${INSTALL_DATA} ${NDIR}/nls/C ${NLSDIR}; \
	fi
	if [ ! -f ${NLSDIR}/nls.dir ] ; then \
	    ${INSTALL_DATA} ${NDIR}/nls/nls.dir ${NLSDIR}; \
	fi
	rm -rf ${NDIR}/nls ${NDIR}/movemail-src ${NDIR}/XKeysymDB
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
