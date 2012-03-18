# New ports collection makefile for:	fusefs-wikipediafs
# Date created:		10 August 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	wikipediafs
PORTVERSION=	0.4
CATEGORIES=	sysutils
MASTER_SITES=	SF
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	5u623l20@gmail.com
COMMENT=	Mount mediawikis

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod \
		py*-fusefs>=0.2:${PORTSDIR}/devel/py-fusefs

USE_PYTHON=	yes
USE_PYDISTUTILS=yes
PORTDOCS=	AUTHORS ChangeLog HACKING NEWS README TODO
MAN1=		mount.${PORTNAME}.1

post-extract:
	@${GUNZIP_CMD} ${WRKSRC}/doc/*gz

post-install:
	@cd ${WRKSRC}/doc/&&${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1/
.ifndef NOPORTDOCS
	@${INSTALL} -d ${DOCSDIR}/
	@cd ${WRKSRC}/&&${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}/
.endif

.include <bsd.port.mk>
