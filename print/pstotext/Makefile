# Created by: Oliver Breuninger <ob@seicom.NET>
# $FreeBSD$

PORTNAME=	pstotext
PORTVERSION=	1.9
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	http://ftp.gwdg.de/pub/ghostscript/contrib/ \
		http://ftp.sunet.se/pub/text-processing/postscript/interpreters/ghostscript/contrib/ \
		http://gd.tuwien.ac.at/pub/publishing/ghostscript/contrib/ \
		http://fossies.org/unix/misc/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PostScript to Text converter

LICENSE=	EULA
LICENSE_NAME=	End User License Agreement
LICENSE_FILE=	${WRKSRC}/pstotext.txt
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

USES=		ghostscript:run

SUB_LIST=	LICENSE=${LICENSE} \
		LICENSE_DIR=${_LICENSE_DIR}

PLIST_FILES=	bin/pstotext \
		man/man1/pstotext.1.gz

post-patch:
	@${REINPLACE_CMD} ${SUB_LIST:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/main.c \
		${WRKSRC}/pstotext.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pstotext ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pstotext.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
