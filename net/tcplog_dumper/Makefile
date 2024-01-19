PORTNAME=	tcplog_dumper
PORTVERSION=	0.1.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Dump data from the tcp_log device
WWW=		https://github.com/Netflix/tcplog_dumper

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 mips64 mips64el mips64elhf mips64hf powerpc64 powerpc64le riscv64 riscv64sf
ONLY_FOR_ARCHS_REASON=	only 64-bit platforms are supported

USE_GITHUB=	yes
GH_ACCOUNT=	Netflix

USE_RC_SUBR=	tcplog_dumper

PLIST_FILES=	sbin/tcplog_dumper \
		man/man1/tcplog_dumper.1.gz

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_PROGRAM} ${WRKSRC}/tcplog_dumper ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/tcplog_dumper.1.gz ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
