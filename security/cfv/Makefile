# ex:ts=8
# New ports collection makefile for:	cfv
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cfv
PORTVERSION=	1.18.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to both test and create .sfv, .csv and md5sum files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/fchksum.so:${PORTSDIR}/security/py-fchksum

USE_PYTHON=	yes
ALL_TARGET=	cfv.wrapper
INSTALL_TARGET=	install-wrapper

MAN1=	cfv.1

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.mk>
