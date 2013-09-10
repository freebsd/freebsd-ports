# Created by: Frank Wall <fw@moov.de>
# $FreeBSD$

PORTNAME=	omping
PORTVERSION=	0.0.4
CATEGORIES=	net-mgmt
MASTER_SITES=	https://fedorahosted.org/releases/o/m/${PORTNAME}/

MAINTAINER=	fw@moov.de
COMMENT=	Tool to test IP multicast functionality

LICENSE=	MIT

USES=		gmake

PLIST_FILES=	bin/${PORTNAME}

MAN8=		${PORTNAME}.8

post-patch:
		@${REINPLACE_CMD} -e 's|/share/man|/man|g' ${WRKSRC}/Makefile

.include <bsd.port.mk>
