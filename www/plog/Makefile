# New ports collection makefile for:	plog
# Date created:		2004-10-27
# Whom:			clsung
#
# $FreeBSD$
#

PORTNAME=	plog
PORTVERSION=	0.3.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	plog

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A PHP and MySQL based blogging platform

USE_BZIP2=	YES

USE_PHP=	mysql
PHP4_PORT?=	www/mod_php4
NO_BUILD=	YES
WANT_PHP_WEB=	YES
PLOGDIR?=	www/data-dist/plog
PLIST=		${WRKDIR}/pkg-plist

OPTIONS=	GD		"With GD Support" on \
		IMAGICK		"With ImageMagick Support" off

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_GD)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/gd.so:${PORTSDIR}/${gd_DEPENDS}
.endif

.if defined(WITH_IMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/lib/php/${PHP_EXT_DIR}/imagick.so:${PORTSDIR}/${imagick_DEPENDS}
.endif

.if defined(WITHOUT_GD) && !defined(WITH_IMAGICK)
pre-patch:
	@${ECHO_CMD} "Without GD or ImageMagick support. No thumbnails will be generated at all."
.endif

pre-install:
	@${RM} ${WRKSRC}/.cvsignore
	cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${PLOGDIR}/|' > ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${PLOGDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PLOGDIR} >> ${PLIST}

do-install:
	-${MKDIR} ${PREFIX}/${PLOGDIR}
	@${CHOWN} www:www ${PREFIX}/${PLOGDIR}
	@${CHMOD} 755 ${PREFIX}/${PLOGDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PLOGDIR}
	@${CHOWN} www:www ${PREFIX}/${PLOGDIR}/tmp

post-install:
	@${SED} -e 's|%%PLOGDIR%%|${PREFIX}/${PLOGDIR}|' ${PKGMESSAGE}

.include <bsd.port.post.mk>
