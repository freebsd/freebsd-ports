# Created by: Nicola Vitale	<nivit@email.it>
# $FreeBSD$

PORTNAME=	geogebra
PORTVERSION=	5.0.208.0
CATEGORIES=	math java
MASTER_SITES=	http://download.geogebra.org/installers/5.0/
DISTNAME=	GeoGebra-Linux-Portable-${PORTVERSION}

MAINTAINER=	udvzsolt@gmail.com
COMMENT=	Dynamic software that joins geometry, algebra, and calculus

LICENSE=	GEOGEBRA
LICENSE_NAME=	GeoGebra Non-Commercial License Agreement
LICENSE_TEXT=   See on http://www.geogebra.org/license
LICENSE_PERMS=	dist-sell pkg-sell auto-accept

RUN_DEPENDS=	bash:${PORTSDIR}/shells/bash \
    /compat/linux/bin/sh:${PORTSDIR}/emulators/linux_base-c6

ONLY_FOR_ARCHS=i386 amd64

SUB_FILES=  geogebra.desktop
CONFLICTS=  math/geogebra-i18n-[0-9]*
NO_BUILD=	yes
USES=		tar:bzip2 desktop-file-utils shared-mime-info shebangfix
WRKSRC=		${WRKDIR}/${DISTNAME}
FIND_JARS=	-type f -name "*.jar" -maxdepth 1 -print0
JAVADIR=    jre1.7.0_45-i686
SHEBANG_FILES=	geogebra-portable

do-install:
	cd ${WRKSRC} && ${MKDIR} ${STAGEDIR}${DATADIR}/${PORTNAME} && \
    ${REINPLACE_CMD} -e 's,arch,/compat/linux/bin/arch,' ${WRKSRC}/geogebra-portable && \
	${INSTALL_SCRIPT} ${WRKSRC}/geogebra/geogebra ${STAGEDIR}${DATADIR}/${PORTNAME}/geogebra && \
    ${INSTALL_SCRIPT} ${WRKSRC}/geogebra-portable ${STAGEDIR}${DATADIR} && \
    ${LN} -s ${DATADIR}/geogebra-portable ${STAGEDIR}${PREFIX}/bin/${PORTNAME} && \
	${FIND} geogebra ${FIND_JARS} | ${XARGS} -0 -J % ${INSTALL_DATA} % ${STAGEDIR}${DATADIR}/${PORTNAME} && \
    ${COPYTREE_SHARE} ${JAVADIR} ${STAGEDIR}${DATADIR} && \
    ${INSTALL_PROGRAM} ${JAVADIR}/bin/java ${STAGEDIR}${DATADIR}/${JAVADIR}/bin && \
	${MKDIR} ${STAGEDIR}${PREFIX}/share/mime/packages && \
	${INSTALL_DATA} ${WRKDIR}/geogebra.desktop ${STAGEDIR}${DESKTOPDIR}

.include <bsd.port.mk>
