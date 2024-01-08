PORTNAME=	choparp
DISTVERSIONPREFIX=	release/
DISTVERSION=	20150613
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	garga@FreeBSD.org
COMMENT=	Simple proxy arp daemon
WWW=		https://github.com/quinot/choparp

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	quinot
USE_RC_SUBR=	choparp
LDFLAGS+=	-lpcap

PLIST_FILES=	sbin/choparp share/man/man8/choparp.8.gz

do-build:
	( cd ${WRKSRC}/src && \
		${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c )

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} \
		${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/src/${PORTNAME}.8 \
		${STAGEDIR}${PREFIX}/share/man/man8

.include <bsd.port.mk>
