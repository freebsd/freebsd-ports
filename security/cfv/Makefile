# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cfv
PORTVERSION=	1.18.3
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to both test and create .sfv, .csv, and md5sum files

USE_PYTHON=	yes
ALL_TARGET=	cfv.wrapper
INSTALL_TARGET=	install-wrapper

MAN1=	cfv.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
