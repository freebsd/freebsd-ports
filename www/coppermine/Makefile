# Ports collection makefile for:	coppermine
# Date created:				05 April 2004
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	coppermine
PORTVERSION=	1.3.3
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	cpg${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Coppermine is a web picture gallery script

USE_PHP=	mysql pcre
WANT_PHP_MOD=	yes
USE_ZIP=	yes

.if defined (WITH_IMAGEMAGICK)
RUN_DEPENDS+=	${LOCALBASE}/bin/convert:${PORTSDIR}/graphics/ImageMagick
.else
USE_PHP+=	gd
.endif

PKGMESSAGE=	${WRKDIR}/pkg-message
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/cpg133
DOCFILES=	CHANGELOG
EXCEPTFILES=	${DOCFILES} COPYING docs/COPYING
CPIOARGS=	--quiet -pdum -R
PLIST_SUB=	CPGDIR=${CPGDIR}

pre-fetch:
.if !defined(CPGDIR)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Define CPGDIR to override default of 'www/coppermine'."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "By default, coppermine depends on PHP with GD support."
	@${ECHO_MSG} "You may define WITH_IMAGEMAGICK to depend on ImageMagick instead of GD."
	@${ECHO_MSG} ""
.endif

post-extract:
	@${CHMOD} -R o-w ${WRKSRC}

pre-patch:
	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' \
	    -e 's|%%CPGDIR%%|${CPGDIR}|g' \
	    ${.CURDIR}/pkg-message > ${PKGMESSAGE}

CPGDIR?=	www/coppermine
WWWOWN?=	www
WWWGRP?=	www

do-install:
	@${MKDIR} -m 0755 ${PREFIX}/${CPGDIR}
	@cd ${WRKSRC} && \
	    ${FIND} . -name \*.orig ${EXCEPTFILES:S/^/-o -name /} -o -print | \
	    ${CPIO} ${CPIOARGS} ${WWWOWN}:${WWWGRP} ${PREFIX}/${CPGDIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} ${DOCFILES} ${DOCSDIR}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

########################################################################
# The following targets are for the port maintainer.  Use are your own #
# risk, no user-serviceable parts inside.                              #
########################################################################
# Assuming the port is installed cleanly (i.e. it's unconfigured)
# build a pkg-plist file.
build-plist:
	${FIND} ${DOCSDIR} -type f | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%%%DOCSDIR%%|' | \
	    ${SORT} > pkg-plist
	${FIND} ${PREFIX}/${CPGDIR}/* -type f | \
	    ${SED} -e 's|${PREFIX}/${CPGDIR}|%%CPGDIR%%|' | \
	    ${SORT} >> pkg-plist
	${FIND} ${PREFIX}/${CPGDIR}/* -type d | \
	    ${SED} -e 's|${PREFIX}/${CPGDIR}|@dirrm %%CPGDIR%%|' | \
	    ${SORT} -r >> pkg-plist
	${FIND} ${DOCSDIR} -type d | \
	    ${SED} -e 's|${DOCSDIR}|%%PORTDOCS%%@dirrm %%DOCSDIR%%|' | \
	    ${SORT} -r >> pkg-plist
	${ECHO} "@unexec rmdir %D/%%CPGDIR%% 2>/dev/null || true" \
	    >> pkg-plist

.include <bsd.port.mk>
