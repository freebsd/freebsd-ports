# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	wikipediafs
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Mount mediawikis

RUN_DEPENDS=	py*-fusefs>=0.2:${PORTSDIR}/devel/py-fusefs

USES=		fuse
USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README TODO
MAN1=		mount.${PORTNAME}.1

NO_STAGE=	yes
post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/doc/*gz

post-install:
	@cd ${WRKSRC}/doc/&&${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
