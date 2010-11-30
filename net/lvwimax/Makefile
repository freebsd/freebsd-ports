# New ports collection makefile for:	net/lvwimax
# Date created:				2010-06-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	lvwimax
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.ipt.ru/pub/download/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	A userland driver for Samsung WiMAX modems

LICENSE=	GPLv2

USE_RC_SUBR=	lvwimax

PLIST_FILES=	etc/devd/lvwimax.conf sbin/lvwimax

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800069
IGNORE=		requires FreeBSD 8.0-RELEASE or later for libusb-1.0 support
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/lvwimax.conf.in > ${WRKDIR}/lvwimax.conf
	${INSTALL_DATA} "${WRKDIR}/lvwimax.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
