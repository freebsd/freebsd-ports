# Created by: roam@FreeBSD.org
# $FreeBSD$

PORTNAME=	qmail-conf
PORTVERSION=	0.60
PORTREVISION=	4
CATEGORIES=	mail
MASTER_SITES=	LOCAL/oliver:conf \
		http://cr.yp.to/djbdns/:djbdns
DISTFILES=	${DISTNAME}.tar.gz:conf \
		${DJBDNS_DIST}:djbdns
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	oliver@FreeBSD.org
COMMENT=	Configure various qmail services to run under daemontools

USES=		qmail:run

ALL_TARGET=	prog
INSTALL_TARGET=	setup check

LEGAL_TEXT=	No license -- see http://cr.yp.to/softwarelaw.html

PREFIX?=	${QMAIL_PREFIX}
NO_PREFIX_RMDIR=yes

NO_MTREE=	yes

DJBDNS_VER=	1.05
DJBDNS_NAME=	djbdns-${DJBDNS_VER}
DJBDNS_DIST=	${DJBDNS_NAME}${EXTRACT_SUFX}

post-extract:
		@(cd ${WRKSRC} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DJBDNS_DIST} ${EXTRACT_AFTER_ARGS})

post-patch:
		@${ECHO_CMD} "${QMAIL_PREFIX}" > ${WRKSRC}/conf-qmail
		@${ECHO_CMD} "${CC} ${CFLAGS}" > ${WRKSRC}/conf-cc
		@${ECHO_CMD} "${CC} ${CFLAGS} ${STRIP}" > ${WRKSRC}/conf-ld
		@${ECHO_CMD} "${LOCALBASE}" > ${WRKSRC}/conf-ucspi-tcp

pre-build:
		@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} \
		    djbdns=${DJBDNS_NAME} -f Makefile.ini)

# Do a dance to stage and keep out of resulting binaries (see r346769
# and r349241)
post-build:
	@${ECHO_MSG} "===> Rebuilding DJB installer to respect STAGEDIR"
	@${MV} -f ${WRKSRC}/conf-qmail ${WRKSRC}/conf-qmail.sav
	@${ECHO_CMD} "${STAGEDIR}${QMAIL_PREFIX}" > ${WRKSRC}/conf-qmail
	@cd ${WRKSRC} ; ${RM} install instcheck install.o instcheck.o hier.o auto_qmail.o auto_qmail.c
	@cd ${WRKSRC} ; ${DO_MAKE_BUILD} install instcheck
	@${TOUCH} ${WRKSRC}/*-conf
	@${MV} -f ${WRKSRC}/conf-qmail.sav ${WRKSRC}/conf-qmail

.include <bsd.port.mk>
