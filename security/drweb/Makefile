# New ports collection makefile for:   drweb
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@chelcom.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb
PORTVERSION=	4.32.2
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.drweb.ru/pub/unix/FreeBSD/49/ \
		ftp://ftp.drweb.ru/pub/unix/FreeBSD/53/

MAINTAINER=	support@spectrum.ru
COMMENT=	DrWeb antivirus suite

ONLY_FOR_ARCHS=	i386
NO_BUILD=	yes

RUN_DEPENDS=	${LOCALBASE}/bin/wget:${PORTSDIR}/ftp/wget

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd49
.else
DISTNAME=	${PORTNAME}-${PORTVERSION}-freebsd53
.if ${OSVERSION} >= 600000
LIB_DEPENDS+=	c.5:${PORTSDIR}/misc/compat5x
.endif
.endif

WRKSRC=		${WRKDIR}/${DISTNAME}

DRWEB_PREFIX=	${PREFIX}/${PORTNAME}

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Warning!"
	@${ECHO_MSG} "4.32* version not supported in the .key files of 4.31* version and older."
	@${ECHO_MSG} "Press Ctrl-C if you want to stop installation."
	@${ECHO_MSG} ""

do-install:
	-@${INSTALL} -dv -o ${BINOWN} -g ${BINGRP} ${DRWEB_PREFIX}
	@cd ${DRWEB_PREFIX}; ${RM} -f drweb drwebd bases/* updates/*; ${MKDIR} updates
	${TAR} -cf - -C ${WRKSRC}/usr/local/drweb . | \
		${TAR} -xf - -C ${DRWEB_PREFIX} \
		--exclude "*.static" \
		--exclude "update/update.pl*"
	${TAR} -cf - -C ${WRKSRC}/var/drweb bases | \
		${TAR} -xf - -C ${DRWEB_PREFIX}
	${CHMOD} 755 ${DRWEB_PREFIX}/bases ${DRWEB_PREFIX}/doc \
		${DRWEB_PREFIX}/lib ${DRWEB_PREFIX}/updates
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/drweb/update/update.pl \
		> ${DRWEB_PREFIX}/update/update.pl
	${CHMOD} 750 ${DRWEB_PREFIX}/update/update.pl
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/etc/drweb/drweb32.ini \
		> ${PREFIX}/drweb/drweb32.ini-distr
	${RM} -f ${PREFIX}/bin/drweb
	if [ ! -f ${PREFIX}/drweb/drweb32.ini ] ; then \
		${CP} ${PREFIX}/drweb/drweb32.ini-distr \
		      ${PREFIX}/drweb/drweb32.ini; \
	fi
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${FILESDIR}/drweb.sh \
		> ${WRKDIR}/drweb
	${INSTALL_SCRIPT} ${WRKDIR}/drweb ${PREFIX}/bin
	${SED} 's#%INSTALL%#${DRWEB_PREFIX}#g' \
		< ${WRKSRC}/usr/local/etc/rc.d/00.drwebd.sh \
		> ${PREFIX}/etc/rc.d/00.drwebd.sh
	${CHMOD} 750 ${PREFIX}/etc/rc.d/00.drwebd.sh
	${INSTALL_DATA} ${WRKSRC}/usr/local/etc/drweb/email.ini \
		${PREFIX}/drweb/email.ini-distr
	if [ ! -f ${PREFIX}/drweb/email.ini ] ; then \
		${CP} ${PREFIX}/drweb/email.ini-distr \
		${PREFIX}/drweb/email.ini; \
	fi

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
