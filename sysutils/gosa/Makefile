# Created by: Denis Shaposhnikov <dsh@wizard.volgograd.ru>
# $FreeBSD$

PORTNAME=	gosa
PORTVERSION=	2.6.10
DISTVERSIONPREFIX=	combined-
PORTREVISION=	1
CATEGORIES=	sysutils www
MASTER_SITES=	http://oss.gonicus.de/pub/gosa/ \
		http://oss.gonicus.de/pub/gosa/archive/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web Based LDAP Administration Program

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	p5-Crypt-SmbHash>=0.12:security/p5-Crypt-SmbHash \
		pecl-imagick>=2.2.2:graphics/pecl-imagick

USES=		tar:bzip2
USE_PHP=	gettext iconv imap ldap mbstring hash mysql pcre posix \
		session spl xml zlib

NO_BUILD=	yes
NO_ARCH=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
REINPLACE_ARGS=	-i ""
SUB_FILES=	pkg-message
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}
PLIST_SUB+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} \
		-e 's!"/etc/gosa"!"${ETCDIR}"!g' \
		-e 's!"../contrib"!"${EXAMPLESDIR}/contrib"!g' \
		-e 's!"/var/cache/gosa/tmp"!"/tmp"!g' \
		${WRKSRC}/include/functions.inc

	${REINPLACE_CMD} \
		-e 's!/usr/bin/php!${PREFIX}/bin/php!g' \
		-e 's!("GOSA_HOME", dirname(__FILE__));!("GOSA_HOME", "${WWWDIR}");!g' \
		${WRKSRC}/update-gosa

.for i in doc/core/guide.xml html/helpviewer.php include/functions_helpviewer.inc
	${REINPLACE_CMD} -e 's!"../doc/!"${DOCSDIR}/!g' ${WRKSRC}/$i
.endfor

	${MV} -f ${WRKSRC}/contrib/gosa.conf.5 ${WRKSRC}
	${FIND} ${WRKSRC} -type f -name '*.orig' -exec ${RM} -f {} +

do-install:
	@${MKDIR} ${STAGEDIR}${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"html ihtml include locale plugins setup" ${STAGEDIR}${WWWDIR})
	${INSTALL_SCRIPT} ${WRKSRC}/update-gosa ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/update-gosa.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/gosa.conf.5 ${STAGEDIR}${MANPREFIX}/man/man5
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} contrib ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${ETCDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC} && ${INSTALL_DATA} AUTHORS COPYING Changelog FAQ \
		INSTALL README README.safemode ${STAGEDIR}${DOCSDIR})
	${MKDIR} ${STAGEDIR}/var/spool/gosa

.include <bsd.port.mk>
