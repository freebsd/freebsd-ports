# New ports collection makefile for:    grep
# Date created:                         5 February 2010
# Whom:                                 Gabor Kovesdan <gabor@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	grep
PORTVERSION=	2.12
CATEGORIES=	textproc
MASTER_SITES=	GNU
PKGNAMEPREFIX=	gnu

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	GNU grep

LICENSE=	GPLv3

CONFLICTS=	bsd-grep-[0-9]*

USE_XZ=		yes
GNU_CONFIGURE=	yes

MAN1=		egrep.1 \
		fgrep.1 \
		grep.1
INFO=		grep

OPTIONS=	PCRE	"Compile with Perl-compatible regex support"	off

.include <bsd.port.options.mk>

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
LDFLAGS+=	-lintl -L${LOCALBASE}/lib
PLIST_SUB+=	NLS=
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITH_PCRE)
LIB_DEPENDS+=	pcre.1:${PORTSDIR}/devel/pcre
.else
CONFIGURE_ARGS+=	--disable-perl-regexp
.endif

post-patch:
.if defined(WITHOUT_NLS)
	@${REINPLACE_CMD} '/install-exec-local:/s/install-exec-localcharset//' \
		${WRKSRC}/lib/Makefile.in
.endif
	@${REINPLACE_CMD} 's|mkinstalldirs = .*|mkinstalldirs = ${MKDIR}|g' \
		${WRKSRC}/po/Makefile.in.in

.include <bsd.port.mk>
