# $FreeBSD$

PORTNAME=	ndmpd
PORTVERSION=	1.1
CATEGORIES=	sysutils

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Network Data Management Protocol daemon

LICENSE=	BSD3CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	araujobsd
GH_PROJECT=	ndmpd
GH_TAGNAME=	daa00f9 

ONLY_FOR_ARCHS=	amd64 i386
PLIST_FILES=	sbin/ndmpd etc/ndmpd.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ndmpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ndmpd.conf ${STAGEDIR}${PREFIX}/etc/ndmpd.conf.example

.include <bsd.port.mk>
