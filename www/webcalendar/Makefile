# New ports collection makefile for:   WebCalendar
# Date created:        21 June 2005
# Whom:                glarkin
#
# $FreeBSD$
#

PORTNAME=	WebCalendar
DISTVERSION=	1.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	webcalendar
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	glarkin@sourcehosting.net
COMMENT=	A web-based calendar application

USE_PHP=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/WebCalendar-${DISTVERSION}

WEBWCDIR?=	www/data/WebCalendar
PLIST=		${WRKDIR}/pkg-plist

DOCSDIR?=	${PREFIX}/share/doc/${PORTNAME}
DOCS=		docs/README \
		docs/WebCalendar-Database.html \
		docs/WebCalendar-DeveloperGuide.html \
		docs/WebCalendar-Styling.html \
		docs/WebCalendar-SysAdmin.html \
		docs/newwin.gif

pre-install:
	cd ${WRKSRC} && ${FIND} -s * -type f | \
		${SED} -e 's|^|${WEBWCDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${WEBWCDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${WEBWCDIR} >> ${PLIST}
	${CAT} pkg-plist >> ${PLIST}

do-install:
	${MKDIR} ${PREFIX}/${WEBWCDIR}
	${CP} -R ${WRKSRC}/* ${PREFIX}/${WEBWCDIR}
	${CHOWN} -R www:www ${PREFIX}/${WEBWCDIR}
	${FIND} ${PREFIX}/${WEBWCDIR} -type f | ${XARGS} ${CHMOD} 644

post-install:
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${CAT} ${PKGMESSAGE} | ${SED} -e 's|%%PREFIX%%|${PREFIX}|g' -e 's|%%WEBWCDIR%%|${WEBWCDIR}|g' -e 's|%%DOCSDIR%%|${DOCSDIR}|g'

.include <bsd.port.mk>
