# New ports collection makefile for:	netscape
# Version required:     4.02b7
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $Id: Makefile,v 1.4 1997/08/04 00:04:22 ache Exp $
#

DISTNAME=       netscape-4.02b7
CATEGORIES=	www
MASTER_SITES=   ftp://ftp23.netscape.com/pub/communicator/4.02/4.02b7/english/unix/freebsd/base_install/
DISTFILES=      communicator-v402b7-export.x86-unknown-freebsd.tar.gz
NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
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
	rm -rf ${NDIR}/movemail-src
	chown -R bin.bin ${NDIR}

post-install:
	@${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
