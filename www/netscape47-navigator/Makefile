# New ports collection makefile for:	netscape
# Version required:     4.04
# Date created:         24 Feb 1997
# Whom:                 ache
#
# Note: you can make the standalone navigator version by typing
#       make NAVIGATOR=yes
#
# $Id: Makefile,v 1.8 1997/09/25 08:25:24 asami Exp $
#

CATEGORIES=	www
.if !defined(NAVIGATOR)
DISTNAME=       netscape-4.04
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.04/development/english/unix/freebsd/professional_edition/
DISTFILES=      communicator-v404-export.x86-unknown-freebsd.tar.gz
MAINTAINER=     ache@FreeBSD.ORG
.else
DISTNAME=       netscape-4.03b8
MASTER_SITES=   ftp://ftp.netscape.com/pub/communicator/4.03/4.03b8/english/unix/freebsd/navigator_standalone/
DISTFILES=      navigator-v403b8-export.x86-unknown-freebsd.tar.gz
MAINTAINER=     ports@FreeBSD.ORG
.endif
NO_WRKSUBDIR=   Yes
NO_BUILD=       Yes

NDIR=           ${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

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
