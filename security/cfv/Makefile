# ex:ts=8
# New ports collection makefile for:	cfv
# Date created:			Jul 20, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	cfv
PORTVERSION=	1.18.2
CATEGORIES=	security
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility to both test and create .sfv, .csv and md5sum files

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/fchksum.so:${PORTSDIR}/security/py-fchksum

USE_PYTHON=	yes
ALL_TARGET=	cfv.wrapper
INSTALL_TARGET=	install-wrapper

MAN1=	cfv.1

OPTIONS=	PSYCO "Enable devel/py-psyco optimization support" off

post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.pre.mk>

.if defined(WITH_PSYCO)
EXTRA_PATCHES+=	${FILESDIR}/extra-psyco-patch-Makefile
.endif

.include <bsd.port.post.mk>
