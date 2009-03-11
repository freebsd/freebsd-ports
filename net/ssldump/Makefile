# New ports collection makefile for:	ssldump
# Date created:				10 November 2000
# Whom:					Kris Kennaway <kris@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ssldump
PORTVERSION=	0.9b3
PORTREVISION=	4
CATEGORIES=	net security
MASTER_SITES=	http://www.rtfm.com/ssldump/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	SSLv3/TLS network protocol analyzer

USE_OPENSSL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl=${OPENSSLBASE} \
		--sbindir=${PREFIX}/bin

OPTIONS=	AES "Enable AES support from CVS (EXPERIMENTAL)" off

MAN1=		ssldump.1
PLIST_FILES=	bin/ssldump

.include <bsd.port.pre.mk>

.if defined(WITH_AES)
EXTRA_PATCHES+=	${FILESDIR}/extra-patch-aes
.endif

.include <bsd.port.post.mk>
