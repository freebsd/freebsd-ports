# Created by: Andrew L. Neporada <andrew@chg.ru>
# $FreeBSD$

PORTNAME=	gsl
PORTVERSION=	1.16
CATEGORIES=	math
MASTER_SITES=	GNU

MAINTAINER=	bf@FreeBSD.org
COMMENT=	The GNU Scientific Library - mathematical libs

LICENSE=	GPLv3

USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	MAKEINFO='makeinfo --no-split'

MAN1=		gsl-config.1 gsl-randist.1 gsl-histogram.1
MAN3=		gsl.3
INFO=		gsl-ref

post-extract:
	@${RM} -f ${WRKSRC}/doc/gsl-ref.info*

#prevent regression test coredumps from causing failures on the
#package-building cluster:
.ifndef(MAINTAINER_MODE)
CORELIMIT?=	/usr/bin/limits -Sc 0
.endif

check regression-test test: build
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${CORELIMIT} ${MAKE_CMD} \
	${MAKE_ARGS} check

.include <bsd.port.pre.mk>

.if ${ARCH} == "powerpc"
BROKEN=		Does not compile on powerpc
.endif

.include <bsd.port.post.mk>
