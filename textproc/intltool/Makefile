# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/textproc/intltool/Makefile 17268 2013-04-01 05:13:11Z marcus $

PORTNAME=	intltool
PORTVERSION=	0.50.2
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	http://launchpadlibrarian.net/94524169/
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Tools to internationalize various kinds of data files

BUILD_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	p5-XML-Parser>=0:${PORTSDIR}/textproc/p5-XML-Parser

USES=		iconv gmake perl5
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
