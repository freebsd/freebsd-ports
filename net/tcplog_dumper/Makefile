# $FreeBSD$

PORTNAME=	tcplog_dumper
PORTVERSION=	0.1.0
DISTVERSIONPREFIX=	v
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Dump data from the tcp_log device

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64

USE_GITHUB=	yes
GH_ACCOUNT=	Netflix

PLIST_FILES=	sbin/tcplog_dumper \
		man/man1/tcplog_dumper.1.gz

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1300076
IGNORE=	builds only on FreeBSD 13-head with minimum revision 356414
.endif

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcplog_dumper ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcplog_dumper.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
