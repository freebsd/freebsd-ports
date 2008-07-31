# New ports collection makefile for:	dovecot-sieve
# Date created:		2006-12-29
# Whom:			Nils Vogels <nivo+kw+ports.bfa274@is-root.com>
#
# $FreeBSD$
#

PORTNAME=	dovecot-sieve
PORTVERSION=	1.1.5
CATEGORIES=	mail
MASTER_SITES=	http://www.dovecot.org/releases/sieve/ \
		http://www.is-root.com/myports/

MAINTAINER=	yds@coolrat.org
COMMENT=	A sieve plugin for the Dovecot LDA called 'deliver'

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build

USE_LDCONFIG=	${PREFIX}/lib/dovecot/lda

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-dovecot=`make -C ${PORTSDIR}/mail/dovecot -V WRKSRC`

.include <bsd.port.mk>
