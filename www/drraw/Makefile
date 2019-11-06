# Created by: Jim Riggs <ports@christianserving.org>
# $FreeBSD$

PORTNAME=	drraw
DISTVERSION=	2.2b2
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://web.taranis.org/drraw/dist/ \
		http://christianserving.org/ports/mail/imapsync/

MAINTAINER=	avg@icyb.net.ua
COMMENT=	Simple web-based presentation front-end for RRDtool

BROKEN=		unfetchable

RUN_DEPENDS+=	rrdtool>=0:databases/rrdtool

OPTIONS_DEFINE=	ZOOM_PATCH DOCS
ZOOM_PATCH_DESC=	Zoom support using jQuery via external patch

USES=		perl5 shebangfix
USE_PERL5=	run
NO_BUILD=	yes
SHEBANG_FILES=	drraw.cgi

PORTDOCS=	CHANGES INSTALL LICENSE README.EVENTS

CONFDIR?=	etc
DATADIRS?=	"/var/db/rrdtool" => "[Label1] "
SAVEDDIR?=	/var/db/${PORTNAME}/saved
TMPDIR?=	/var/db/${PORTNAME}/tmp

PLIST_SUB+=	CONFDIR=${CONFDIR}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MZOOM_PATCH}
PATCH_SITES+=	http://aprilmayjune.org/wp-content/uploads/2009/09/
PATCHFILES+=	drraw.cgi.zoom_patch
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|%%CONFDIR%%|${PREFIX}/${CONFDIR}|g' ${WRKSRC}/drraw.cgi

	@${CP} -p ${WRKSRC}/drraw.conf ${WRKSRC}/drraw.conf-dist
	@${REINPLACE_CMD} \
		-e 's|%%DATADIRS%%|${DATADIRS}|g' \
		-e 's|%%SAVEDDIR%%|${SAVEDDIR}|g' \
		-e 's|%%TMPDIR%%|${TMPDIR}|g' \
		${WRKSRC}/drraw.conf-dist

do-install:
	${INSTALL_DATA} ${WRKSRC}/drraw.conf-dist ${STAGEDIR}${PREFIX}/${CONFDIR}

	${MKDIR} ${STAGEDIR}${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/drraw.cgi ${STAGEDIR}${WWWDIR}

	${MKDIR} ${STAGEDIR}${WWWDIR}/icons
	cd ${WRKSRC}/icons/${theFile} && ${INSTALL_DATA} bomb.gif folder.gif folder.open.gif generic.gif link.gif text.gif unknown.gif ${STAGEDIR}${WWWDIR}/icons
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
