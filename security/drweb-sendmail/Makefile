# New ports collection makefile for:   drweb_sendmail
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb_sendmail
PORTVERSION=    4.27
CATEGORIES=	security mail
MASTER_SITES=	http://www.drweb.ru/ftp/web_pub/
DISTNAME=	drwebd-${PORTVERSION}-freebsd4
EXTRACT_SUFX=	.tgz

MAINTAINER=	anton@urc.ac.ru

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

WRKSRC=		${WRKDIR}/${DISTNAME}/clients/drwebdc

.include <bsd.port.pre.mk>

INST_PREFIX=	${PREFIX}/${PORTNAME}
WITH_DRWEBSMF_SENDMAIL_DIR=     /usr/src/contrib/sendmail
LIBSMUTIL_DIR=  /usr/src/lib/libsmutil
DOC_DIR=	${PREFIX}/share/doc/drweb-sendmail

.if !defined(WITH_DRWEBSMF_HOSTNAME)
.if defined(BATCH)
WITH_DRWEBSMF_HOSTNAME= your.domain.name
.else
WITH_DRWEBSMF_HOSTNAME!=hostname
.endif
.endif

.if exists( ${WITH_DRWEBSMF_SENDMAIL_DIR}/include/libmilter/mfapi.h )

SENDMAIL_VERSION!=      ${AWK} '/^sendmail [0-9.]+$$/{print $$2}' ${WITH_DRWEBSMF_SENDMAIL_DIR}/FREEBSD-upgrade
SENDMAIL_MAJOR!=	${ECHO} ${SENDMAIL_VERSION} | ${AWK} 'BEGIN{ FS="." }{ print $$1 }'
SENDMAIL_MINOR!=	${ECHO} ${SENDMAIL_VERSION} | ${AWK} 'BEGIN{ FS="." }{ print $$2 }'
.if ${SENDMAIL_MAJOR} > 8 || ${SENDMAIL_MAJOR} == 8 && ${SENDMAIL_MINOR} >= 12
SENDMAIL8_12=	y
.elif ${SENDMAIL_MAJOR} == 8 && ${SENDMAIL_MINOR} >= 10
SENDMAIL8_12=	n
.else
IGNORE=	"uses Sendmail sources that are expected to have version 8.10.0 or newer. Your system sources are too old - please upgrade them"
.endif

.else
IGNORE= "depends on the Sendmail sources. Please place them somewhere first and point WITH_DRWEBSMF_SENDMAIL_DIR there"
.endif

post-extract:
	cd ${WRKDIR}/${DISTNAME} && \
		${TAR} -xzf ${WRKDIR}/${DISTNAME}/${DISTNAME}.tar.gz \
		clients/sendmail clients/drwebdc

post-configure:
	${MKDIR} ${WRKSRC}/libmilter ${WRKSRC}/libsmutil
	${CP} ${FILESDIR}/Makefile.libmilter ${WRKSRC}/libmilter/Makefile
	${CP} ${FILESDIR}/Makefile.libsmutil ${WRKSRC}/libsmutil/Makefile
.if ${SENDMAIL_VERSION} == "8.11.1"
	${CP} ${WITH_DRWEBSMF_SENDMAIL_DIR}/libmilter/listener.c ${WRKSRC}/libmilter
	cd ${WRKSRC}/libmilter && ${PATCH} < ${WRKSRC}/../sendmail/listener-8.11.1.patch
.elif ${SENDMAIL_VERSION} == "8.12.0"
	${CP} ${WITH_DRWEBSMF_SENDMAIL_DIR}/libmilter/listener.c ${WRKSRC}/libmilter
	cd ${WRKSRC}/libmilter && ${PATCH} < ${WRKSRC}/../sendmail/listener-8.12.0.patch
.endif
	cd ${WRKSRC}/libmilter && ${MAKE} clean && ${MAKE} SENDMAIL_DIR=${WITH_DRWEBSMF_SENDMAIL_DIR}
	cd ${WRKSRC}/libsmutil && ${MAKE} clean && ${MAKE} SENDMAIL_DIR=${WITH_DRWEBSMF_SENDMAIL_DIR}
	cd ${WRKSRC} && { \
		${ECHO} y; \
		${ECHO} n; \
		${ECHO} y; \
		${ECHO} ${SENDMAIL8_12} ; \
		${ECHO} ${WITH_DRWEBSMF_SENDMAIL_DIR} ; \
		${ECHO} ${CFLAGS} ; \
		${ECHO} y; \
	} | ./configure

do-install:
	${MKDIR} ${DOC_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/drweb-smf ${PREFIX}/sbin/
	${INSTALL_PROGRAM} ${WRKSRC}/drwebdc ${PREFIX}/sbin/
	cd ${WRKSRC}/../sendmail && { \
		${ECHO} y; \
		${ECHO} "${PREFIX}/sbin"; \
		${ECHO} ; \
		${ECHO} u; \
		${ECHO} "${PREFIX}/drweb/run/drweb-smf.sock"; \
		${ECHO} drweb; \
		${ECHO} "${PREFIX}/drweb/infected"; \
		${ECHO} y; \
		${ECHO} /tmp; \
		${ECHO} y; \
		${ECHO} y; \
		${ECHO} ; \
		${ECHO} postmaster@${WITH_DRWEBSMF_HOSTNAME}; \
		${ECHO} y; \
		${ECHO} y; \
		${ECHO} y; \
		${ECHO} c; \
		${ECHO} t; \
		${ECHO} t; \
		${ECHO} t; \
		${ECHO} a; \
		${ECHO} r; \
		${ECHO} 160000; \
		${ECHO} ${SENDMAIL8_12} ; \
		${ECHO} n; \
		${ECHO} y; \
		${ECHO} ; \
	} | ./configure
	cd ${WRKSRC}/../sendmail; \
		${INSTALL_DATA} example* readme.* sendmail.*.addon ${DOC_DIR}
	cd ${WRKSRC}/../sendmail; \
		${INSTALL_DATA} drweb-sendmail.sh \
		${PREFIX}/etc/rc.d/drweb-sendmail.sh-dist
	if [ ! -f ${PREFIX}/etc/rc.d/drweb-sendmail.sh ] ; then \
		cd ${WRKSRC}/../sendmail; \
			${INSTALL_SCRIPT} drweb-sendmail.sh \
			${PREFIX}/etc/rc.d/; \
	fi

post-install:
	PKG_PREFIX=${PREFIX} ${SH} pkg-install ${PKGNAME} POST-INSTALL
	@echo
	@${CAT} pkg-message
	@echo
	@echo "Read documentation about additional sendmail tuning needed"
	@echo "in ${DOC_DIR}."

.include <bsd.port.post.mk>
