# $FreeBSD$

PORTNAME=	github-markup
PORTVERSION=	1.6.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	16

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Render any fancy markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	textproc/rubygem-github-markup

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

REINPLACE_ARGS=	-i ''

PLIST_FILES=	bin/github-markup

SHEBANG_FILES=	script/bootstrap \
		script/cibuild

PORTSCOUT=	limit:^1\.6\.

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/lib/github/commands/rest2html

.include <bsd.port.mk>
