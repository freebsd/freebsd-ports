# New ports collection makefile for:	netscape
# Version required:     4.0b3
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.1.1.1 1997/02/24 19:00:29 ache Exp $
#

DISTNAME=       netscape-4.0b3
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.0/4.0b3/unix/other/
DISTFILES=      communicator-v40b3-export.x86-unknown-bsd.tar.gz
NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
NLSDIR=		${X11BASE}/lib/X11/nls
BINDIR=		${PREFIX}/bin

MAINTAINER=     ache@FreeBSD.ORG

RESTRICTED=	"Commercial software"

do-install:
	cd ${WRKSRC} && yes "" | \
	    NSHOME="${NDIR}" ./ns-install
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
