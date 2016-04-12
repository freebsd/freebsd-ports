# Created by: Zane C, Bowers-Hadley <vvelox@vvelox.net>
# $FreeBSD$

PORTNAME=	Gtk2-WebKit
PORTVERSION=	0.09
PORTREVISION=	2
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:FLORA
PKGNAMEPREFIX=	p5-

MAINTAINER=	vvelox@vvelox.net
COMMENT=	Web content engine library for Gtk2

BUILD_DEPENDS=	p5-Cairo>=0:graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=0:devel/p5-Glib2 \
		p5-Gtk2>=0:x11-toolkits/p5-Gtk2 \
		${LOCALBASE}/libdata/pkgconfig/webkit-1.0.pc:www/webkit-gtk2
RUN_DEPENDS=	p5-Gtk2>=0:x11-toolkits/p5-Gtk2

MAKE_JOBS_UNSAFE=	yes

NO_PACKAGE=	Man page creation hangs on some systems for unknown reasons

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
