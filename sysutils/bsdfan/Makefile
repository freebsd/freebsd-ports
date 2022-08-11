PORTNAME=	bsdfan
PORTVERSION=	g20180112
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility to manage fans on Lenovo ThinkPad laptops

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=	requires acpi_ibm(4) which is only available on x86

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	claudiozz
GH_TAGNAME=	d8428a7

PLIST_FILES=	bin/bsdfan man/man1/bsdfan.1.gz \
		@sample\ etc/bsdfan.conf.sample

post-install:
	${INSTALL_DATA} ${WRKSRC}/bsdfan.conf \
		${STAGEDIR}${PREFIX}/etc/bsdfan.conf.sample

.include <bsd.port.mk>
