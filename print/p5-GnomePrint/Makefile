# New ports collection makefile for:	p5-GnomePrint
# Date created:				11 March 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GnomePrint
PORTVERSION=	0.7008
CATEGORIES=	print lang perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Gnome Print module of Gtk-Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome \
		${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/Pixbuf.pm:${PORTSDIR}/x11-toolkits/p5-GdkPixbuf \
		${SITE_PERL}/${PERL_ARCH}/Gtk/Gdk/ImlibImage.pm:${PORTSDIR}/x11-toolkits/p5-GdkImlib
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	yes
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3PREFIX=     ${LOCALBASE}/lib/perl5/${PERL_VERSION}
MAN3=		Gnome::Print::reference.3pm

.include <bsd.port.mk>
