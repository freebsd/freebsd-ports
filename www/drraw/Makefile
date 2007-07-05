# New ports collection makefile for:	drraw
# Date created:				2006-08-08
# Whom:					Jim Riggs <ports@christianserving.org>
#
# $FreeBSD$
#

PORTNAME=	drraw
PORTVERSION=	2.1.3
CATEGORIES=	www
MASTER_SITES=	http://web.taranis.org/drraw/dist/ \
		http://christianserving.org/ports/mail/imapsync/

MAINTAINER=	ports@christianserving.org
COMMENT=	A simple web-based presentation front-end for RRDtool

RUN_DEPENDS+=	${SITE_PERL}/RRDp.pm:${PORTSDIR}/databases/rrdtool

USE_PERL5_RUN=	yes

NO_BUILD=	yes

PORTDOCS=	CHANGES INSTALL LICENSE README.EVENTS WISHLIST

CONFDIR?=	etc
DATADIRS?=	"/var/db/rrdtool" => "[Label1] "
SAVEDDIR?=	/var/db/${PORTNAME}/saved
TMPDIR?=	/var/db/${PORTNAME}/tmp

PLIST_SUB+=	CONFDIR=${CONFDIR}

post-patch:
	@${REINPLACE_CMD} -e 's|%%CONFDIR%%|${PREFIX}/${CONFDIR}|g' ${WRKSRC}/drraw.cgi

	@${CP} -p ${WRKSRC}/drraw.conf ${WRKSRC}/drraw.conf-dist
	@${REINPLACE_CMD} \
		-e 's|%%DATADIRS%%|${DATADIRS}|g' \
		-e 's|%%SAVEDDIR%%|${SAVEDDIR}|g' \
		-e 's|%%TMPDIR%%|${TMPDIR}|g' \
		${WRKSRC}/drraw.conf-dist

do-install:
	${INSTALL_DATA} ${WRKSRC}/drraw.conf-dist ${PREFIX}/${CONFDIR}

	${MKDIR} ${WWWDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/drraw.cgi ${WWWDIR}

	${MKDIR} ${WWWDIR}/icons
.for theFile in bomb.gif folder.gif folder.open.gif generic.gif link.gif text.gif unknown.gif
	${INSTALL_DATA} ${WRKSRC}/icons/${theFile} ${WWWDIR}/icons
.endfor

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
. for theFile in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${theFile} ${DOCSDIR}
. endfor
.endif

post-install:
	@if [ ! -f ${PREFIX}/etc/drraw.conf ];\
	then \
		${CP} -p ${PREFIX}/etc/drraw.conf-dist ${PREFIX}/etc/drraw.conf; \
	fi

.include <bsd.port.mk>
