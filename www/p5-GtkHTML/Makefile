# New ports collection makefile for:	p5-GtkHTML
# Date created:				11 March 2001
# Whom:					vanilla
#
# $FreeBSD$
#

PORTNAME=	GtkHTML
PORTVERSION=	0.7006
PORTREVISION=	2
CATEGORIES=	www lang perl5 gnome
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Gtk
PKGNAMEPREFIX=	p5-
DISTNAME=	Gtk-Perl-${PORTVERSION}

MAINTAINER=	vanilla@FreeBSD.org
COMMENT=	The Gtk HTML module of Gtk-Perl

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Gnome.pm:${PORTSDIR}/x11-toolkits/p5-Gnome \
		${SITE_PERL}/XML/Writer.pm:${PORTSDIR}/textproc/p5-XML-Writer
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_GNOME=	gnomeprefix gtkhtml
PERL_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

MAN3=		Gtk::HTML::reference.3pm

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6.0 or later. Install lang/perl5 then try again
.endif

.include <bsd.port.post.mk>
