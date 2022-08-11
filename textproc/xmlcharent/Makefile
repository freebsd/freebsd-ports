PORTNAME=	xmlcharent
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	https://www.oasis-open.org/docbook/${PORTNAME}/${PORTVERSION}/ \
		https://library.syr.edu/digital/guides/lavender/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XML character entities

LICENSE=	OASIS
LICENSE_NAME=	OASIS License
LICENSE_TEXT=	License text is available in all .ent files installed by this port
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
NO_ARCH=	yes

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent \
		${FILESDIR}/catalog ${FILESDIR}/catalog.xml ${STAGEDIR}${XMLDIR}

.include <bsd.port.mk>
