# New ports collection makefile for:    milter-sender
# Date created:                         7 Sep 2003
# Whom:                                 Andrey Chernov
#
# $FreeBSD$
#

PORTNAME=       milter-sender
PORTVERSION=    0.36
CATEGORIES=     mail
MASTER_SITES=   http://www.snert.com/Software/download/
DISTFILES=      libsnert-1.18.tgz milter-sender-0.36.tgz
RESTRICTED=     see LICENSE.TXT

MAINTAINER=     ache@FreeBSD.org
COMMENT=        Real-time sender address verification, based on Milter API

DOCDIR=         ${PREFIX}/share/doc/milter-sender
WRKSRC=         ${WRKDIR}/com/snert/src
MAKEFILE=       makefile
ALL_TARGET=     build

.if !exists(/usr/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12; upgrade the base system
.endif

do-build:
	@cd ${WRKSRC}/lib && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f ../mk/FreeBSD.mk \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}
	@cd ${WRKSRC}/milter-sender && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f ../mk/FreeBSD.mk \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

do-install:
	@cd ${WRKSRC}/milter-sender && \
	${SETENV} ${MAKE_ENV} ${MAKE} -f ../mk/FreeBSD.mk \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${INSTALL_TARGET}
	@${INSTALL} -d ${DOCDIR}/Img
	@cd ${WRKSRC}/milter-sender && \
	${INSTALL_DATA} CHANGES.TXT index.shtml style.css mailto.js \
	license-body.html LICENSE.TXT milter-sender.mc ${DOCDIR}
	@cd ${WRKSRC}/milter-sender/Img && \
	${INSTALL_DATA} *.gif *.png ${DOCDIR}/Img

EXTRA_CFLAGS=   ${PTHREAD_CFLAGS}
LDFLAGS=	${PTHREAD_LIBS}
MAKE_ENV=       EXTRA_CFLAGS="${EXTRA_CFLAGS}" \
		LDFLAGS="${LDFLAGS}" \
		WRKDIR="${WRKDIR}"

post-install:
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Do not forget delete filter description from /etc/mail/YOUR-CONF.mc"
	@${ECHO_MSG} "and rebuild sendmail.cf file!"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
