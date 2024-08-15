PORTNAME?=	zed
DISTVERSIONPREFIX=	v
DISTVERSION=	1.17.0
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	meta@FreeBSD.org
COMMENT=	Command-line tool to manage and query Zed data lakes
WWW=		https://zed.brimdata.io/

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BROKEN_i386=	fails to build: cannot use math.MaxUint32 (untyped int constant 4294967295) as int value in assignment (overflows)

USES=		go:modules,1.21

GO_MODULE?=	github.com/brimdata/zed
GO_PKGNAME?=	github.com/brimdata/zed/cmd/zed

PLIST_FILES?=	bin/zed

.include <bsd.port.pre.mk>

.if ${SLAVE_PORT} == no

x-maintainer-makesum:
	${MAKE} DISTINFO_FILE=${.CURDIR}/distinfo.zed makesum
	${MAKE} DISTINFO_FILE=${.CURDIR}/distinfo.zq -C "${.CURDIR}/../zq" makesum

	${CAT} ${.CURDIR}/distinfo.zed ${.CURDIR}/distinfo.zq | \
		${AWK} '$$1 != "TIMESTAMP" || NR == 1' > ${.CURDIR}/distinfo
	${RM} ${.CURDIR}/distinfo.zed ${.CURDIR}/distinfo.zq

.endif

.include <bsd.port.post.mk>
