# New ports collection makefile for:	upclient
# Date created:		20 Aug 1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

PORTNAME=	upclient
PORTVERSION=	5.0.b8
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://uptimes.hostingwired.com/files/ \
		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-${PORTVERSION:R}${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Uptimes project client

# Global variables
#

USE_GETTEXT=	yes
USE_RC_SUBR=	yes
ALL_TARGET=	bsd
BUILD_WRKSRC=	${WRKSRC}/src

SUB_FILES=	pkg-message  upclient.sh
PKGMESSAGE=	${WRKDIR}/pkg-message upclient.sh

MAN8=		upclient.8

# Local variables
#

REINPLACE_SUB=	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE}

DOC_FILES=	AUTHORS COPYING FAQ HISTORY INSTALL README TODO
DOC_FILES+=	doc/UptimesProtocol5
DOC_FILES+=	HISTORY-BETA

.include <bsd.port.pre.mk>

# Post-extract
#

post-extract: rename-doc

rename-doc:
	@${MV} ${WRKSRC}/doc/"Uptimes Protocol 5" ${WRKSRC}/doc/UptimesProtocol5

# Post-patch
#

post-patch:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/clientchk \
		${WRKSRC}/src/Makefile

# Install
#

do-install: install-program install-man install-sample install-script \
	install-locale

install-program:
	@${INSTALL_PROGRAM} -g kmem -m 2555 ${WRKSRC}/src/products/upclient \
		${PREFIX}/sbin

install-man:
	@${INSTALL_MAN} ${WRKSRC}/src/products/upclient.8 \
		${MAN8PREFIX}/man/man8

install-sample:
	@${INSTALL_DATA} -g kmem -m 640 ${WRKSRC}/src/products/upclient.conf \
		${PREFIX}/etc/upclient.conf.sample

install-script:
	@${INSTALL_SCRIPT} ${WRKSRC}/scripts/upchk ${WRKSRC}/scripts/clientchk \
		${PREFIX}/sbin

install-locale:
	@cd ${WRKSRC}/src; ${MAKE} install-locales

# Post-install
#

post-install: install-conf install-startup install-doc display-message

install-conf:
.if !exists(${PREFIX}/etc/upclient.conf)
	@${CP} -p ${PREFIX}/etc/upclient.conf.sample \
		${PREFIX}/etc/upclient.conf
.endif

install-startup:
	@${INSTALL_SCRIPT} ${WRKDIR}/upclient.sh \
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
