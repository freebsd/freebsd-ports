# New ports collection makefile for:	rotorouter
# Date created:				Sat May 29 01:30:43 EDT 2004
# Whom:					Paul Chvostek <paul@it.ca>
#
# $FreeBSD$
#
# This port is self-contained in the src directory.
#

PORTNAME=	rotorouter
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	net-mgmt
MASTER_SITES=	# nada
DISTFILES=	# nil

MAINTAINER=	paul+ports@it.ca
COMMENT=	Traceroute attempt logger and result spoofer

NO_WRKSUBDIR=	yes

SED_SCRIPT+=	-e 's,%%PREFIX%%,${PREFIX},g' \
		-e 's,%%RC_SUBR%%,${RC_SUBR},g'

.include <bsd.port.pre.mk>

USE_RC_SUBR=    yes

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${FILESDIR}/rotorouter.c ${WRKSRC}

do-build:
		${CC} -lpcap -o ${WRKSRC}/rotorouter ${WRKSRC}/rotorouter.c
		${SED} ${SED_SCRIPT} < ${FILESDIR}/rotorouter.sh > ${WRKSRC}/rotorouter.sh

do-install:
		@${INSTALL_DATA} -m 640 ${FILESDIR}/rotorouter.conf-example ${PREFIX}/etc
		@${INSTALL_DATA} -m 640 ${FILESDIR}/rotorouter.conf-example ${PREFIX}/etc/rotorouter.conf
		@${INSTALL_PROGRAM} ${WRKSRC}/rotorouter ${PREFIX}/sbin/
		@${INSTALL_SCRIPT} -m 751 ${WRKSRC}/rotorouter.sh ${PREFIX}/etc/rc.d/rotorouter.sh

post-install:
		@${SED} ${SED_SCRIPT} < ${PKGMESSAGE}

.include <bsd.port.post.mk>
