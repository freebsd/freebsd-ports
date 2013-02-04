# Created by: reg@shale.csir.co.za
# $FreeBSD$

PORTNAME=	snns
PORTVERSION=	4.3
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://www.ra.cs.uni-tuebingen.de/downloads/SNNS/
DISTNAME=	SNNSv${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fully featured neural network simulator

LIB_DEPENDS=	Xaw3d:${PORTSDIR}/x11-toolkits/Xaw3d

USE_XORG=	x11 xext xt
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}/lib/snns --enable-global \
		--build=${CONFIGURE_TARGET}
MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.options.mk>

post-extract:
.for file in config.guess config.sub
	@${CP} -f ${TEMPLATES}/${file} ${WRKSRC}/configuration
.endfor

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|mkdir $$(|${MKDIR} $$(|g'
	@${FIND} ${WRKSRC}/xgui/sources -name "*.c" -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|X11/Xaw/|X11/Xaw3d/|g'

	@${ECHO_CMD} '#!/bin/sh' > ${WRKDIR}/snns
	@${ECHO_CMD} '' >> ${WRKDIR}/snns
	@${ECHO_CMD} 'XGUILOADPATH=${PREFIX}/lib/snns' >> ${WRKDIR}/snns
	@${ECHO_CMD} 'export XGUILOADPATH' >> ${WRKDIR}/snns
	@${ECHO_CMD} 'PATH=$${PATH}:${PREFIX}/lib/snns/bin'  >> ${WRKDIR}/snns
	@${ECHO_CMD} 'export DPATH' >> ${WRKDIR}/snns
	@${ECHO_CMD} '' >> ${WRKDIR}/snns
	@${ECHO_CMD} '${PREFIX}/lib/snns/bin/xgui' >> ${WRKDIR}/snns

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/snns ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/Readme ${PREFIX}/lib/snns
	${INSTALL_DATA} ${WRKSRC}/Readme.license ${PREFIX}/lib/snns
	${INSTALL_DATA} ${WRKSRC}/default.cfg ${PREFIX}/lib/snns
	${INSTALL_DATA} ${WRKSRC}/help.hdoc ${PREFIX}/lib/snns
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
