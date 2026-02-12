PORTNAME=	try-rs
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
CATEGORIES=	sysutils

MAINTAINER=	adamw@FreeBSD.org
COMMENT=	Workspace manager for your temporary experiments
WWW=		https://try-rs.org

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	git-tiny>=0:devel/git@tiny

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	tassiovirginio

PLIST_FILES=	bin/try-rs

.include <bsd.port.mk>
