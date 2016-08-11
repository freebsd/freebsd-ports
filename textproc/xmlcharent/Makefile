# Created by: Kimura Fuyuki <fuyuki@mj.0038.net>
# $FreeBSD$

PORTNAME=	xmlcharent
PORTVERSION=	0.3
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://www.oasis-open.org/docbook/${PORTNAME}/${PORTVERSION}/

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	XML character entities

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		zip
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

XMLDIR=		${PREFIX}/share/xml/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${XMLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ent \
		${FILESDIR}/catalog ${FILESDIR}/catalog.xml ${STAGEDIR}${XMLDIR}

.include <bsd.port.mk>
