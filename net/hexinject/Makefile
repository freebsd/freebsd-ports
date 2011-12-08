# New ports collection makefile for:	hexinject
# Date created:		2010-10-24
# Whom:			Sofian Brabez <sbrabez@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	hexinject
PORTVERSION=	1.4
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	HexInject is a very versatile packet injector and sniffer

LICENSE=	BSD

PLIST_FILES=	bin/${PORTNAME}

WRKSRC=	${WRKDIR}/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e '2s#-lpcap#-L${LOCALBASE}/lib -lpcap#' ${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.pre.mk>

.if ${OSREL} < 8
BUILD_DEPENDS+=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap
.endif

.include <bsd.port.post.mk>
