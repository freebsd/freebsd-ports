# New ports collection makefile for:    milter-sender
# Date created:                         7 Sep 2003
# Whom:                                 Andrey Chernov
#
# $FreeBSD$
#

PORTNAME=       milter-sender
PORTVERSION=    0.45
CATEGORIES=     mail
MASTER_SITES=   http://www.snert.com/Software/download/
DISTFILES=      libsnert-1.27.tgz milter-sender-${PORTVERSION}.tgz

MAINTAINER=     ache@FreeBSD.org
COMMENT=        Real-time sender address verification, based on Milter API

RESTRICTED=     see LICENSE.TXT

GNU_CONFIGURE=  yes

WRKSRC=         ${WRKDIR}/com/snert/src/milter-sender
MAKEFILE=       makefile

.include <bsd.port.pre.mk>

.if !exists(/usr/lib/libmilter.a) && !exists(${LOCALBASE}/lib/libmilter.a)
IGNORE=         requires Sendmail 8.12
.endif
.if exists(${LOCALBASE}/lib/libmilter.a)
CFLAGS+=       -I${LOCALBASE}/include
LDFLAGS+=      -L${LOCALBASE}/lib
.endif

DOCS= CHANGES.TXT index.shtml style.css mailto.js \
      license-body.html LICENSE.TXT milter-sender.mc responses.txt

CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CFLAGS+= ${PTHREAD_CFLAGS}
CONFIGURE_ENV+=  LDFLAGS="${LDFLAGS}" LIBS="${PTHREAD_LIBS}"
CONFIGURE_ARGS+= --with-db --localstatedir=/var
MAKE_ENV+=       PREFIX="${PREFIX}"

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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/Img
	cd ${WRKSRC} && ${INSTALL_DATA} ${DOCS} ${DOCSDIR}
	@cd ${WRKSRC}/Img && \
	${INSTALL_DATA} *.gif *.png ${DOCSDIR}/Img
.endif
	@if [ ! -f ${PREFIX}/etc/rc.d/milter-sender.sh ] ; then \
	${CP} ${PREFIX}/etc/rc.d/milter-sender.sh-dist ${PREFIX}/etc/rc.d/milter-sender.sh; \
	${CHMOD} ug+x ${PREFIX}/etc/rc.d/milter-sender.sh; \
	fi
	@${CAT} ${PKGMESSAGE}

post-deinstall:
	@if [ -f ${PREFIX}/etc/rc.d/milter-sender.sh ] && \
	cmp -s ${PREFIX}/etc/rc.d/milter-sender.sh ${PREFIX}/etc/rc.d/milter-sender.sh-dist; then \
	${RM} -f ${PREFIX}/etc/rc.d/milter-sender.sh; \
	fi
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Do not forget to delete the filter description from /etc/mail/YOUR-CONF.mc"
	@${ECHO_MSG} "and rebuild sendmail.cf file!"
	@${ECHO_MSG} ""

.include <bsd.port.post.mk>
