# ex:ts=8
# Ports collection makefile for:	help2man
# Date created:			Jan 30, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	help2man
PORTVERSION=	1.33.1
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	arved@FreeBSD.org
COMMENT=	Automatically generating simple manual pages from program output

.if !defined(WITHOUT_NLS)
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext
RUN_DEPENDS=	${BUILD_DEPENDS}

MANLANG=	"" pl fr
PLIST_SUB=		NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB=		NLS="@comment "
.endif

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		help2man.1

INFO=		help2man
PLIST_FILES=	bin/help2man %%NLS%%lib/hacklocaledir.so \
		%%NLS%%share/locale/fr/LC_MESSAGES/help2man.mo \
		%%NLS%%share/locale/pl/LC_MESSAGES/help2man.mo

.include <bsd.port.mk>
