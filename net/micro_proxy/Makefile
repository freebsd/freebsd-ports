PORTNAME=	micro_proxy
DISTVERSION=	20140814
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://www.acme.com/software/micro_proxy/ \
		LOCAL/ehaupt
DISTNAME=	${PORTNAME}_14Aug2014

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Really small HTTP/HTTPS proxy
WWW=		https://www.acme.com/software/micro_proxy/

LICENSE=	BSD2CLAUSE

SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}
PLIST_FILES=	libexec/micro_proxy \
		share/man/man8/micro_proxy.8.gz

do-build:
	${CC} ${CFLAGS} -c ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}.o
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.o -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/libexec
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.8 ${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
