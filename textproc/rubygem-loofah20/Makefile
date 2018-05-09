# $FreeBSD$

PORTNAME=	loofah
PORTVERSION=	2.0.3
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Library for manipulating HTML/XML documents and fragments

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE.txt

DEPRECATED=	Obsoleted by update of www/gitlab. Please use textproc/rubygem-loofah instead.
EXPIRATION_DATE=	2018-05-31

RUN_DEPENDS=	rubygem-nokogiri>=1.5.9:textproc/rubygem-nokogiri

PORTSCOUT=	limit:^2\.0

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
