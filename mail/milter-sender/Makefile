# New ports collection makefile for:    milter-sender
# Date created:                         7 Sep 2003
# Whom:                                 Andrey Chernov
#
# $FreeBSD$
#

PORTNAME=       milter-sender
PORTVERSION=    0.38
CATEGORIES=     mail
MASTER_SITES=   http://www.snert.com/Software/download/
DISTFILES=      libsnert-1.20.tgz milter-sender-0.38.tgz
RESTRICTED=     see LICENSE.TXT

MAINTAINER=     ache@FreeBSD.org
COMMENT=        Real-time sender address verification, based on Milter API

DOCDIR=         ${PREFIX}/share/doc/milter-sender
WRKSRC=         ${WRKDIR}/com/snert/src/milter-sender
MAKEFILE=       makefile
GNU_CONFIGURE=  yes

.if !exists(/usr/lib/libmilter.a)
IGNORE=		requires Sendmail 8.12; upgrade the base system
.endif

CFLAGS+= ${PTHREAD_CFLAGS}
CONFIGURE_ENV=  LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS= --localstatedir=${PREFIX} --with-db
MAKE_ENV=       PREFIX="${PREFIX}"

pre-configure:
	@cd ${WRKSRC}/../lib && \
	${SETENV} CC="${CC}" CXX="${CXX}" \
	CFLAGS="${CFLAGS}" CXXFLAGS="${CXXFLAGS}" \
	INSTALL="/usr/bin/install -c ${_BINOWNGRP}" \
	INSTALL_DATA="${INSTALL_DATA}" \
	INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
	${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS}
	@cd ${WRKSRC}/../lib && \
	${SETENV} ${MAKE_ENV} ${MAKE} \
	${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} ${ALL_TARGET}

post-install:
	@${INSTALL} -d ${DOCDIR}/Img
	@cd ${WRKSRC} && \
	${INSTALL_DATA} CHANGES.TXT index.shtml style.css mailto.js \
	license-body.html LICENSE.TXT milter-sender.mc responses.txt \
	${DOCDIR}
	@cd ${WRKSRC}/Img && \
	${INSTALL_DATA} *.gif *.png ${DOCDIR}/Img
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Do not forget delete filter description from /etc/mail/YOUR-CONF.mc"
	@${ECHO_MSG} "and rebuild sendmail.cf file!"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
