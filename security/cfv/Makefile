# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cfv
PORTVERSION=	1.18.3
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to both test and create .sfv, .csv, and md5sum files

DEPRECATED=	Unmaintained, uses EOLed python27
EXPIRATION_DATE=	2020-01-27

USES=		python:2.7
ALL_TARGET=	cfv.wrapper
INSTALL_TARGET=	install-wrapper
MAKE_ARGS=	PYTHON=${PYTHON_CMD}

post-patch:
	@${REINPLACE_CMD} -e "s,%%SITELIBDIR%%,${PYTHON_SITELIBDIR},g" \
	        -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
