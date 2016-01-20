# Created by: Lars Engels <lars.engels@0x20.net>
# $FreeBSD$

PORTNAME=	tvbrowser
PORTVERSION=	3.4.3
CATEGORIES=	misc java
MASTER_SITES=	SF/${PORTNAME}/TV-Browser%20Releases%20%28Java%206%20and%20higher%29/${PORTVERSION}/
DISTNAME=	${PORTNAME}_${PORTVERSION}_bin

MAINTAINER=	lme@FreeBSD.org
COMMENT=	Digital TV and radio guide

LICENSE=	GPLv3

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
NO_BUILD=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.6+
SUB_FILES=	tvbrowser

do-install:
	@${REINPLACE_CMD} -e "s/${PORTNAME}\.sh/${PORTNAME}/" \
		${WRKSRC}/${PORTNAME}.desktop
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.desktop \
		${STAGEDIR}${PREFIX}/share/applications/
	@${RM} ${WRKSRC}/${PORTNAME}.desktop ${WRKSRC}/${PORTNAME}.desktop.bak
	@cd ${WRKSRC} && ${FIND} . -type d -exec \
		${MKDIR} "${STAGEDIR}${DATADIR}/{}" \;
	@cd ${WRKSRC} && ${FIND} . -type f -exec \
		${INSTALL_DATA} "{}" "${STAGEDIR}${DATADIR}/{}" \;
	${INSTALL_SCRIPT} ${WRKDIR}/tvbrowser ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
