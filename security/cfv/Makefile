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

OPTIONS_DEFINE_i386=	PSYCO
PSYCO_DESC=	Enable devel/py-psyco optimization support

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/Makefile

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MPSYCO}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/_psyco.so:${PORTSDIR}/devel/py-psyco

EXTRA_PATCHES+=	${FILESDIR}/extra-psyco-patch-Makefile
.endif

.include <bsd.port.mk>
