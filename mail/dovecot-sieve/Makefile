# New ports collection makefile for:	dovecot-sieve
# Date created:		2006-12-29
# Whom:			Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot-sieve
PORTVERSION=	1.0.1
CATEGORIES=	mail
MASTER_SITES=	http://www.dovecot.org/releases/sieve/ \
		http://www.is-root.com/myports/

MAINTAINER=	nivo+kw+ports.bfa274@is-root.com
COMMENT=	A sieve plugin for the Dovecot LDA called 'deliver'

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build

USE_LDCONFIG=	${PREFIX}/lib/dovecot/lda

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-dovecot=`make -C ${PORTSDIR}/mail/dovecot -V WRKSRC`

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not compile on 4.x
.endif

.include <bsd.port.post.mk>
