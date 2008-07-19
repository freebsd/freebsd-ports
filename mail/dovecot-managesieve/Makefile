# New ports collection makefile for:	dovecot-managesieve
# Date created:		2008-07-05
# Whom:			Geoffroy Desvernay <dgeo@ec-marseille.fr>
#
# $FreeBSD$
#

PORTNAME=	dovecot-1.1-managesieve
PORTVERSION=	0.10.3
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/1.1/

MAINTAINER=	dgeo@ec-marseille.fr
COMMENT=	Managesieve package

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build \
		${NONEXISTENT}:${PORTSDIR}/mail/dovecot-sieve:build
RUN_DEPENDS=	${LOCALBASE}/lib/dovecot/lda/lib90_cmusieve_plugin.so:${PORTSDIR}/mail/dovecot-sieve

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-dovecot=`make -C ${PORTSDIR}/mail/dovecot -V WRKSRC` --with-dovecot-sieve=`make -C ${PORTSDIR}/mail/dovecot-sieve -V WRKSRC`

.include <bsd.port.mk>
