# ex:ts=8
# Ports collection makefile for:	help2man
# Date created:			Jan 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	help2man
PORTVERSION=	1.38.2
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	sunpoet@sunpoet.net
COMMENT=	Automatically generating simple manual pages from program output

.if !defined(WITHOUT_NLS)
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext

CFLAGS+=	-lintl
INSTALL_TARGET=	install install_l10n
MANLANG=	"" de fi fr pl pt_BR ru sv vi
PLIST_SUB+=	NLS=""
USE_GETTEXT=	yes
.else
CONFIGURE_ARGS+=--disable-nls
INSTALL_TARGET=	install
PLIST_SUB+=	NLS="@comment "
.endif

CFLAGS+=	-L${LOCALBASE}/lib
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes

INFO=		help2man
MAN1=		help2man.1

.include <bsd.port.mk>
