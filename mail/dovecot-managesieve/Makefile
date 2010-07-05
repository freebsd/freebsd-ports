# New ports collection makefile for:	dovecot-managesieve
# Date created:		2008-07-05
# Whom:			Geoffroy Desvernay <dgeo@ec-marseille.fr>
#
# $FreeBSD$
#

PORTNAME=	dovecot-managesieve
PORTVERSION=	0.11.11
PORTREVISION=	2
CATEGORIES=	mail
MASTER_SITES=	http://www.rename-it.nl/dovecot/${DOVECOTVERSION}/
DISTNAME=	${PORTNAME:C/-/-${DOVECOTVERSION}-/}-${DISTVERSIONPREFIX}${DISTVERSION:C/:(.)/\1/g}${DISTVERSIONSUFFIX}

MAINTAINER=	dgeo@ec-marseille.fr
COMMENT=	Dovecot ManageSieve Server daemon

BUILD_DEPENDS=	${NONEXISTENT}:${PORTSDIR}/mail/dovecot:build \
		${NONEXISTENT}:${PORTSDIR}/mail/dovecot-sieve:build
RUN_DEPENDS=	dovecot>=${DOVECOTVERSION}.*:${PORTSDIR}/mail/dovecot \
		dovecot-sieve>=${DOVECOTVERSION}:${PORTSDIR}/mail/dovecot-sieve

DOVECOTVERSION=	1.2

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-dovecot=`${MAKE} -C ${PORTSDIR}/mail/dovecot -V WRKSRC` \
		--with-dovecot-sieve=`${MAKE} -C ${PORTSDIR}/mail/dovecot-sieve -V WRKSRC`

.include <bsd.port.mk>
