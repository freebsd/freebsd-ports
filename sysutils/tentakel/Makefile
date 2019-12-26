# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	tentakel
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for executing commands on many hosts in parallel

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

WRKSRC=		${WRKDIR}/${DISTNAME}/py

USES=		python:2.7
USE_PYTHON=	distutils

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc/tentakel|${DOCSDIR_REL}|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
