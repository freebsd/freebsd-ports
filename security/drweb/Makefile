# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.31.4
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/generic/ \
		ftp://ftp.drweb.ru/pub/unix/archive/ \
		ftp://ftp.drweb.ru/pub/unix/archive/${PORTNAME}-${PORTVERSION}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	DrWeb antivirus suite

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

BROKEN=		Unfetchable

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd4
.else
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd5
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

do-install:
	-@${INSTALL} -dv -o ${BINOWN} -g ${BINGRP} ${DRWEB_PREFIX}
	@cd ${DRWEB_PREFIX}; ${RM} -f drweb drwebd bases/* updates/*; ${MKDIR} updates
	${TAR} -cf - -C ${WRKSRC}/usr/local/drweb . | \
		${TAR} -xf - -C ${DRWEB_PREFIX} \
		--exclude "*.key" \
		--exclude "*.static" \
		--exclude "update/update.pl*"
	${TAR} -cf - -C ${WRKSRC}/var/drweb bases | \
		${TAR} -xf - -C ${DRWEB_PREFIX}
	${CHMOD} 755 ${DRWEB_PREFIX}/bases ${DRWEB_PREFIX}/doc \
		${DRWEB_PREFIX}/lib ${DRWEB_PREFIX}/updates
	${INSTALL_DATA} ${WRKSRC}/usr/local/drweb/drweb.key-distr \
		${DRWEB_PREFIX}/drweb.key-distr
	${INSTALL_DATA} ${WRKSRC}/usr/local/drweb/drwebd.key-distr \
		${DRWEB_PREFIX}/drwebd.key-distr
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/drweb/update/update.pl \
		> ${DRWEB_PREFIX}/update/update.pl
	${CHMOD} 750 ${DRWEB_PREFIX}/update/update.pl
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/etc/drweb/drweb32.ini \
		> ${PREFIX}/drweb/drweb32.ini-distr
	${RM} -f ${PREFIX}/bin/drweb
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/etc/rc.d/00drwebd.sh \
		> ${PREFIX}/etc/rc.d/00drwebd.sh
	${CHMOD} 755 ${PREFIX}/etc/rc.d/00drwebd.sh
	if [ ! -f ${PREFIX}/drweb/drweb32.ini ] ; then \
		${CP} ${PREFIX}/drweb/drweb32.ini-distr \
		      ${PREFIX}/drweb/drweb32.ini; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/drweb.key ] ; then \
		${CP} ${DRWEB_PREFIX}/drweb.key-distr \
		      ${DRWEB_PREFIX}/drweb.key; \
	fi
	if [ ! -f ${DRWEB_PREFIX}/drwebd.key ] ; then \
		${CP} ${DRWEB_PREFIX}/drwebd.key-distr \
		      ${DRWEB_PREFIX}/drwebd.key; \
	fi
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${FILESDIR}/drweb.sh \
		> ${WRKDIR}/drweb
	${INSTALL_SCRIPT} ${WRKDIR}/drweb ${PREFIX}/bin

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
