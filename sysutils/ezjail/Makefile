PORTNAME=	ezjail
PORTVERSION=	3.4.2
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://erdgeist.org/arts/software/ezjail/

MAINTAINER=	erdgeist@erdgeist.org
COMMENT=	Framework to easily create, manipulate, and run FreeBSD jails
WWW=		https://erdgeist.org/arts/software/ezjail/

USES=		tar:bzip2

post-patch:
	@${REINPLACE_CMD} -e 's|man/man|share/man/man|g' \
		${WRKSRC}/Makefile

.include <bsd.port.mk>
