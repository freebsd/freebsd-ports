# Created by: Simon 'corecode' Schubert <corecode@corecode.ath.cx>
# $FreeBSD$

PORTNAME=	epsonepl
PORTVERSION=	0.2.2
PORTREVISION=	6
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/GS-IJS%20Plugin%20v${PORTVERSION}
DISTNAME=	${PORTNAME}ijs-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Printer filter for EPSON EPL-5700L etc

LIB_DEPENDS=	libijs.so:print/libijs

USES=		ghostscript:run uidfix tar:tgz

MAKEFILE=	${FILESDIR}/Makefile
SUB_FILES=	pkg-message

post-extract:
	@cd ${WRKSRC} && ${LS} ijs* | ${GREP} -v ${PORTNAME} | ${XARGS} ${RM}

post-install:
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.conf.sample \
		${STAGEDIR}${PREFIX}/etc
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${FILESDIR}/${PORTNAME}.apsfilter ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
