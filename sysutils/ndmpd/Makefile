# $FreeBSD$

PORTNAME=	ndmpd
PORTVERSION=	1.0
CATEGORIES=	sysutils
MASTER_SITES=	https://bitbucket.org/araujobsd/ndmp-freebsd/get/

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Network Data Management Protocol daemon

LICENSE=	BSD3CLAUSE

WRKSRC=		${WRKDIR}/araujobsd-ndmp-freebsd-daa00f9dc732

ONLY_FOR_ARCHS=	amd64 i386
PLIST_FILES=	sbin/ndmpd etc/ndmpd.conf.example

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ndmpd ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_DATA} ${WRKSRC}/ndmpd.conf ${STAGEDIR}${PREFIX}/etc/ndmpd.conf.example

.include <bsd.port.mk>
