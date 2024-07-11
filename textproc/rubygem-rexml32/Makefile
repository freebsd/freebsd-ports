PORTNAME=	rexml
PORTVERSION=	3.2.9
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	32

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	XML toolkit for Ruby
WWW=		https://github.com/ruby/rexml

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-strscan>=0:devel/rubygem-strscan

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	ruby-lang

PORTSCOUT=	limit:^3\.2\.

.include <bsd.port.mk>
