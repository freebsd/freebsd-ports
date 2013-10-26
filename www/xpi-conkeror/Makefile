# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	conkeror
PORTVERSION=	20090821
PORTREVISION=	6
CATEGORIES=	www
MASTER_SITES=	http://mirror.4bit.ws/ \
		${MASTER_SITE_LOCAL} \
		${MASTER_SITE_FREEBSD}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	A completely keyboard driven browser based on firefox

WRKSRC=	${WRKDIR}/conkeror
USE_GECKO=	libxul

BUILD_ID=echo -n `whoami`@`hostname`_`date +%s`

NO_STAGE=	yes
post-patch:
	cd ${WRKSRC} && \
		${REINPLACE_CMD} -e "s/%%PREFIX%%/${PREFIX:S/\//\\\//g}/g" \
			${WRKSRC}/conkeror && \
		${MV} debian/conkeror.desktop . && \
		${RM} -rf debian tests && \
		${MKDIR} share  && \
		${MV} branding chrome components content \
			contrib defaults locale modules search-engines help style share

do-build:
	${MAKE} -C ${WRKSRC}

do-install:
	${MKDIR} ${PREFIX}/libexec/conkeror
	${MKDIR} ${DESKTOPDIR}
	cd ${WRKSRC}/share && ${COPYTREE_SHARE} . ${DATADIR}
	${SED} -e "s/BuildID=git/BuildID=$$(${BUILD_ID})/g" \
		-e "s/^Version=\(.*\)$$/Version=\1 (FreeBSD-${OSREL})/g" \
		<${WRKSRC}/application.ini >${DATADIR}/application.ini
	${REINPLACE_CMD} -e "s/\\\$$CONKEROR_VERSION\\$$/`${GREP} \
		'^Version=' ${WRKSRC}/application.ini |${SED} \
		-e 's/^Version=//'` (FreeBSD-${OSREL})/g" ${DATADIR}/components/application.js
	${INSTALL_SCRIPT} ${WRKSRC}/conkeror ${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/conkeror.desktop ${DESKTOPDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/conkeror-spawn-helper ${PREFIX}/libexec/conkeror/
	${LN} -sf ${PREFIX}/libexec/conkeror/conkeror-spawn-helper ${DATADIR}/

post-install:
	@-update-desktop-database

.include <bsd.port.mk>
