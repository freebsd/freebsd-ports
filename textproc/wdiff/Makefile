# Created by: Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
# $FreeBSD$

PORTNAME=	wdiff
PORTVERSION=	1.2.1
CATEGORIES=	textproc
MASTER_SITES=	GNU

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Display word differences between text files

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

MAN1=		wdiff.1
INFO=		wdiff

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
CFLAGS+=	-I${LOCALBASE}/include
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "

post-patch:	.SILENT
	${REINPLACE_CMD} '/^install-exec-local:/s/install-exec-localcharset//' \
		${WRKSRC}/lib/Makefile.in
.endif

.include <bsd.port.mk>
