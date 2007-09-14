# New ports collection makefile for:	javaservicewrapper
# Date created:				2007-09-13
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	javaservicewrapper
PORTVERSION=	3.2.3
CATEGORIES=	sysutils java
MASTER_SITES=	SF/wrapper
DISTNAME=	wrapper_${PORTVERSION}_src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Application to solve problems common to many Java applications

USE_JAVA=	1.3+

DATADIR=	${PREFIX}/lib/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|gcc|${CC} ${CFLAGS}|' \
		${WRKSRC}/src/c/Makefile-freebsd-x86-32

do-build:
	@cd ${WRKSRC} && ${SH} build32.sh

do-install:
	${MKDIR} ${DATADIR}
	cd ${WRKSRC} && ${CP} -rp bin conf lib test ${DATADIR}
	${LN} -sf ${DATADIR}/bin/wrapper ${PREFIX}/bin/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} -r ${WRKSRC}/doc/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
