# New ports collection makefile for:		linux-opera4
# Date created:					December 6th 2000
# Whom:						des
#
# $FreeBSD$
#

PORTNAME=	linux-opera
PORTVERSION=	4.0b3
CATEGORIES=	www linux
MASTER_SITES=	http://opera.online.no/linux/tgz/
DISTNAME=	opera-4.0-b3-static.i386

MAINTAINER=	des@FreeBSD.org

RUN_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_base

NO_BUILD=	yes

do-install:
	(cd ${WRKDIR} && \
	    tar cf - ${DISTNAME} | tar --unlink -xpf - -C ${PREFIX})
	${INSTALL_SCRIPT} ${FILESDIR}/opera.sh ${PREFIX}/bin/opera

.include <bsd.port.mk>
