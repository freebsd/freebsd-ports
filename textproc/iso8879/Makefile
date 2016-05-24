# Created by: jfieber
# $FreeBSD$

PORTNAME=	iso8879
PORTVERSION=	1986
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/kuriyama
DISTNAME=	isoENTS

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Character entity sets from ISO 8879:1986 (SGML)

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

INSTDIR=	${PREFIX}/share/sgml/iso8879

do-install:
	@${MKDIR} ${STAGEDIR}${INSTDIR}
	@${INSTALL_DATA} ${WRKSRC}/ISO* ${STAGEDIR}${INSTDIR}
	@${INSTALL_DATA} ${FILESDIR}/catalog ${STAGEDIR}${INSTDIR}/catalog


.include <bsd.port.mk>
