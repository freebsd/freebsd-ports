# New ports collection makefile for:	qmail-tls
# Date created:				03 Dec 2000
# Whom:					Mario S F Ferreira <lioux@linf.unb.br> et al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION= 	${QMAIL_VERSION}.${TLS_PATCH_DATE}
CATEGORIES=	mail
PKGNAMESUFFIX=	-tls

PATCH_SITES+=	http://www.esat.kuleuven.ac.be/~vermeule/qmail/
PATCHFILES+=	tls.patch
PATCH_DIST_STRIP+=	-p1

MAINTAINER=	lioux@FreeBSD.org

USE_OPENSSL=	YES

TLS_PATCH_DATE=	20000823

.if !defined(PRE_MK_INCLUDED)
.include <bsd.port.pre.mk>
.endif

MAKE_ARGS+=     TLS=yes

.if defined(WITH_TLS_DEBUG)
MAKE_ARGS+=	DEBUG=yes
.endif # WITH_TLS_DEBUG

#PREFIX=		/var/qmail-tls

DOCFILES+=	${WRKDIR}/TLS.readme

yetanotherone-pre-fetch: tls-pre-fetch

tls-pre-fetch:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build options:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_TLS_DEBUG=yes	enable additional debug information"
	@${ECHO_MSG} ""

yetanotherone-post-patch: tls-post-patch

tls-post-patch:
	@${HEAD} -74 ${DISTDIR}/tls.patch > ${WRKDIR}/TLS.readme
	@${PERL} -pi -ne "s|/var/qmail|${PREFIX}|;s|/usr/local/ssl|${OPENSSLBASE}|" ${WRKSRC}/Makefile

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
MASTERDIR=	${PORTSDIR}/mail/qmail
#MASTERDIR=	${.CURDIR}/../qmail
PKGDIR_LOCAL=	${.CURDIR}
COMMENT=	${PKGDIR_LOCAL}/pkg-comment
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message
PLIST=		${PKGDIR_LOCAL}/pkg-plist

.include "${MASTERDIR}/Makefile"
