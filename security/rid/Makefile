# ex:ts=8
# Ports collection makefile for:  ddos_scan
# Date created:			  Sun Feb 12, 2000
# Whom:				  David O'Brien (obrien@NUXI.com)
#
# $FreeBSD$
#

PORTNAME=	rid
PORTVERSION=	1.0
CATEGORIES=	security
MASTER_SITES=	http://www.phreak.org/archives/exploits/denial/  \
		ftp://ftp.ntua.gr/pub/security/technotronic/denial/
DISTFILES=	${PORTNAME}-${PORTVERSION:S/./_/}.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Configurable remote distributed denial of service tool detector

ALL_TARGET=	rid
USE_REINPLACE=	yes

pre-configure:
	@${REINPLACE_CMD} -e 's:config.txt:${PREFIX}/etc/rid.conf:g'  \
		${WRKSRC}/config.h

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/rid ${PREFIX}/sbin
	@${INSTALL_DATA} ${WRKSRC}/config.txt ${PREFIX}/etc/rid.conf
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/rid
	@${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/rid
.endif

.include <bsd.port.mk>
