# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	activestorage
PORTVERSION=	6.1.3.2
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Attach cloud and local files in Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack613>=${PORTVERSION}:www/rubygem-actionpack613 \
		rubygem-activejob613>=${PORTVERSION}:devel/rubygem-activejob613 \
		rubygem-activerecord613>=${PORTVERSION}:databases/rubygem-activerecord613 \
		rubygem-activesupport613>=${PORTVERSION}:devel/rubygem-activesupport613 \
		rubygem-marcel>=1.0.0<1.1:devel/rubygem-marcel \
		rubygem-mini_mime>=1.1.0:mail/rubygem-mini_mime

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^6\.1\.

.include <bsd.port.mk>
