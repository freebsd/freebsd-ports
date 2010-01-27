# New ports collection makefile for:	xpi-gwt-dev-plugin
# Date created:			2010/01/20
# Whom:				Jonathan Chen <jonc@chen.org.nz>
#
# $FreeBSD$
#

PORTNAME=	xpi-gwt-dev-plugin
PORTVERSION=	2.0
CATEGORIES=	www
MASTER_SITES=	http://sites.google.com/site/daemonwizard/
DISTNAME=	gwt-dev-plugin-${PORTVERSION}-partial

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Google Web Toolkit Developer Plugin for Firefox

BUILD_DEPENDS=	firefox3:${PORTSDIR}/www/firefox35 \
		${LOCALBASE}/lib/libxul/xpidl:${PORTSDIR}/www/libxul
RUN_DEPENDS=	firefox3:${PORTSDIR}/www/firefox35

USE_BZIP2=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/gwt-dev-plugin
BUILD_WRKSRC=	${WRKSRC}/xpcom

XPI_ID=		gwt-dmp-ff35@gwt.google.com
XPI_LIBDIR=	${PREFIX}/lib/xpi
XPI_XPIDIR=	${XPI_LIBDIR}/${XPI_ID}
XPI_FILESDIR=	${BUILD_WRKSRC}/prebuilt/extension-ff35

FETCH_ARGS=	-p -o ${DISTDIR}/${DISTFILES}

do-fetch:
	@if [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		${FETCH_CMD} ${MASTER_SITES}${DISTFILES}?attredirects=0\&d=1 ; \
	fi

post-extract:
	${RM} -rf ${XPI_FILESDIR}/.svn ${XPI_FILESDIR}/*/.svn ${XPI_FILESDIR}/platform/*

do-install:
	${MKDIR} ${XPI_XPIDIR}
	${CP} -R ${XPI_FILESDIR}/ ${XPI_XPIDIR}
	${LN} -s ${XPI_XPIDIR} ${LOCALBASE}/lib/firefox3/extensions

.include <bsd.port.mk>
