# Created by: Jin-Sih Lin <linpct@gmail.com>
# $FreeBSD$

PORTNAME=	rsyncrypto
PORTVERSION=	1.12
PORTREVISION=	2
CATEGORIES=	sysutils net
MASTER_SITES=	SF

MAINTAINER=	linpct@gmail.com
COMMENT=	Rsync Friendly File Encryption

LICENSE=	GPLv2

BUILD_DEPENDS=	${LOCALBASE}/lib/libargtable2.so:devel/argtable
RUN_DEPENDS=	rsync:net/rsync

LDFLAGS+=	-L${LOCALBASE}/lib/
CPPFLAGS+=	-I${LOCALBASE}/include/

GNU_CONFIGURE=	yes
USES=		gmake ssl

PLIST_FILES=	bin/rsyncrypto \
		bin/rsyncrypto_recover \
		man/man1/rsyncrypto.1.gz \
		man/man1/rsyncrypto_recover.1.gz

.include <bsd.port.pre.mk>

.if ${SSL_DEFAULT} == base
BROKEN_FreeBSD_12=	member access into incomplete type 'RSA' (aka 'rsa_st')
BROKEN_FreeBSD_13=	member access into incomplete type 'RSA' (aka 'rsa_st')
.endif

.include <bsd.port.post.mk>
