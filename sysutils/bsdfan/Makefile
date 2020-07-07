# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bsdfan
PORTVERSION=	g20180112
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Utility to manage fans on Lenovo ThinkPad laptops

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

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
