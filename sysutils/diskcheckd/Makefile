# ex:ts=8
# Ports collection makefile for:  diskcheckd
# Date created:			  Thu Aug 23, 2001
# Whom:				  David W. Chapman Jr. (dwcjr@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	diskcheckd
PORTVERSION=	20010823
PORTREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	# part of port
DISTFILES=	# part of port
EXTRACT_ONLY=	# part of port

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Daemon to check for disk read errors

MAN8=		diskcheckd.8
MLINKS=		diskcheckd.8 diskcheckd.conf.5

USE_RC_SUBR=	diskcheckd
CFLAGS+=	-D_PATH_CONF='\"${PREFIX}/etc/diskcheckd.conf\"'
MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ARGS=	PROG=diskcheckd MAN8=${MAN8}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		is not tested on anything less than 5.0, use at discretion
.endif

do-extract:
	@${MKDIR} ${WRKSRC}

.for file in diskcheckd.c diskcheckd.8
	@(cd ${WRKSRC} ; ${CP} ${FILESDIR}/${file} .)
.endfor

do-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/diskcheckd.conf|${PREFIX}/etc/diskcheckd.conf|g' ${WRKSRC}/diskcheckd.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diskcheckd ${PREFIX}/sbin
	${INSTALL_DATA}	${FILESDIR}/diskcheckd.conf ${PREFIX}/etc/diskcheckd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/diskcheckd.8 ${PREFIX}/man/man8

.include <bsd.port.post.mk>
