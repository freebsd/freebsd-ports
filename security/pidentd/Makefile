# New ports collection makefile for:	pidentd
# Date created:		19 Oct 1994
# Whom:			torstenb
#
# $FreeBSD$
#

PORTNAME=	pidentd
PORTVERSION=	2.8.5
CATEGORIES=	security ipv6
MASTER_SITES=	ftp://ftp.lysator.liu.se/pub/ident/servers/ \
		ftp://ftp.fu-berlin.de/unix/security/ident/servers/

PATCH_SITES=	http://www.imasy.or.jp/~ume/ipv6/
PATCHFILES=	pidentd-2.8.5-ipv6-1.5.diff.gz
PATCH_DIST_STRIP=	-p2

MAINTAINER=	ports@FreeBSD.org

ALL_TARGET=	freebsd
MAKE_ENV=	REALPREFIX=${PREFIX}
MAN8=		identd.8 idecrypt.8

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 400014
ADD_GDEFS+=	-DINET6 -D__ss_family=ss_family -D__ss_len=ss_len
.endif

# Uncomment to activate the use of verifiable "cookies".  The idea is to be
# able to detect fake "logs" intended to get your innocent users in trouble.
# Naturally, since it uses libdes, you must have the "secure" dist installed.
#WITH_DES=	yes

.if defined(WITH_DES)
ADD_GDEFS+=	-DINCLUDE_CRYPT
ADD_GLIBS=	-ldes
.endif
.if defined(WITH_DES) || ${OSVERSION} >= 400014
MAKE_ENV+=	ADD_GDEFS="${ADD_GDEFS}" ADD_GLIBS="${ADD_GLIBS}"
.endif

.include <bsd.port.post.mk>
