# New ports collection makefile for:	qmail-smtp_auth+tls
# Date created:				03 Dec 2000
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org> et. al.
#
# $FreeBSD$
#

PORTNAME=	qmail
PORTVERSION=	${QMAIL_VERSION}.${SMTP_AUTH-TLS_PATCH_DATE}
CATEGORIES=	mail
PKGNAMESUFFIX=	-smtp_auth+tls

PATCH_SITES+=	http://students.imsa.edu/~ngroot/:smtp_auth_tls
PATCHFILES+=	qmail-1.03-starttls-smtp-auth.patch:smtp_auth_tls

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A SECURE, reliable, and FAST MTA for UNIX systems WITH SMTP_AUTH+TLS

# not type-safe
ONLY_FOR_ARCHS=	i386

USE_OPENSSL=	YES

# Patches from the main qmail port are not wanted
MAIN_QMAIL_PORT_WITH_OUTGOINGIP_PATCH_BARRIER=	yes

SMTP_AUTH-TLS_PATCH_DATE=	20020519

# Using default from master port, i.e., /var/qmail
PREFIX?=	${QMAIL_PORT_PREFIX}
#PREFIX=		/var/qmail-smtp_auth+tls

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

DOCFILES+=	${WRKDIR}/SMTP_AUTH+TLS.readme \
		${WRKSRC}/README.auth

slaveport-pre-fetch: qmail-smtp_auth+tls-pre-fetch

qmail-smtp_auth+tls-pre-fetch:
	@${ECHO_MSG} "WITH_TLS_DEBUG=yes		enable additional debug information"

slaveport-post-patch: qmail-smtp_auth+tls-post-patch

qmail-smtp_auth+tls-post-patch:
	@${HEAD} -6 ${DISTDIR}/qmail-1.03-starttls-smtp-auth.patch \
		| ${TAIL} -5 \
		> ${WRKDIR}/SMTP_AUTH+TLS.readme
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
			-out ${WRKDIR}/servercert.pem -days 366 \
			-keyout ${WRKDIR}/servercert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/servercert.pem ${PREFIX}/control/servercert.pem ; \
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
			-keyout ${WRKDIR}/servercert.pem ; \
		${INSTALL} -o qmaild -g qmail -m 0640 ${WRKDIR}/servercert.pem ${PREFIX}/control/servercert.pem ; \
		${ECHO_MSG} ; \
		${ECHO_MSG} "===> Do not forget to do 'make clean' to clean up temporary files" ; \
		${ECHO_MSG} "===> Send ${WRKDIR}/req.pem to your CA to obtain signed_req.pem, and do:" ; \
		${ECHO_MSG} "===> cat signed_req.pem >> ${PREFIX}/control/servercert.pem" ; \
	else \
		${ECHO_MSG} "===> You must create the file ${OPENSSLDIR}/openssl.cnf first." ; \
	fi

# Local overrides
MASTERDIR=	${QMAIL_PORT}
PKGDIR_LOCAL=	${.CURDIR}
DESCR=		${PKGDIR_LOCAL}/pkg-descr
PKGMESSAGE=	${PKGDIR_LOCAL}/pkg-message
PLIST=		${PKGDIR_LOCAL}/pkg-plist

.include "${MASTERDIR}/Makefile"
