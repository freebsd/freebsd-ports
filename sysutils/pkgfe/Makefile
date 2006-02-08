# New ports collection makefile for:	pkgfe
# Date created:		2006-01-14
# Whom:			Sulev-Madis Silber <madis555@hot.ee>
#
# $FreeBSD$
#

PORTNAME=	pkgfe
PORTVERSION=	20060207
CATEGORIES=	sysutils
MASTER_SITES=	http://ketas.life.ee/ports/ \
		http://ketas.si.pri.ee/ports/

MAINTAINER=	madis555@hot.ee
COMMENT=	Ncurses front-end to manage the ports collection

RUN_DEPENDS=	portupgrade:${PORTSDIR}/sysutils/portupgrade \
		portaudit:${PORTSDIR}/security/portaudit \
		csup:${PORTSDIR}/net/csup

NO_BUILD=	yes

PLIST_FILES=	sbin/pkgfe etc/pkgfe.conf

do-install:
	${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/pkgfe
	${INSTALL_SCRIPT} ${WRKSRC}/pkgfe ${PREFIX}/sbin/pkgfe
	${INSTALL_DATA} ${WRKSRC}/pkgfe.conf ${PREFIX}/etc/pkgfe.conf

.include <bsd.port.mk>
