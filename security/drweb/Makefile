# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=    4.27
CATEGORIES=	security
MASTER_SITES=   http://www.drweb.ru/ftp/web_pub/ \
		http://www.drweb.ru/ftp/update_free/freebsd4/
DISTFILES=      ${MAIN_NAME}.tgz \
		drwebd_4.27_freebsd4_update.tgz
EXTRACT_ONLY=   ${MAIN_NAME}.tgz

MAINTAINER=	anton@urc.ac.ru

NO_BUILD=	YES

WRKSRC=         ${WRKDIR}/${MAIN_NAME}

# Needed for update.pl
RUN_DEPENDS=    ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32

MAIN_NAME=      ${PORTNAME}d-${PORTVERSION}-freebsd4
DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

do-install:
	-@install -dv -o ${BINOWN} -g ${BINGRP} ${DRWEB_PREFIX}
	@cd ${DRWEB_PREFIX}; ${RM} -f drw*.txt drw*.vdb drweb drwebd
	${TAR} -xzf ${WRKSRC}/${MAIN_NAME}.tar.gz -C ${DRWEB_PREFIX} \
		--exclude *.ini --exclude *.key
	${TAR} -xzf ${DISTDIR}/drwebd_4.27_freebsd4_update.tgz -C ${DRWEB_PREFIX} \
		--exclude README
	${TAR} -xzOf ${WRKSRC}/${MAIN_NAME}.tar.gz drweb32.ini \
		> ${DRWEB_PREFIX}/drweb32.ini-tmpl
	${TAR} -xzOf ${WRKSRC}/${MAIN_NAME}.tar.gz drweb.key \
		> ${DRWEB_PREFIX}/drweb.key-dist
	${TAR} -xzOf ${WRKSRC}/${MAIN_NAME}.tar.gz drwebd.key \
		> ${DRWEB_PREFIX}/drwebd.key-dist
	cd ${DRWEB_PREFIX}; \
		${PATCH} -s < ${FILESDIR}/ini-patch && \
		${RM} drweb32.ini-tmpl.orig
	cd ${DRWEB_PREFIX}; \
		${SED} 's#__INSTALL_DIR__#${DRWEB_PREFIX}#' \
		< drweb32.ini-tmpl > drweb32.ini-dist && \
		${RM} drweb32.ini-tmpl
	if [ ! -f ${DRWEB_PREFIX}/drweb32.ini ] ; then \
		${CP} ${DRWEB_PREFIX}/drweb32.ini-dist \
		      ${DRWEB_PREFIX}/drweb32.ini; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/drweb.key ] ; then \
		${CP} ${DRWEB_PREFIX}/drweb.key-dist \
		      ${DRWEB_PREFIX}/drweb.key; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/drwebd.key ] ; then \
		${CP} ${DRWEB_PREFIX}/drwebd.key-dist \
		      ${DRWEB_PREFIX}/drwebd.key; \
	fi

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
