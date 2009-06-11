# New ports collection makefile for:	fressh
# Date created:				25 July 2000
# Whom:					Alistair G. Crooks <agc@netbsd.org>
#
# $FreeBSD$
#

PORTNAME=	fressh
PORTVERSION=	0.8.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://freebsd.unixfreunde.de/sources/ \
		http://mirror2.unixfreunde.de/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A free rewritten implementation of the SSH communication protocol

USE_BZIP2=	yes

PLIST_FILES=	bin/fressh bin/fressh-add bin/fressh-agent \
		bin/fressh-keygen sbin/fresshd

post-patch:
	@${REINPLACE_CMD} -e '117s,^static ,,' ${WRKSRC}/sshd_main.c

.if !exists(/usr/lib/libssl.a) || !exists(/usr/lib/libcrypto.a)
.if exists(${LOCALBASE}/lib/libssl.a) && exists(${LOCALBASE}/lib/libcrypto.a)
LIB_DEPENDS+=	ssl.3:${PORTSDIR}/security/openssl
MAKE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		RSAGLUE="${RSAGLUE}"
.if exists(${LOCALBASE}/lib/librsaref.a)
RSAGLUE=	-lrsaref
.endif
RSAGLUE+=	-lRSAglue
.endif
.endif

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800065
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
