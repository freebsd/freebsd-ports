# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	ypsilon
PORTVERSION=	0.9.6.3
PORTREVISION=	5
CATEGORIES=	lang scheme

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Scheme implementation for real-time applications

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/license.txt

USE_GITHUB=	yes
GH_TUPLE=	fujita-y:ypsilon:0.9.6-update3

USES=		gmake
USE_GCC=	yes

MAKE_ARGS=	DATADIR="${DATADIR}"

ONLY_FOR_ARCHS=	i386 amd64

OPTIONS_DEFINE=	EXAMPLES

post-patch:
	${REINPLACE_CMD} 's/-fno-[a-z-]*//g' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/ && ${COPYTREE_SHARE} "sitelib stdlib" ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example/*.scm ${STAGEDIR}${EXAMPLESDIR}

regression-test: build
	cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
