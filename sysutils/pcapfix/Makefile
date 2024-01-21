PORTNAME=	pcapfix
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.7
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	vidar@karlsen.tech
COMMENT=	Tool to repair damaged or corrupted pcap and pcapng files
WWW=		https://f00l.de/pcapfix/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GITHUB=	yes
GH_ACCOUNT=	Rup0rt

PLIST_FILES=	bin/pcapfix \
		share/man/man1/pcapfix.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
