# Created by: Boris Samorodov <bsam@FreeBSD.org>
# $FreeBSD$

PORTNAME=	lvwimax
PORTVERSION=	0.1
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.wart.ru/pub/download/ \
		${MASTER_SITE_LOCAL}

MAINTAINER=	bsam@FreeBSD.org
COMMENT=	Userland driver for Samsung WiMAX modems

LICENSE=	GPLv2

USE_RC_SUBR=	lvwimax

PLIST_FILES=	etc/devd/lvwimax.conf sbin/lvwimax

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' ${WRKSRC}/Makefile

post-install:
	@${MKDIR} ${PREFIX}/etc/devd
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
		< ${FILESDIR}/lvwimax.conf.in > ${WRKDIR}/lvwimax.conf
	${INSTALL_DATA} "${WRKDIR}/lvwimax.conf" ${PREFIX}/etc/devd
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
