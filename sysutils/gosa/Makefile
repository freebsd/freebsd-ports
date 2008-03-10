# New ports collection makefile for:	gosa
# Date created:				Wed Dec 26 18:41:49 MSK 2007
# Whom:					Denis Shaposhnikov <dsh@wizard.volgograd.ru>
#
# $FreeBSD$
#

PORTNAME=	gosa
PORTVERSION=	2.5.15
CATEGORIES=	sysutils www
MASTER_SITES=	http://oss.gonicus.de/pub/gosa/ \
		http://oss.gonicus.de/pub/gosa/archive/

MAINTAINER=	dsh@wizard.volgograd.ru
COMMENT=	Web Based LDAP Administration Program

RUN_DEPENDS=	p5-Crypt-SmbHash>=0.12:${PORTSDIR}/security/p5-Crypt-SmbHash

USE_BZIP2=	yes
USE_PHP=	gettext iconv imap ldap mhash posix

NO_BUILD=	yes
PKGMESSAGE=	${WRKDIR}/pkg-message
REINPLACE_ARGS=	-i ""
SUB_FILES=	pkg-message
SUB_LIST+=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	${REINPLACE_CMD} \
		-e 's!"/etc/gosa"!"${ETCDIR}"!g' \
		-e 's!"../contrib/"!"${EXAMPLESDIR}/contrib/"!g' \
		${WRKSRC}/include/functions.inc

.for i in admin devel
	${RM} -rf ${WRKSRC}/doc/guide/$i
.endfor
	${RM} -rf ${WRKSRC}/doc/guide/user/*/lyx-source
	${FIND} ${WRKSRC}/doc -name WARNINGS -exec ${RM} -f -- {} +
.for i in doc/guide.xml html/helpviewer.php include/functions_helpviewer.inc
	${REINPLACE_CMD} -e 's!"../doc/!"${DOCSDIR}/!g' ${WRKSRC}/$i
.endfor

do-install:
	${MKDIR} ${WWWDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"ihtml plugins html include setup locale" ${WWWDIR})

	${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "contrib" ${EXAMPLESDIR})

	${MKDIR} ${ETCDIR}
	${INSTALL} -d -o ${WWWOWN} -g ${WWWGRP} /var/spool/gosa

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} "*" ${DOCSDIR})
.  for i in AUTHORS COPYING Changelog FAQ INSTALL README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.  endfor
.endif

	${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
