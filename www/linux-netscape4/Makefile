# New ports collection makefile for:    linux-netscape4
# Date created:         24 Feb 1997
# Whom:                 ache
#
# $FreeBSD$
#

PORTNAME=	linux-netscape
PORTVERSION=	4.08
CATEGORIES=	www linux
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	tom
DISTNAME=	communicator-v408-export.x86-unknown-linux2.0_libc5

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		netscape:${PORTSDIR}/www/netscape-wrapper

ONLY_FOR_ARCHS=	i386

WRKSRC=		${WRKDIR}/communicator-v408.x86-unknown-linux2.0
NO_BUILD=	Yes

NDIR=		${PREFIX}/lib/netscape
BINDIR=		${PREFIX}/bin

do-install:
	cd ${WRKSRC} && yes "" | \
	    LC_TIME=C MOZILLA_HOME="${NDIR}" ./ns-install
	${MV} -f ${NDIR}/netscape ${NDIR}/netscape.bin
	${INSTALL_SCRIPT} ${WRKSRC}/netscape ${BINDIR}/netscape.run
	if [ ! -f ${NDIR}/mailcap ] ; then \
	    ${INSTALL_DATA} ${FILESDIR}/mailcap ${NDIR}; \
	fi
	${RM} -rf ${NDIR}/nls ${NDIR}/movemail-src ${NDIR}/XKeysymDB
	${CHOWN} -R ${BINOWN}.${BINGRP} ${NDIR}

post-install:
	@${CAT} ${DESCR}

.include <bsd.port.mk>
