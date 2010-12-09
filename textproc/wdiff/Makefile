# New ports collection makefile for:	wdiff
# Date created:		Sep 15, 1997
# Whom:			Yoshiro MIHIRA <sanpei@yy.cs.keio.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	wdiff
PORTVERSION=	0.6.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	wdiff

MAINTAINER=	sanpei@FreeBSD.org
COMMENT=	Display word differences between text files

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

MAN1=		wdiff.1
INFO=		wdiff

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
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
