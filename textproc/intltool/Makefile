# Created by: Ade Lovett <ade@FreeBSD.org>
# $FreeBSD$

PORTNAME=	intltool
PORTVERSION=	0.51.0
PORTREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	https://launchpad.net/intltool/trunk/${PORTVERSION}/+download/
DIST_SUBDIR=	gnome

MAINTAINER=	desktop@FreeBSD.org
COMMENT=	Tools to internationalize various kinds of data files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser
RUN_DEPENDS=	p5-XML-Parser>=0:textproc/p5-XML-Parser

USES=		iconv gmake perl5
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
