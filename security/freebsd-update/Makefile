# New ports collection makefile for:	FreeBSD Update Client
# Date created:				21 March 2003
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	freebsd-update
PORTVERSION=	1.2
CATEGORIES=	security
MASTER_SITES=	http://www.daemonology.net/freebsd-update/
DISTNAME=	freebsd-update-client-1_2

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Fetches and installs binary updates to FreeBSD

NO_WRKSUBDIR=	yes
ALL_TARGET=	verify

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/freebsd-update \
		> ${WRKSRC}/freebsd-update

do-install:
	@${MKDIR} ${PREFIX}/freebsd-update
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/verify ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/Makefile ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/VERSION ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/update.conf \
		${PREFIX}/freebsd-update/update.conf.sample

post-install:
	@${CAT} ${PKGDIR}/pkg-message

.include <bsd.port.mk>
