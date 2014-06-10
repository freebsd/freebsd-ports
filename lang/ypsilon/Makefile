# Created by: Vitaly Magerya <vmagerya@gmail.com>
# $FreeBSD$

PORTNAME=	ypsilon
PORTVERSION=	0.9.6.3
PORTREVISION=	3
CATEGORIES=	lang scheme
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}-0.9.6.update3

MAINTAINER=	vmagerya@gmail.com
COMMENT=	Scheme implementation for real-time applications

USES=		gmake

MAKE_ARGS=	DATADIR="${DATADIR}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}"

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
	cd ${WRKSRC} && ${GMAKE} check

.include <bsd.port.mk>
