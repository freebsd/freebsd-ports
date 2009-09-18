# New ports collection makefile for:	gosa
# Date created:				Wed Dec 26 18:41:49 MSK 2007
# Whom:					Denis Shaposhnikov <dsh@wizard.volgograd.ru>
#
# $FreeBSD$
#

PORTNAME=	gosa
PORTVERSION=	2.6.5
PORTREVISION=	1
DISTVERSIONPREFIX=	complete-
CATEGORIES=	sysutils www
MASTER_SITES=	http://oss.gonicus.de/pub/gosa/ \
		http://oss.gonicus.de/pub/gosa/archive/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Web Based LDAP Administration Program

RUN_DEPENDS=	p5-Crypt-SmbHash>=0.12:${PORTSDIR}/security/p5-Crypt-SmbHash \
		pecl-imagick>=2.2.2:${PORTSDIR}/graphics/pecl-imagick

USE_BZIP2=	yes
USE_PHP=	gettext iconv imap ldap mbstring mhash mysql pcre posix \
		session spl xml zlib

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
REINPLACE_ARGS=	-i ""
SUB_FILES=	pkg-message
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

MAN1=		update-gosa.1
MAN5=		gosa.conf.5

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

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"html ihtml include locale plugins setup" ${WWWDIR})

	${INSTALL_SCRIPT} ${WRKSRC}/update-gosa   ${PREFIX}/sbin/
	${INSTALL_MAN}    ${WRKSRC}/update-gosa.1 ${MANPREFIX}/man/man1/
	${INSTALL_MAN}    ${WRKSRC}/gosa.conf.5   ${MANPREFIX}/man/man5/

	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "contrib" ${EXAMPLESDIR})

	${MKDIR} ${ETCDIR}
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} /var/spool/gosa

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${DOCSDIR})
.  for i in AUTHORS COPYING Changelog FAQ INSTALL README README.safemode
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

post-install:
	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
