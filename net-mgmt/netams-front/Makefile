# New ports collection makefile for:	netams-front
# Date created:				Sun 10 May 2009
# Whom:					Alexey V. Degtyarev
#
# $FreeBSD$
#

PORTNAME=	netams-front
PORTVERSION=	0.4
CATEGORIES=	net-mgmt www
MASTER_SITES=	ftp://ftp.renatasystems.org/pub/FreeBSD/ports/distfiles/

MAINTAINER=	alexey@renatasystems.org
COMMENT=	PHP-based web interface for NeTAMS software

NO_BUILD=	yes

USE_MYSQL=	yes
WANT_PHP_WEB=	yes
USE_PHP=	mysql pcre

SUB_FILES=	pkg-message

# This target is only meant to be used by the port maintainer.
x-generate-plist: build
	cd ${WRKSRC}/www; \
	${FIND} . ! -type d ! -name '*.orig' | ${SORT} | \
	    ${SED} -e "s,^\.,%%WWWDIR%%," >${.CURDIR}/pkg-plist.tmp ; \
	${FIND} . -type d | ${SORT} -r | ${SED} \
	     -e "s,^\.$$,@dirrmtry %%WWWDIR%%," \
	     -e "s,^\.,@dirrm %%WWWDIR%%," >>${.CURDIR}/pkg-plist.tmp
do-install:
	@cd ${WRKSRC}/www; \
	for src in $$( ${FIND} . ! -name '*.orig' -a \
			! -name 'config.php.simple' ) ; do \
		dst=${WWWDIR}$${src#.} ; \
		if ${TEST} -d $$src ; then \
			${MKDIR} $$dst ; \
		else \
			${INSTALL_DATA} $$src $$dst ; \
		fi \
	done
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/www/config.php.simple \
		${EXAMPLESDIR}/config.php
	@if ! ${TEST} -f ${WWWDIR}/config.php; then \
		${INSTALL_DATA} ${WRKSRC}/www/config.php.simple \
		${WWWDIR}/config.php; \
	fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
