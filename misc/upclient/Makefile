# New ports collection makefile for:	upclient
# Date created:		20 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	upclient
PORTVERSION=	4.2.1.23
CATEGORIES=	misc
MASTER_SITES=	http://uptimes.atomicvoid.net/files/

MAINTAINER=	cyrille.lefevre@laposte.net

# Global variables
#

ALL_TARGET=	bsd
BUILD_WRKSRC=	${WRKSRC}/src

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# Local variables
#

DOC_FILES=	AUTHORS COPYING FAQ HISTORY INSTALL README TODO

.include <bsd.port.pre.mk>

# Post-patch
#

post-patch: patch-script patch-message

patch-script:
	@${PERL} -pi.fbsd -e 's.%%PREFIX%%.${PREFIX}.g' ${WRKSRC}/scripts/upchk

patch-message:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Install
#

do-install: install-program install-sample install-script

install-program:
	@${INSTALL_PROGRAM} -g kmem -m 2555 ${WRKSRC}/src/upclient \
		${PREFIX}/sbin/upclient

install-sample:
	@${INSTALL_DATA} -m 600 ${WRKSRC}/conf/upclient.conf \
		${PREFIX}/etc/upclient.conf.sample

install-script:
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/upchk ${PREFIX}/sbin/upchk

# Post-install
#

post-install: install-conf install-startup install-doc display-message

install-conf:
.if !exists(${PREFIX}/etc/upclient.conf)
	@${CP} -p ${PREFIX}/etc/upclient.conf.sample \
		${PREFIX}/etc/upclient.conf
.endif

install-startup:
	@${INSTALL_SCRIPT} ${FILESDIR}/upclient.sh \
		${PREFIX}/etc/rc.d/upclient.sh

install-doc:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
