# New ports collection makefile for:	qmail-tls
# Date created:				03 Dec 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${TLS_PATCH_DATE}
PORTREVISION=	1
CATEGORIES=	mail
PKGNAMESUFFIX=	-tls

PATCH_SITES+=	http://www.esat.kuleuven.ac.be/~vermeule/qmail/
PATCHFILES+=	tls.patch
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	lioux@FreeBSD.org

USE_OPENSSL=	YES

TLS_PATCH_DATE=	20000823

# Using default from master port, i.e., /var/qmail
PREFIX?=	${QMAIL_PORT_PREFIX}
#PREFIX=		/var/qmail-tls

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

CFLAGS+=	-I${OPENSSLBASE}/include -L${OPENSSLBASE}/lib -DTLS

.if defined(WITH_TLS_DEBUG)
CFLAGS+=	-DDEBUG
.endif # WITH_TLS_DEBUG

#QMAIL_PORT=	${PORTSDIR}/mail/qmail
QMAIL_PORT=	${.CURDIR}/../qmail
QMAIL_PORT_PREFIX!=	cd ${QMAIL_PORT} && ${MAKE} -V PREFIX

DOCFILES+=	${WRKDIR}/TLS.readme

slaveport-pre-fetch: qmail-tls-pre-fetch

qmail-tls-pre-fetch:
	@${ECHO_MSG} "WITH_TLS_DEBUG=yes		enable additional debug information"

slaveport-post-patch: qmail-tls-post-patch

qmail-tls-post-patch:
	@${HEAD} -74 ${DISTDIR}/tls.patch > ${WRKDIR}/TLS.readme
	@${PERL} -pi -ne "s|/usr/local/ssl|${OPENSSLBASE}|" ${WRKSRC}/Makefile

# Primary Ugh... ;-)
# idea stolen from www/apache13-ssl, a target written by adam@algroup.co.uk
# internal code ripped from tls.patch guts ;-) written by Frederik Vermeulen <jos-tls@kotnet.org>

certificate:
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; \
	then \
		if [ ! -d ${WRKDIR} ]; \
		then \
			${MKDIR} ${WRKDIR} ; \
		fi ; \
		${OPENSSLBASE}/bin/openssl req -new -x509 -nodes \
			-out ${WRKDIR}/cert.pem -days 366 \
			-keyout ${WRKDIR}/cert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/cert.pem ${PREFIX}/control/cert.pem ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi

certificate-req:
	@if [ -f ${OPENSSLDIR}/openssl.cnf ]; \
	then \
		if [ ! -d ${WRKDIR} ]; \
		then \
			${MKDIR} ${WRKDIR} ; \
		fi ; \
		${OPENSSLBASE}/bin/openssl req -new -nodes \
			-out ${WRKDIR}/req.pem \
			-keyout ${WRKDIR}/cert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/cert.pem ${PREFIX}/control/cert.pem ; \
		${ECHO_MSG} ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
		${ECHO_MSG} "===> Send ${WRKDIR}/req.pem to your CA to obtain signed_req.pem, and do:" ; \
		${ECHO_MSG} "===> cat signed_req.pem >> ${PREFIX}/control/cert.pem" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi

# Local overrides
MASTERDIR=	${QMAIL_PORT}
PKGDIR_LOCAL=	${.CURDIR}
COMMENT=	${PKGDIR_LOCAL}/pkg-comment
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message
PLIST=		${PKGDIR_LOCAL}/pkg-plist

.include "${MASTERDIR}/Makefile"
