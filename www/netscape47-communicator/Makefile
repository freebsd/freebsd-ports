# New ports collection makefile for:	netscape
# Version required:     4.0b5
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.2 1997/04/09 15:12:05 ache Exp $
#

DISTNAME=       netscape-4.0b5
CATEGORIES=	www
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.0/4.0b5/unix/other/
DISTFILES=      communicator-v40b5-export.x86-bsdi-bsd.tar.gz
NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

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
	${INSTALL_DATA} ${WRKSRC}/policyMoz40P1.jar ${NDIR}
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
