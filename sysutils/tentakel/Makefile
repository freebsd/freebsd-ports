# Created by: Munish Chopra <mchopra@engmail.uwaterloo.ca>
# $FreeBSD$

PORTNAME=	tentakel
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A program for executing commands on many hosts in parallel

WRKSRC=		${WRKDIR}/${DISTNAME}/py

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/doc/tentakel|${DOCSDIR_REL}|' \
		${WRKSRC}/setup.py

.include <bsd.port.mk>
