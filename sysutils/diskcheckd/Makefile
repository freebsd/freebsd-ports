# ex:ts=8
# Ports collection makefile for:  diskcheckd
# Date created:			  Thu Aug 23, 2001
# Whom:				  David W. Chapman Jr. (dwcjr@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	diskcheckd
PORTVERSION=	20010823
CATEGORIES=	sysutils
MASTER_SITES=	# part of port
DISTFILES=	# part of port
EXTRACT_ONLY=	# part of port

MAINTAINER=	ports@FreeBSD.org

STARTUP=	diskcheckd.sh
MAN8=		diskcheckd.8

NO_WRKSUBDIR=	yes

do-extract:
	@${MKDIR} ${WRKSRC}
	@(cd ${FILESDIR} && pax -r -w * ${WRKSRC})

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -DCONFPATH=\"${PREFIX}/etc\" -o diskcheckd diskcheckd.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diskcheckd ${PREFIX}/sbin
	${INSTALL_DATA}	${WRKSRC}/diskcheckd.conf ${PREFIX}/etc/diskcheckd.conf.sample
	${INSTALL_SCRIPT} ${WRKSRC}/diskcheckd.sh ${PREFIX}/etc/rc.d
	${INSTALL_MAN} ${WRKSRC}/diskcheckd.8 ${PREFIX}/man/man8

.include <bsd.port.mk>
