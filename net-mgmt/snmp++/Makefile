# New ports collection makefile for:   snmp++
# Date created:        2007-05-14
# Whom:                nicolai@catpipe.net
#
# $FreeBSD$
#

PORTNAME=	snmp++
PORTVERSION=	3.2.23
CATEGORIES=	net-mgmt
MASTER_SITES=	http://www.agentpp.com/
DISTNAME=	${PORTNAME}v${PORTVERSION}

MAINTAINER=	nicolai@catpipe.net
COMMENT=	SNMP C++ library with V3 support

MAKEFILE=	Makefile.FreeBSD
WRKSRC=		${WRKDIR}/${PORTNAME}/src

USE_GMAKE=	yes
USE_LDCONFIG=	yes

post-extract:
	${CP} ${FILESDIR}/Makefile.FreeBSD ${WRKSRC}

.include <bsd.port.mk>
