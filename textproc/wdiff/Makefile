# Created by: Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
# $FreeBSD$

PORTNAME=	wdiff
PORTVERSION=	1.2.2
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Display word differences between text files

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

USES=		charsetfix

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
