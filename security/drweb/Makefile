# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.30
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/
DISTFILES=	${MAIN_NAME}.tar.gz

MAINTAINER=	anton@chelcom.ru
COMMENT=	DrWeb antivirus suite

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

WRKSRC=		${WRKDIR}/${MAIN_NAME}

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
LIB_DEPENDS+=	c.4:${PORTSDIR}/misc/compat4x
MAIN_NAME=	${PORTNAME}-${PORTVERSION}-freebsd4
.else
MAIN_NAME=	${PORTNAME}-${PORTVERSION}-freebsd5
.endif

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

do-install:
	-@install -dv -o ${BINOWN} -g ${BINGRP} ${DRWEB_PREFIX}
	@cd ${DRWEB_PREFIX}; ${RM} -f drweb drwebd bases/* updates/*; ${MKDIR} updates
	${TAR} -cf - -C ${WRKSRC}/usr/local/drweb . | \
		${TAR} -xf - -C ${DRWEB_PREFIX} \
		--exclude "*.key" \
		--exclude "*.static" \
		--exclude "update/update.pl*"
	${TAR} -cf - -C ${WRKSRC}/var/drweb bases | \
		${TAR} -xf - -C ${DRWEB_PREFIX}
	chmod 755 ${DRWEB_PREFIX}/bases ${DRWEB_PREFIX}/doc \
		${DRWEB_PREFIX}/lib ${DRWEB_PREFIX}/updates
	${INSTALL_DATA} ${WRKSRC}/usr/local/drweb/drweb.key \
		${DRWEB_PREFIX}/drweb.key-dist
	${INSTALL_DATA} ${WRKSRC}/usr/local/drweb/drwebd.key \
		${DRWEB_PREFIX}/drwebd.key-dist
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/drweb/update/update.pl \
		> ${DRWEB_PREFIX}/update/update.pl
	chmod 750 ${DRWEB_PREFIX}/update/update.pl
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/etc/drweb/drweb32.ini \
		> ${PREFIX}/drweb/drweb32.ini-dist
	${RM} -f ${PREFIX}/bin/drweb
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/etc/rc.d/00drwebd.sh \
		> ${PREFIX}/etc/rc.d/00drwebd.sh
	chmod 755 ${PREFIX}/etc/rc.d/00drwebd.sh
	if [ ! -f ${PREFIX}/drweb/drweb32.ini ] ; then \
		${CP} ${PREFIX}/drweb/drweb32.ini-dist \
		      ${PREFIX}/drweb/drweb32.ini; \
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

.include <bsd.port.post.mk>
