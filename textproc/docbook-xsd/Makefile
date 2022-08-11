PORTNAME=	docbook-xsd
DISTVERSION=	1.0b1
CATEGORIES=	textproc
MASTER_SITES=	https://www.oasis-open.org/docbook/xmlschema/${DISTVERSION}/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	DocBook W3C XML Schema

USES=		zip

NO_ARCH=	yes
NO_BUILD=	yes

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.xsd ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
