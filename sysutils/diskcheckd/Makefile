# Created by: David W. Chapman Jr. (dwcjr@FreeBSD.org)
# $FreeBSD$

PORTNAME=	diskcheckd
PORTVERSION=	20110729
CATEGORIES=	sysutils
MASTER_SITES=	# part of port
DISTFILES=	# part of port
EXTRACT_ONLY=	# part of port

MAINTAINER=	perryh@pluto.rain.com
COMMENT=	Daemon to check for disk read errors

MAN8=		diskcheckd.8
MLINKS=		diskcheckd.8 diskcheckd.conf.5

USE_RC_SUBR=	diskcheckd
CFLAGS+=	-D_PATH_CONF='\"${PREFIX}/etc/diskcheckd.conf\"'
MAKEFILE=	/usr/share/mk/bsd.prog.mk
MAKE_ARGS=	PROG=diskcheckd MAN8=${MAN8}

NO_STAGE=	yes
do-extract:
	@${MKDIR} ${WRKSRC}
.for f in diskcheckd.c diskcheckd.8
	@(cd ${WRKSRC} ; ${CP} ${FILESDIR}/${f} .)
.endfor

do-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/etc/diskcheckd.conf|${PREFIX}/etc/diskcheckd.conf|g' ${WRKSRC}/diskcheckd.8

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/diskcheckd ${PREFIX}/sbin
	${INSTALL_DATA}	${FILESDIR}/diskcheckd.conf ${PREFIX}/etc/diskcheckd.conf.sample
	${INSTALL_MAN} ${WRKSRC}/diskcheckd.8 ${MAN8PREFIX}/man/man8

post-install:
	@[ -f ${PREFIX}/etc/diskcheckd.conf ] \
		|| ${CP} -p ${PREFIX}/etc/diskcheckd.conf.sample \
			${PREFIX}/etc/diskcheckd.conf

.include <bsd.port.mk>
