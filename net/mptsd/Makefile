# $FreeBSD$

PORTNAME=	mptsd
PORTVERSION=	1.1
CATEGORIES=	net multimedia
MASTER_SITES=	https://georgi.unixsol.org/programs/mptsd/

MAINTAINER=	win2000rus@hotmail.com
COMMENT=	MPEG TS stream muxer

LICENSE=	GPLv2 MIT
LICENSE_COMB=	multi

USES=		gmake tar:bzip2

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}*.conf ${STAGEDIR}${ETCDIR}

.include <bsd.port.mk>
