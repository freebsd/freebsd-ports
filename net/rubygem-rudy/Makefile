# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rudy
PORTVERSION=	0.9.8.020
PORTREVISION=	1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	swills@FreeBSD.org
COMMENT=	EC2 deployment tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-amazon-ec2>=0.9.10:net/rubygem-amazon-ec2 \
		rubygem-aws-s3>=0.6.1:net/rubygem-aws-s3 \
		rubygem-annoy>=0.5.6:devel/rubygem-annoy \
		rubygem-attic>=0.5.3:devel/rubygem-attic \
		rubygem-caesars>=0.7.4:devel/rubygem-caesars \
		rubygem-drydock>=0.6.9:devel/rubygem-drydock \
		rubygem-highline>=1.5.1:devel/rubygem-highline \
		rubygem-gibbler>=0.8.9:devel/rubygem-gibbler \
		rubygem-rye>=0.9.3:net/rubygem-rye \
		rubygem-storable>=0.8.6:devel/rubygem-storable \
		rubygem-sysinfo>=0.7.3:devel/rubygem-sysinfo

USE_RUBY=	yes
USES=		gem shebangfix
PLIST_FILES=	bin/rudy bin/rudy-ec2 bin/rudy-s3 bin/rudy-sdb
SHEBANG_FILES=	bin/* tryouts/exploration/machine.rb
NO_ARCH=	yes

.include <bsd.port.mk>
