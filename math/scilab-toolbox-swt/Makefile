## New ports collection makefile for:   swt
# Date created:			28 March 2006
# Whom:				Max Brazhnikov makc@issp.ac.ru
#
# $FreeBSD$
#

PORTNAME=	swt
PORTVERSION=	0.1.11
CATEGORIES=	math
MASTER_SITES=	http://atoms.scilab.org/toolboxes/swt/${PORTVERSION}/files/
PKGNAMEPREFIX=	scilab-toolbox-
DISTFILES=	${DISTNAME}-1-src${EXTRACT_SUFX}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Scilab 1-D and 2-D Wavelet Toolbox

BUILD_DEPENDS=	${SCILAB_CMD}:${PORTSDIR}/math/scilab
RUN_DEPENDS:=	${BUILD_DEPENDS}

IGNORE=		touches ${LOCALBASE}/share/scilab when building under superuser

SCILAB_CMD=	${LOCALBASE}/bin/scilab
CONTRIBDIR?=	share/scilab/contrib
TOOLBOXDIR_REL?=	${CONTRIBDIR}/${PORTNAME}
TOOLBOXDIR=	${PREFIX}/${TOOLBOXDIR_REL}
PLIST_SUB=	TOOLBOXDIR=${TOOLBOXDIR_REL}

OPTIONS=	SIVP "Enable Image and Video support" off

.include <bsd.port.options.mk>

.if defined(WITH_SIVP)
RUN_DEPENDS+=	${LOCALBASE}/${CONTRIBDIR}/sivp/loader.sce:${PORTSDIR}/math/scilab-toolbox-sivp
.endif

post-patch:
	${REINPLACE_CMD} -e "s,SWTDIR+','${TOOLBOXDIR}/demos," \
		${WRKSRC}/demos/image.sce
pre-build:
	${FIND} -d ${WRKSRC} \( -name '*.orig' -or -name '*.bak' \) | ${XARGS} ${RM}

do-build:
	cd ${WRKSRC} && ${SCILAB_CMD} -nogui -f builder.sce

do-install:
	${MKDIR} ${TOOLBOXDIR}/sci_gateway/c
	${INSTALL_DATA} ${WRKSRC}/loader.sce ${TOOLBOXDIR}
	${INSTALL_DATA} ${WRKSRC}/sci_gateway/loader_gateway.sce \
		${TOOLBOXDIR}/sci_gateway
	cd ${WRKSRC}/sci_gateway/c && \
	${INSTALL_DATA} loader.sce ${TOOLBOXDIR}/sci_gateway/c && \
	${INSTALL_PROGRAM} libswt_c.so ${TOOLBOXDIR}/sci_gateway/c
.for d in demos etc macros
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${d} ${TOOLBOXDIR}
.endfor

.include <bsd.port.mk>
