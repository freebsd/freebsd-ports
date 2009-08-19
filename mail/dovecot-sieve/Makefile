# New ports collection makefile for:	dovecot-sieve
# Date created:		2006-12-29
# Whom:			Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot-sieve
PORTVERSION=	${DOVECOTVERSION}+${DISTVERSION}
DISTVERSION=	0.1.11
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${DISTVERSIONPREFIX}${DISTVERSION:C/:(.)/\1/g}${DISTVERSIONSUFFIX}

MAINTAINER=	yds@CoolRat.org
COMMENT=	A Sieve plugin for the Dovecot 'deliver' LDA

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build
RUN_DEPENDS=	dovecot>=${DOVECOTVERSION}.*:${PORTSDIR}/mail/dovecot

DOVECOTVERSION=	1.2

USE_LDCONFIG=	${PREFIX}/lib/dovecot/lda

MAN1=	sieve-test.1 sievec.1 sieved.1

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-dovecot=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC`
SUB_FILES=	pkg-message

.if !defined(NOPORTDOCS)
PORTDOCS=	AUTHORS COPYING COPYING.LGPL INSTALL NEWS README TODO
.endif

post-install:
.if !defined(NOPORTDOCS)
	${INSTALL} ${_SHROWNGRP} -m ${BINMODE} -d ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}
 
.include <bsd.port.mk>
