# New ports collection makefile for:	FreeBSD Update Client
# Date created:				21 March 2003
# Whom:					cperciva@daemonology.net
#
# $FreeBSD$
#

PORTNAME=	freebsd-update
PORTVERSION=	1.4
CATEGORIES=	security
MASTER_SITES=	http://www.daemonology.net/freebsd-update/

MAINTAINER=	cperciva@daemonology.net
COMMENT=	Fetches and installs binary updates to FreeBSD

RUN_DEPENDS=	bspatch:${PORTSDIR}/misc/bsdiff

MAN5=		freebsd-update.conf.5
MAN8=		freebsd-update.8

PKGMESSAGE=	${WRKDIR}/pkg-message

.ifdef NOPORTDOCS
MAKE_ENV+=	NODOCS=yes
.endif

post-extract:
	${SED} -e "s#PREFIX=/usr/local#PREFIX=${PREFIX}#g" \
		${WRKSRC}/freebsd-update > ${WRKSRC}/freebsd-update.new
	${MV} ${WRKSRC}/freebsd-update.new ${WRKSRC}/freebsd-update
	@${SED} -e "s=%%PREFIX%%=${PREFIX}=g" ${FILESDIR}/pkg-message \
		> ${PKGMESSAGE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
