# Created by: Masaki TAGAWA <masaki@club.kyutech.ac.jp>
# $FreeBSD$

PORTNAME=	http_post
PORTVERSION=	1.0.20110118
CATEGORIES=	www ipv6
MASTER_SITES=	http://www.acme.com/software/http_post/
DISTNAME=	${PORTNAME}_18jan2011

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Do a POST operaion and Dump http-contents to stdout

WRKSRC=		${WRKDIR}/http_post
USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/http_post \
		man/man1/http_post.1.gz

.ifndef NO_OPENSSL
USE_OPENSSL=	yes
.endif

.include <bsd.port.mk>
