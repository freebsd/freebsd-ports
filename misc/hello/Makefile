# Created by: shipley@dis.org

PORTNAME=	hello
PORTVERSION=	2.11
CATEGORIES=	misc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Utility for saying hello to the world and reading email

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix gmake perl5
USE_PERL5=	build
GNU_CONFIGURE=	yes

INFO=		hello

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext localbase
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
