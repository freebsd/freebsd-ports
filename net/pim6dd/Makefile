# $FreeBSD$

PORTNAME=	pim6
PORTVERSION=	0.2.1.0.a.15
CATEGORIES=	net
MASTER_SITES=	SF/mcast-tools
PKGNAMESUFFIX=	dd
DISTNAME=	mcast-tools-20061214

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	IPv6 PIM-DM multicast routing daemon

BROKEN=		unfetchable

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf
USE_RC_SUBR=	${PORTNAME}${PKGNAMESUFFIX}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	YACC=${YACC}

post-install:
	${INSTALL_DATA} ${FILESDIR}/pim6dd.conf.sample \
	    ${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
