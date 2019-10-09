# Created by: Aaron Zauner <az_mail@gmx.at>
# $FreeBSD$

PORTNAME=	http_get
PORTVERSION=	1.0.20140814
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_get/
DISTNAME=	${PORTNAME}_14Aug2014

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Dump http-contents to stdout

WRKSRC=		${WRKDIR}/http_get
USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/http_get \
		man/man1/http_get.1.gz

.ifndef NO_OPENSSL
USES+=	ssl
.endif

.include <bsd.port.mk>
