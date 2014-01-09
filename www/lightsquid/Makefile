# Created by: Alexander Logvinov <info@logvinov.com>
# $FreeBSD$

PORTNAME=	lightsquid
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	SF
EXTRACT_SUFX=	.tgz

MAINTAINER=	fluffy@FreeBSD.org
COMMENT=	A light and fast web based squid proxy traffic analyser

OPTIONS_DEFINE=		GD DOCS
OPTIONS_DEFAULT=	GD

USES=		perl5
USE_PERL5=	run
NO_BUILD=	yes

PLIST_SUB+=	WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}" \
		CHOWN="${CHOWN}"

.include <bsd.port.options.mk>

CONFIGS=	lightsquid.cfg realname.cfg skipuser.cfg group.cfg
REINPLACE_ARGS=	-i ""
PORTDOCS=	gnugpl.txt install.txt readme.txt thanks.txt graph.txt logformat.txt \
		templates.txt version.txt
SUB_FILES=	pkg-message
.if ${PORT_OPTIONS:MDOCS}
SUB_LIST+=	NOTEWORK="Read ${DOCSDIR}/readme.txt."
.else
SUB_LIST+=	NOTEWORK=""
.endif

.if ${PORT_OPTIONS:MGD}
RUN_DEPENDS+=	p5-GD>=0:${PORTSDIR}/graphics/p5-GD
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/var/www/html/${PORTNAME}/lang|${DATADIR}/lang| ; \
		s|/var/www/html/${PORTNAME}\"|${ETCDIR}\"| ; \
		s|/var/www/html/${PORTNAME}/ip2name|${PREFIX}/libexec/${PORTNAME}| ; \
		s|/var/log/squid|${LOCALBASE}/squid/logs| ; \
		s|/var/www/html/${PORTNAME}|${WWWDIR}|' \
		${WRKSRC}/lightsquid.cfg
	@${FIND} -E ${WRKSRC} -maxdepth 1 -regex '.*\.(cgi|pl)' | \
		${XARGS} ${REINPLACE_CMD} \
		 -e 's|${PORTNAME}.cfg|${ETCDIR}/${PORTNAME}.cfg|g'
	@${MV} ${WRKSRC}/group.cfg.src ${WRKSRC}/group.cfg

do-install:
	${MKDIR} ${STAGEDIR}/${DATADIR}/lang
	cd ${WRKSRC}/lang && \
	${FIND} . -type f -regex '.*\.lng' -exec \
		${INSTALL_DATA} "{}" "${STAGEDIR}/${DATADIR}/lang/{}" \;
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}
	cd ${WRKSRC}/ip2name && \
	${FIND} . -type f -exec \
		${INSTALL_DATA} "{}" "${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/{}" \;
	${MKDIR} ${STAGEDIR}/${ETCDIR}
.for i in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${ETCDIR}/${i}.dist
.if !exists(${ETCDIR}/${i})
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${ETCDIR}
.endif
.endfor
	${MKDIR} ${STAGEDIR}/${WWWDIR}/report
	${MKDIR} ${STAGEDIR}/${WWWDIR}/tpl
	cd ${WRKSRC}/tpl && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${STAGEDIR}/${WWWDIR}/tpl/{}" \; && \
	${FIND} . -type f -exec \
		${INSTALL_DATA} "{}" "${STAGEDIR}/${WWWDIR}/tpl/{}" \;
	cd ${WRKSRC} && \
	${FIND} -E . -maxdepth 1 -regex '.*\.(cgi|pl)' -exec \
		${INSTALL_SCRIPT} "{}" "${STAGEDIR}/${WWWDIR}/{}" \; && \
		${INSTALL_DATA} .htaccess ${STAGEDIR}/${WWWDIR}/
#	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${STAGEDIR}/${WWWDIR}
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}/${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
