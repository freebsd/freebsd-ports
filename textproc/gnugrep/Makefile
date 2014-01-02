# Created by: Gabor Kovesdan <gabor@FreeBSD.org>
# $FreeBSD$

PORTNAME=	grep
PORTVERSION=	2.16
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU grep

LICENSE=	GPLv3

CONFLICTS=	bsd-grep-[0-9]*

USES+=		charsetfix
USE_XZ=		yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		grep

OPTIONS_DEFINE=	PCRE NLS
OPTIONS_DEFAULT=PCRE NLS
OPTIONS_SUB=	yes
PCRE_LIB_DEPENDS=	libpcre.so:${PORTSDIR}/devel/pcre
PCRE_CONFIGURE_ENABLE=	perl-regexp
NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.options.mk>

post-patch:
.if empty(PORT_OPTIONS:MNLS)
	@${REINPLACE_CMD} '/install-exec-local:/s/install-exec-localcharset//' \
		${WRKSRC}/lib/Makefile.in
.endif
	@${REINPLACE_CMD} 's|mkinstalldirs = .*|mkinstalldirs = ${MKDIR}|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
