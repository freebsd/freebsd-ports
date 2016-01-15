# Created by: shipley@dis.org
# $FreeBSD$

PORTNAME=	hello
PORTVERSION=	2.10
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

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
NLS_CPPFLAGS=		-I${LOCALBASE}/include
NLS_LDFLAGS=		-L${LOCALBASE}/lib

.include <bsd.port.mk>
