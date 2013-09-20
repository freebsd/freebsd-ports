# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	installwatch
PORTVERSION=	0.6.3
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://asic-linux.com.mx/~izto/checkinstall/files/source/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	File creation/modification logger

LICENSE=	GPLv2

USE_LDCONFIG=	yes

PLIST_FILES=	bin/installwatch lib/installwatch.so
PORTDOCS=	BUGS CHANGELOG INSTALL README TODO
OPTIONS_DEFINE=	DOCS

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCS}
post-install:
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
