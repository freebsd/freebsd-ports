# Created by: Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
# $FreeBSD$

PORTNAME=	wdiff
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Display word differences between text files

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix makeinfo
GNU_CONFIGURE=	yes

INFO=		wdiff

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_CONFIGURE_ENABLE=	nls
NLS_CFLAGS=		-isystem${LOCALBASE}/include
NLS_USES=		gettext

.include <bsd.port.mk>
