# New ports collection makefile for:	FreeBSD Update Client
# Date created:				21 March 2003
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	freebsd-update
PORTVERSION=	1.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.daemonology.net/freebsd-update/
DISTNAME=	${PORTNAME}-client-${PORTVERSION:S/./_/}

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Fetches and installs binary updates to FreeBSD

RUN_DEPENDS=	bspatch:${PORTSDIR}/misc/bsdiff

MAN5=		freebsd-update.conf.5
MAN8=		freebsd-update.8

NO_WRKSUBDIR=	yes
ALL_TARGET=	verify

PKGMESSAGE=	${WRKDIR}/pkg-message

post-extract:
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/freebsd-update \
		> ${WRKSRC}/freebsd-update
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/pkg-message \
		> ${PKGMESSAGE}
	@${CP} ${FILESDIR}/freebsd-update.8 ${WRKSRC}
	@${CP} ${FILESDIR}/freebsd-update.conf.5 ${WRKSRC}

do-install:
	@${MKDIR} ${PREFIX}/freebsd-update
	${INSTALL_SCRIPT} ${WRKSRC}/freebsd-update ${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/verify ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/Makefile ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${PREFIX}/freebsd-update
	${INSTALL_DATA} ${WRKSRC}/update.conf \
		${PREFIX}/etc/freebsd-update.conf.sample
.if !defined(WITHOUT_MAN)
	${INSTALL_MAN} ${WRKSRC}/freebsd-update.conf.5 ${PREFIX}/man/man5/
	${INSTALL_MAN} ${WRKSRC}/freebsd-update.8 ${PREFIX}/man/man8/
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
