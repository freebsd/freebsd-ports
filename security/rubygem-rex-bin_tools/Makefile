# $FreeBSD$

PORTNAME=	rex-bin_tools
PORTVERSION=	0.1.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Ruby Exploitation(Rex) Library for Binary Manipulation

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	nasm>=0:devel/nasm \
		rubygem-metasm>=0:devel/rubygem-metasm \
		rubygem-rex-arch>=0:security/rubygem-rex-arch \
		rubygem-rex-core>=0:security/rubygem-rex-core \
		rubygem-rex-struct2>=0:security/rubygem-rex-struct2 \
		rubygem-rex-text>=0:security/rubygem-rex-text

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/msfbinscan \
		bin/msfelfscan \
		bin/msfmachscan \
		bin/msfpescan

.include <bsd.port.mk>
