PORTNAME=	kamal
PORTVERSION=	2.7.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Deploy web apps in containers to servers running Docker with zero downtime
WWW=		https://kamal-deploy.org/ \
		https://github.com/basecamp/kamal

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport80>=7.0:devel/rubygem-activesupport80 \
		rubygem-base64>=0.2<1:converters/rubygem-base64 \
		rubygem-bcrypt_pbkdf>=1.0<2:security/rubygem-bcrypt_pbkdf \
		rubygem-concurrent-ruby>=1.2<2:devel/rubygem-concurrent-ruby \
		rubygem-dotenv>=3.1<4:misc/rubygem-dotenv \
		rubygem-ed25519>=1.4<2:security/rubygem-ed25519 \
		rubygem-net-ssh>=7.3,2<8,2:security/rubygem-net-ssh \
		rubygem-sshkit>=1.23.0<2.0:security/rubygem-sshkit \
		rubygem-thor>=1.3<2:devel/rubygem-thor \
		rubygem-zeitwerk>=2.6.18<3.0:devel/rubygem-zeitwerk

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/kamal

.include <bsd.port.mk>
