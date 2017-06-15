# Created by: Alexander Logvinov <info@logvinov.com>
# $FreeBSD$

PORTNAME=	lightsquid
PORTVERSION=	1.8
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Light and fast web based squid proxy traffic analyser

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/doc/gnugpl.txt

USES=		perl5 shebangfix tar:tgz
SHEBANG_FILES=	*.cgi *.pl tools/SiteAggregator/*.pl lang/*.pl tools/*.pl \
		lightsquid.cfg
USE_PERL5=	run
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_SUB+=	WWWOWN="${WWWOWN}" \
		WWWGRP="${WWWGRP}" \
		CHOWN="${CHOWN}"

CONFIGS=	lightsquid.cfg realname.cfg skipuser.cfg group.cfg
REINPLACE_ARGS=	-i ""
PORTDOCS=	gnugpl.txt install.txt readme.txt thanks.txt graph.txt logformat.txt \
		templates.txt version.txt
SUB_FILES=	pkg-message

OPTIONS_DEFINE=		GD DOCS
OPTIONS_DEFAULT=	GD

GD_RUN_DEPENDS=	p5-GD>=0:graphics/p5-GD
DOCS_SUB_LIST=	NOTEWORK="Read ${DOCSDIR}/readme.txt."
DOCS_SUB_LIST_OFF=NOTEWORK=

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
		${INSTALL_DATA} {} "${STAGEDIR}/${DATADIR}/lang/{}" \;
	${MKDIR} ${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}
	cd ${WRKSRC}/ip2name && \
	${FIND} . -type f -exec \
		${INSTALL_DATA} {} "${STAGEDIR}/${PREFIX}/libexec/${PORTNAME}/{}" \;
	${MKDIR} ${STAGEDIR}/${ETCDIR}
.for i in ${CONFIGS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}/${ETCDIR}/${i}.sample
.endfor
	${MKDIR} ${STAGEDIR}/${WWWDIR}/report
	${MKDIR} ${STAGEDIR}/${WWWDIR}/tpl
	cd ${WRKSRC}/tpl && \
	${FIND} . -type d ! -empty -exec \
		${MKDIR} "${STAGEDIR}/${WWWDIR}/tpl/{}" \; && \
	${FIND} . -type f -exec \
		${INSTALL_DATA} {} "${STAGEDIR}/${WWWDIR}/tpl/{}" \;
	cd ${WRKSRC} && \
	${FIND} -E . -maxdepth 1 -regex '.*\.(cgi|pl)' -exec \
		${INSTALL_SCRIPT} {} "${STAGEDIR}/${WWWDIR}/{}" \; && \
		${INSTALL_DATA} .htaccess ${STAGEDIR}/${WWWDIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${i} ${STAGEDIR}/${DOCSDIR}
.endfor

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 502200
RUN_DEPENDS+=	p5-CGI>0:www/p5-CGI
.endif

.include <bsd.port.post.mk>
