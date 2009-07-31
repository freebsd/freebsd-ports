# New ports collection makefile for:	GCFilms
# Date Created:				01 May 2005
# Whom:					Remington Lang <MrL0Lz@gmail.com>
#
# $FreeBSD$

PORTNAME=	gcfilms
PORTVERSION=	6.0
PORTREVISION=	3
CATEGORIES=	multimedia perl5
MASTER_SITES=	http://download.gna.org/gcfilms/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to manage movie collections

BUILD_DEPENDS=	${SITE_PERL}/Archive/Tar.pm:${PORTSDIR}/archivers/p5-Archive-Tar \
		${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple \
		${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP/Simple.pm:${PORTSDIR}/www/p5-libwww
RUN_DEPENDS=	${BUILD_DEPENDS}

WRKSRC=		${WRKDIR}/${PORTNAME}

# uses Gtk2 install wizard
IS_INTERACTIVE=	yes

NO_BUILD=	yes

do-install:
	cd ${WRKSRC} ; ./install --prefix=${PREFIX}

.include <bsd.port.mk>
