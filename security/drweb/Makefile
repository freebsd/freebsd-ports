# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=    4.29
CATEGORIES=	security
MASTER_SITES=   ftp://ftp.drweb.ru/pub/unix/
DISTFILES=      ${MAIN_NAME}.tgz

MAINTAINER=	anton@chelcom.ru

ONLY_FOR_ARCHS=	i386
NO_BUILD=       yes

WRKSRC=         ${WRKDIR}/${MAIN_NAME}/install

# Needed for update.pl
RUN_DEPENDS=    ${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/String/CRC32.pm:${PORTSDIR}/devel/p5-String-CRC32

MAIN_NAME=      ${PORTNAME}-${PORTVERSION}-freebsd4
DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

do-install:
	-@install -dv -o ${BINOWN} -g ${BINGRP} ${DRWEB_PREFIX}
	@cd ${DRWEB_PREFIX}; ${RM} -f drweb drwebd bases/* updates/*
	${TAR} -cf - -C ${WRKSRC}/opt/drweb . | \
		${TAR} -xf - -C ${DRWEB_PREFIX} \
		--exclude "*.key" --exclude "update/update.pl*"
	${TAR} -cf - -C ${WRKSRC}/var/drweb bases | \
		${TAR} -xf - -C ${DRWEB_PREFIX}
	chmod 755 ${DRWEB_PREFIX}/bases ${DRWEB_PREFIX}/doc \
		${DRWEB_PREFIX}/lib ${DRWEB_PREFIX}/updates
	${INSTALL_DATA} ${WRKSRC}/opt/drweb/drweb.key \
		${DRWEB_PREFIX}/drweb.key-dist
	${INSTALL_DATA} ${WRKSRC}/opt/drweb/drwebd.key \
		${DRWEB_PREFIX}/drwebd.key-dist
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/opt/drweb/update/update.pl \
		> ${DRWEB_PREFIX}/update/update.pl
	chmod 750 ${DRWEB_PREFIX}/update/update.pl
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/etc/drweb/drweb32.ini \
		> ${DRWEB_PREFIX}/drweb32.ini-dist
	${RM} -f ${PREFIX}/bin/drweb
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${FILESDIR}/drweb.sh \
		> ${PREFIX}/bin/drweb
	chmod 755 ${PREFIX}/bin/drweb
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
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
