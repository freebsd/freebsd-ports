PORTNAME=	diffstat
PORTVERSION=	1.65
PORTREVISION=	1
CATEGORIES=	textproc devel
MASTER_SITES=	https://invisible-mirror.net/archives/${PORTNAME}/ \
		ftp://ftp.invisible-island.net/${PORTNAME}/

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Makes a histogram summarizing "diff" output
WWW=		https://invisible-island.net/diffstat/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		tar:tgz
GNU_CONFIGURE=	yes
MAKEFILE=	makefile

PLIST_FILES=	bin/diffstat share/man/man1/diffstat.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
