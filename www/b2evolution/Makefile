# New ports collection makefile for:	b2evo
# Date created:		2005-04-16
# Whom:			chinsan <chinsan@mail20000.com.tw>
#
# $FreeBSD$
#

PORTNAME=	b2evolution
PORTVERSION=	0.9.0.12
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	evocms
DISTNAME=	${PORTNAME}-${PORTVERSION}-${B2EVODATE}

MAINTAINER=	chinsan.tw@gmail.com
COMMENT=	A multilingual, multiuser, multi-blog engine

USE_ZIP=	YES

B2EVODATE?=	2005-05-06
USE_PHP=	mysql pcre session
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES

TMPDIR?=	b2evolution
WRKSRC=		${WRKDIR}/${TMPDIR}
WWWDOCROOT?=	www/data-dist
B2EVOURL?=	b2evo
WWWOWN?=	www
WWWGRP?=	www
B2EVODIR?=	${WWWDOCROOT}/${B2EVOURL}
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${B2EVODIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${B2EVODIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${B2EVODIR} >> ${PLIST}

do-install:
	-${MKDIR} ${PREFIX}/${B2EVODIR}
	@${CHOWN} ${WWWOWN}:${WWWGRP} ${PREFIX}/${B2EVODIR}
	@${CHMOD} 755 ${PREFIX}/${B2EVODIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${B2EVODIR}

post-install:
	@${SED} -e 's|%%B2EVOURL%%|${B2EVOURL}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
