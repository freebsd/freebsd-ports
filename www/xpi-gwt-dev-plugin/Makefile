# New ports collection makefile for:	xpi-gwt-dev-plugin
# Date created:			2010/01/20
# Whom:				Jonathan Chen <jonc@chen.org.nz>
#
# $FreeBSD$
#

PORTNAME=	xpi-gwt-dev-plugin
PORTVERSION=	2.0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://sites.google.com/site/daemonwizard/
DISTNAME=	gwt-dev-plugin-${PORTVERSION}-partial

MAINTAINER=	jonc@chen.org.nz
COMMENT=	Google Web Toolkit Developer Plugin for Firefox

BUILD_DEPENDS=	${LOCALBASE}/lib/libxul/xpidl:${PORTSDIR}/www/libxul

ONLY_FOR_ARCHS=	amd64 i386

USE_BZIP2=	yes
USE_FIREFOX_BUILD=	35
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

xpi-post-extract:
	${RM} -rf ${XPI_FILESDIR}/.svn ${XPI_FILESDIR}/*/.svn ${XPI_FILESDIR}/platform/*

do-install:
	${MKDIR} ${XPI_XPIDIR}
	${CP} -R ${XPI_FILESDIR}/ ${XPI_XPIDIR}
	${LN} -s ${XPI_XPIDIR} ${LOCALBASE}/lib/firefox3/extensions

post-install:
	@${FIND} -s ${XPI_FILESDIR} -not -type d | \
		${SED} -ne 's,^${XPI_FILESDIR}/,${XPI_XPIDIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${FIND} -s -d ${XPI_FILESDIR} -type d | \
		${SED} -ne 's,^${XPI_FILESDIR}/,@dirrm ${XPI_XPIDIR:S,^${PREFIX}/,,}/,p' >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${XPI_XPIDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}
	@${ECHO_CMD} "@dirrm ${XPI_LIBDIR:S,^${PREFIX}/,,}" >> ${TMPPLIST}

.include <bsd.port.mk>
