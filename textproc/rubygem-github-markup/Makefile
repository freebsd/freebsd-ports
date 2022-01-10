PORTNAME=	github-markup
PORTVERSION=	4.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Render any fancy markup

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem shebangfix
USE_RUBY=	yes

CONFLICTS_INSTALL=	rubygem-github-markup*

NO_ARCH=	yes
REINPLACE_ARGS=	-i ''

PLIST_FILES=	bin/github-markup

SHEBANG_FILES=	script/*

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/lib/github/commands/rest2html

.include <bsd.port.mk>
