# New ports collection makefile for:	runit
# Date created:		2003-06-20
# Whom:			Sergei Kolobov <sergei@kolobov.com>
#
# $FreeBSD$
#

PORTNAME=	runit
PORTVERSION=	2.1.1
CATEGORIES=	sysutils
MASTER_SITES=	http://smarden.org/${PORTNAME}/ \
		http://www.bayofrum.net/dist/${PORTNAME}/

MAINTAINER=	crees@FreeBSD.org
COMMENT=	Service supervision tools compatible with DJB daemontools

USE_RC_SUBR=	runsvdir
WRKSRC=		${WRKDIR}/admin/${DISTNAME}

SERVICE_DIR?=	/var/service
SUB_LIST=	SERVICE_DIR="${SERVICE_DIR}"
PORTDOCS=	*

MAN8=		chpst.8 runit-init.8 runit.8 runsv.8 runsvchdir.8 \
		runsvdir.8 sv.8 svlogd.8 utmpset.8
DOCS=		package/CHANGES package/COPYING package/README \
		package/THANKS doc/*.html
CONFIG=		etc/freebsd/1 etc/2 etc/freebsd/3 etc/freebsd/ctrlaltdel \
	 	etc/freebsd/getty-ttyv4/run etc/freebsd/getty-ttyv4/finish

do-configure:
	${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/src/conf-cc

do-build:
	cd ${WRKSRC} && package/compile && package/check
	@${MKDIR} ${WRKDIR}/etc/getty-ttyv4
.for file in ${CONFIG}
	@${SED} -e 's!/etc/runit!${ETCDIR}!g' \
		-e 's!/service!${SERVICE_DIR}!g' \
		-e 's!/usr/local!${PREFIX}!g' \
		${WRKSRC}/${file} > ${WRKDIR}/${file:S!freebsd/!!}.sample
.endfor

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/command/* ${PREFIX}/sbin
.for man in ${MAN8}
	@${INSTALL_MAN} ${WRKSRC}/man/${man} ${MAN8PREFIX}/man/man8
.endfor
	@${MKDIR} ${ETCDIR}/getty-ttyv4
	@${INSTALL_SCRIPT} ${WRKDIR}/etc/[123c]* ${ETCDIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/etc/getty-ttyv4/* \
		${ETCDIR}/getty-ttyv4
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.   for doc in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.   endfor
.endif

post-install:
	@for file in ${ETCDIR}/*.sample ${ETCDIR}/getty-ttyv4/*.sample ; \
	    do [ ! -f ${ETCDIR}/$${file%.sample} ] \
		&& ${CP} -p $${file} $${file%.sample} ; \
	    done

.include <bsd.port.mk>
