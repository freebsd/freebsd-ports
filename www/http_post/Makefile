PORTNAME=	http_post
PORTVERSION=	1.0.20140814
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.acme.com/software/http_post/
DISTNAME=	${PORTNAME}_14Aug2014

MAINTAINER=	masaki@club.kyutech.ac.jp
COMMENT=	Do a POST operation and dump http-contents to stdout
WWW=		https://www.acme.com/software/http_post/

WRKSRC=		${WRKDIR}/http_post
USES=		uidfix
MAKEFILE=	${FILESDIR}/Makefile.bsd

PLIST_FILES=	bin/http_post \
		share/man/man1/http_post.1.gz

.ifndef NO_OPENSSL
USES+=	ssl
.endif

.include <bsd.port.mk>
