PORTNAME=	iso8879
PORTVERSION=	1986
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	LOCAL/kuriyama
DISTNAME=	isoENTS

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Character entity sets from ISO 8879:1986 (SGML)

LICENSE=	IOS
LICENSE_NAME=	International Organization for Standardization license
LICENSE_TEXT=	(C) International Organization for Standardization 1986 \
		Permission to copy in any form is granted for use with \
		conforming SGML systems and applications as defined in \
		ISO 8879, provided this notice is included in all copies.
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

RUN_DEPENDS=	xmlcatmgr:textproc/xmlcatmgr

USES=		zip
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
NO_ARCH=	yes

INSTDIR=	${PREFIX}/share/sgml/iso8879

do-install:
	@${MKDIR} ${STAGEDIR}${INSTDIR}
	${INSTALL_DATA} ${WRKSRC}/ISO* ${STAGEDIR}${INSTDIR}
	${INSTALL_DATA} ${FILESDIR}/catalog ${STAGEDIR}${INSTDIR}/catalog

.include <bsd.port.mk>
