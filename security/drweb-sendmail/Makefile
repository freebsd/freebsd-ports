# New ports collection makefile for:   tas
# Date created:        14 August 2001
# Whom:                Anton Voronin <anton@urc.ac.ru>
#
# $FreeBSD$
#

PORTNAME=	drweb_sendmail
PORTVERSION=	4.25
CATEGORIES=	security mail
MASTER_SITES=	http://www.drweb.ru/ftp/web_pub/
DISTNAME=	drwebd-${PORTVERSION}-freebsd4
EXTRACT_SUFX=	.tgz

MAINTAINER=	anton@urc.ac.ru

RUN_DEPENDS=	${LOCALBASE}/drweb/drwebd:${PORTSDIR}/security/drweb

WRKSRC=		${WRKDIR}/${DISTNAME}/clients/drwebdc
MAKEFILE=	Makefile.unix

.include <bsd.port.pre.mk>

INST_PREFIX=	${PREFIX}/${PORTNAME}
SENDMAIL_DIR=	/usr/src/contrib/sendmail
MF_INCDIR=	${SENDMAIL_DIR}/include/libmilter
DOC_DIR=	${PREFIX}/share/doc/drweb-sendmail

.if exists( ${MF_INCDIR}/mfapi.h )

SENDMAIL_VERSION!=	${AWK} '/^sendmail [0-9.]+$$/{print $$2}' ${SENDMAIL_DIR}/FREEBSD-upgrade
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
IGNORE=	"depends on the system sources. Please place them under /usr/src first"
.endif

post-extract:
	cd ${WRKDIR}/${DISTNAME} && ${TAR} -xzf ${WRKDIR}/${DISTNAME}/${DISTNAME}.tar.gz clients/drwebdc clients/sendmail

pre-build:
	${MKDIR} ${WRKSRC}/libmilter
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/libmilter
.if ${SENDMAIL_VERSION} == "8.11.1"
	${CP} ${SENDMAIL_DIR}/libmilter/listener.c ${WRKSRC}/libmilter
	${LN} -s ${SENDMAIL_DIR}/libmilter/libmilter.h ${WRKSRC}/libmilter
	cd ${WRKSRC}/libmilter && ${PATCH} < ${WRKSRC}/../sendmail/listener.patch
.endif
	cd ${WRKSRC}/libmilter && ${MAKE} clean && ${MAKE}
	cd ${WRKSRC} && { \
		${ECHO} ; \
		${ECHO} ${MF_INCDIR} ; \
		${ECHO} libmilter ; \
		${ECHO} ${SENDMAIL8_12} ; \
		${ECHO} ${CFLAGS} ; \
	} | ./configure

do-install:
	${MKDIR} ${DOC_DIR}
	${INSTALL_PROGRAM} ${WRKSRC}/drweb-smf ${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/../sendmail/readme.sendmail ${DOC_DIR}
	${INSTALL_DATA} ${WRKSRC}/../sendmail/readme.sendmail.rus ${DOC_DIR}
	${SED} 's#!!PREFIX!!#${PREFIX}#' < ${FILESDIR}/drweb-smf.sh >${WRKSRC}/drwebsmf.sh
	${INSTALL_SCRIPT} ${WRKSRC}/drweb-smf.sh ${PREFIX}/etc/rc.d
	@${CAT} pkg-message

.include <bsd.port.post.mk>
