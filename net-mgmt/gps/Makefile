# ex:ts=8
# New ports collection makefile for:	gps
# Date created:			Nov 25, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gps
PORTVERSION=	0.9.3
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	http://gps.sourceforge.net/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}-FRC

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ghost Port Scan

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LIBS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

post-patch:
	@${REINPLACE_CMD} -e "s,-Wall -O3,${CFLAGS},g" ${WRKSRC}/configure

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/docs/* ${DOCSDIR}
.endif

.include <bsd.port.mk>
