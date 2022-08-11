PORTNAME=	hello
PORTVERSION=	2.12.1
CATEGORIES=	misc
MASTER_SITES=	GNU

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Utility for saying hello to the world and reading email

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes

INFO=		hello

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_USES=		gettext localbase

.include <bsd.port.mk>
