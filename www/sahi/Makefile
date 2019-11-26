# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sahi
PORTVERSION=	3.5.${SAHI_BUILD}
#PORTREVISION=	0
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-v${PORTVERSION:R:R:R:S,.,,}/${SAHI_BUILD:S,.,,g}/
DISTNAME=	${PORTNAME}_${SAHI_BUILD:S,.,,g}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Web automation and testing tool

LICENSE=	APACHE20 MPL11
LICENSE_COMB=	multi

RUN_DEPENDS=	xdg-open:devel/xdg-utils

DATADIR=	${JAVASHAREDIR}/${PORTNAME}

JAVA_OS=	native
JAVA_RUN=	yes

NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=	CHROME
OPTIONS_SINGLE=	BROWSER
OPTIONS_SINGLE_BROWSER=	CHROME FIREFOX OPERA

CHROME_DESC=	Use Chrome as default browser
FIREFOX_DESC=	Use Firefox as default browser
OPERA_DESC=	Use Opera as default browser

USES=		dos2unix zip
DOS2UNIX_GLOB=	linux.xml os.properties sahi.properties

.include <bsd.port.options.mk>

SAHI_BUILD=	2011.07.19

USE_JAVA=	yes

WRKSRC=	${WRKDIR}/sahi

REINPLACE_ARGS=	-i '' -E \
		-e 's,%%CHROME%%,${LOCALBASE}/bin/chrome,g' \
		-e 's,%%DATADIR%%,${DATADIR},g' \
		-e 's,%%FIREFOX%%,${LOCALBASE}/bin/firefox,g' \
		-e 's,%%JAVA%%,${JAVA},g' \
		-e 's,%%JAVA_KEYTOOL%%,${JAVA_KEYTOOL},g' \
		-e 's,%%OPERA%%,${LOCALBASE}/bin/opera,g' \
		-e 's,(SAHI_HOME=).*$$,\1${DATADIR},g' \
		-e 's,(export (SAHI_)?USERDATA_DIR=).*$$,if [ -z "$${SAHI_USERDATA_DIR}" ]; then \1\$${HOME}/.sahi; fi,g' \
		-e 's,^(\#!/bin/)ba(sh)$$,\1\2,g'

SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	BROWSER=${BROWSER} JAVA_HOME=${JAVA_HOME}

post-patch:
	@${FIND} ${WRKSRC} -type f \( -name "*.orig" -or -name "*.bat" \) -delete
	@${FIND} ${WRKSRC} -type f \( -name "*.sh" -or -name "linux.xml" \
		-or -name "sahi.properties" \) -print0 \
		| ${XARGS} -0 ${REINPLACE_CMD}

do-install:
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	@cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

	@${CP} ${STAGEDIR}${DATADIR}/config/browser_types/linux.xml ${STAGEDIR}${DATADIR}/userdata/config/browser_types.xml
.for	d in bin userdata/bin
	@${CHMOD} ${BINMODE} ${STAGEDIR}${DATADIR}/${d}/*
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MV} ${STAGEDIR}${DATADIR}/docs ${STAGEDIR}${DOCSDIR}
.else
	@${RM} -r ${STAGEDIR}${DATADIR}/docs
.endif

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MCHROME}
BROWSER=	chrome
RUN_DEPENDS+=	chrome:www/chromium
.endif

.if ${PORT_OPTIONS:MFIREFOX}
BROWSER=	firefox
RUN_DEPENDS+=	firefox:www/firefox
.endif

.if ${PORT_OPTIONS:MOPERA}
BROWSER=	opera
RUN_DEPENDS+=	opera:www/opera
.endif

.include <bsd.port.post.mk>
