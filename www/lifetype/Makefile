# New ports collection makefile for:	lifetype
# Date created:		Wed Jan 11 09:37:54 CST 2006
# Whom:			clsung
#
# $FreeBSD$
#

PORTNAME=	lifetype
PORTVERSION=	1.0.4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lifetype
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTVERSION:R}__all_plugins${EXTRACT_SUFX} \
		${PORTVERSION:R}__all_templates${EXTRACT_SUFX}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A PHP and MySQL based blogging platform

IGNOREFILES=	${PORTVERSION:R}__all_plugins${EXTRACT_SUFX} \
		${PORTVERSION:R}__all_templates${EXTRACT_SUFX}

USE_ZIP=	YES

USE_PHP=	ctype mysql pcre session xml
NO_BUILD=	YES
WANT_PHP_WEB=	YES
WWWDOCROOT?=	www/data
PLOGURL?=	lifetype
WWWOWN?=	www
WWWGRP?=	www
PLOGDIR?=	${WWWDOCROOT}/${PLOGURL}
PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message

OPTIONS=	BIG5		"With Big5 chinese template fix" off \
		GD		"With GD Support" on \
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

post-extract:
.for x in plugins templates
	cd ${WRKSRC}/${x} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${PORTVERSION:R}__all_${x}${EXTRACT_SUFX}
.endfor

.if defined(WITH_BIG5)

post-patch:
	${FIND} ${WRKSRC}/templates -name "*.template" | \
		${XARGS} ${REINPLACE_CMD} -e 's/|capitalize//g' -e 's/%b/%B/g'
	${FIND} ${WRKSRC}/templates -name "*.template.bak" -delete
.endif
pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC} && ${FIND} -s . -type f | \
		${SED} -e 's|^./||;s|^|${PLOGDIR}/|' > ${PLIST} \
		&& ${ECHO_CMD} "@unexec ${RM} -fr %D/${PLOGDIR}/tmp/* 2>/dev/null || ${TRUE}" >> ${PLIST} \
		&& ${FIND} -d * -type d | \
		${SED} -e 's|^|@dirrm ${PLOGDIR}/|' >> ${PLIST} \
		&& ${ECHO_CMD} @dirrm ${PLOGDIR} >> ${PLIST}

do-install:
	@${MKDIR} ${PREFIX}/${PLOGDIR}
	@${CP} -R ${WRKSRC}/ ${PREFIX}/${PLOGDIR}
	@${CHOWN} -R ${WWWOWN}:${WWWGRP} ${PREFIX}/${PLOGDIR}

post-install:
	@${SED} -e 's|%%PLOGURL%%|${PLOGURL}|' pkg-message > ${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
