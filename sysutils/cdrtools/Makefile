# New ports collection makefile for:    cdrecord
# Version required:     1.5
# Date created:         2 November 1997
# Whom:                 jmz
#
# $Id$
#

DISTNAME=	cdrecord-1.5
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/


MAINTAINER=	jmz@FreeBSD.org

MAN1=		cdrecord.1

USE_GMAKE=	yes
RUN_DEPENDS=	mkisofs:${PORTSDIR}/sysutils/mkisofs

do-build:
	@cd ${WRKSRC}/lib && ../Gmake
	@cd ${WRKSRC}/cdrecord && ../Gmake

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/i386-freebsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@cd /dev && ln -sf /dev/rworm0.ctl sgx

.include <bsd.port.mk>
