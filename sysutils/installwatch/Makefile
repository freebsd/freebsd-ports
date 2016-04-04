# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	installwatch
PORTVERSION=	0.6.3
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	http://asic-linux.com.mx/~izto/checkinstall/files/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File creation/modification logger

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USE_LDCONFIG=	yes

PLIST_FILES=	bin/installwatch lib/installwatch.so
PORTDOCS=	BUGS CHANGELOG README TODO

OPTIONS_DEFINE=	DOCS

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/installwatch.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
