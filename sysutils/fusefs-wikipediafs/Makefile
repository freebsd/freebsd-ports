# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wikipediafs
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Mount mediawikis

LICENSE=	GPLv2

RUN_DEPENDS=	py*-fusefs>=0.2:${PORTSDIR}/devel/py-fusefs

USES=		fuse python
USE_PYTHON=	distutils autoplist
PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README TODO

OPTIONS_DEFINE=	DOCS

PLIST_FILES=	man/man1/mount.${PORTNAME}.1.gz

.include <bsd.port.options.mk>
post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/doc/*gz

post-install:
	@cd ${WRKSRC}/doc/&&${INSTALL_MAN} mount.${PORTNAME}.1 ${STAGEDIR}${PREFIX}/man/man1/
.if ${PORT_OPTIONS:MDOCS}
	@${INSTALL} -d ${STAGEDIR}${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/
.endif

.include <bsd.port.mk>
