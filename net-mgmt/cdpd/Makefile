# Created by: Alexandre Snarskii <snar@paranoia.ru>
# $FreeBSD$

PORTNAME=	cdpd
PORTVERSION=	1.0.4.1
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://snar.spb.ru/prog/cdpd/

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Daemon to send CDP/LLDP announces over ethernet

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

USES=		tar:tgz
GNU_CONFIGURE=	yes

USE_RC_SUBR=	cdpd
PLIST_FILES=	sbin/cdpd man/man8/cdpd.8.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cdpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/cdpd.8 ${STAGEDIR}${MANPREFIX}/man/man8

.include <bsd.port.mk>
