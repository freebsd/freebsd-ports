# $FreeBSD$

PORTNAME=	premailer-rails
PORTVERSION=	1.9.7
CATEGORIES=	mail rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	19-rails50

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Improve the rendering of HTML emails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionmailer50>=3:mail/rubygem-actionmailer50 \
		rubygem-premailer>=1.7.9:mail/rubygem-premailer

PORTSCOUT=	limit=^1\.9

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
