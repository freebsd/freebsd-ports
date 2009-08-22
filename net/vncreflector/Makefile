# Ports collection makefile for:	vncreflector
# Date created:				Wed, Jan 19 2005
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	vncreflector
PORTVERSION=	1.2.4
PORTREVISION=	3
CATEGORIES=	net
MASTER_SITES=	SF/vnc-reflector/vnc-reflector/${PORTVERSION}
DISTNAME=	vnc_reflector-${PORTVERSION}

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Multi-client VNC proxy server

LIB_DEPENDS+=	jpeg.10:${PORTSDIR}/graphics/jpeg

USE_RC_SUBR=	vncreflector.sh

ALL_TARGET=	default
WRKSRC=		${WRKDIR}/vnc_reflector

post-patch:
	${REINPLACE_CMD} -e 's|%%LOCALBASE%%|${LOCALBASE}|' ${WRKSRC}/Makefile

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} -m0750 ${PREFIX}/etc/${PORTNAME}
	@${CHOWN} root:wheel ${PREFIX}/etc/${PORTNAME}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
