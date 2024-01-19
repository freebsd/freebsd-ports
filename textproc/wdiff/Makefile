PORTNAME=	wdiff
PORTVERSION=	1.2.2
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Display word differences between text files
WWW=		https://www.gnu.org/software/wdiff/

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix makeinfo
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share

INFO=		wdiff

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_CFLAGS=		-isystem${LOCALBASE}/include
NLS_USES=		gettext

.include <bsd.port.mk>
