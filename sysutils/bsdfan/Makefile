PORTNAME=	bsdfan
PORTVERSION=	g20180112
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility to manage fans on Lenovo ThinkPad laptops
WWW=		https://github.com/claudiozz/bsdfan

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	requires acpi_ibm(4) which is only available on x86

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	claudiozz
GH_TAGNAME=	d8428a7
MAKE_ARGS=	BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/share/man/man
USE_RC_SUBR=	${PORTNAME}

PLIST_FILES=	bin/bsdfan share/man/man1/bsdfan.1.gz \
		@sample\ etc/bsdfan.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/bsdfan.conf \
		${STAGEDIR}${PREFIX}/etc/bsdfan.conf.sample

.include <bsd.port.mk>
