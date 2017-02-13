# Created by: Vidar Karlsen <vidar@karlsen.tech>
# $FreeBSD$

PORTNAME=	pcapfix
PORTVERSION=	1.1.0
CATEGORIES=	sysutils

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Tool to repair damaged or corrupted pcap and pcapng files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Rup0rt
GH_TAGNAME=	v1.1.0

PLIST_FILES=	bin/pcapfix man/man1/pcapfix.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
