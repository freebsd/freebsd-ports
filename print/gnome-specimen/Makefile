# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	gnome-specimen
PORTVERSION=	0.4
PORTREVISION=	4
CATEGORIES=	print
MASTER_SITES=	http://uwstopia.nl/geek/projects/gnome-specimen/releases/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Gnome Specimen is a simple tool to preview and compare installed fonts

GNU_CONFIGURE=	yes
USE_GNOME=	pygnomedesktop
GCONF_SCHEMAS=	gnome-specimen.schemas
USES=		gettext gmake python
USE_AUTOTOOLS=	automake:env
INSTALLS_ICONS=	yes

post-configure:
	@${INSTALL_SCRIPT} ${AUTOMAKE_DIR}/py-compile ${WRKSRC}

.include <bsd.port.mk>
