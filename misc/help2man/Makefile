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

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Locale/gettext.pm:${PORTSDIR}/devel/p5-Locale-gettext
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
USE_PERL5=	yes

MAN1=		help2man.1
MANLANG=	"" pl fr
INFO=		help2man
PLIST_FILES=	bin/help2man lib/hacklocaledir.so \
		share/locale/fr/LC_MESSAGES/help2man.mo \
		share/locale/pl/LC_MESSAGES/help2man.mo

.include <bsd.port.mk>
