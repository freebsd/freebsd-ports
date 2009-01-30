# New ports collection makefile for:	dovecot-sieve
# Date created:		2006-12-29
# Whom:			Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot-sieve
PORTVERSION=	1.1.6
CATEGORIES=	mail
MASTER_SITES=	http://www.dovecot.org/releases/sieve/ \
		http://www.is-root.com/myports/

MAINTAINER=	yds@CoolRat.org
COMMENT=	A Sieve plugin for the Dovecot 'deliver' LDA

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build
RUN_DEPENDS=	dovecot>=1.1.*:${PORTSDIR}/mail/dovecot

USE_LDCONFIG=	${PREFIX}/lib/dovecot/lda

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-dovecot=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC`
SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING COPYING.LGPL INSTALL NEWS README \
		AUTHORS.CMU COPYING.CMU NEWS.CMU README.CMU
.endif

post-extract:
	@${LN} -f ${WRKSRC}/src/libsieve/AUTHORS	${WRKSRC}/AUTHORS.CMU
	@${LN} -f ${WRKSRC}/src/libsieve/COPYING	${WRKSRC}/COPYING.CMU
	@${LN} -f ${WRKSRC}/src/libsieve/NEWS		${WRKSRC}/NEWS.CMU
	@${LN} -f ${WRKSRC}/src/libsieve/README		${WRKSRC}/README.CMU

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} ${_SHROWNGRP} -m ${BINMODE} -d ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
 
.include <bsd.port.mk>
