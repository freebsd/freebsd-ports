# ex:ts=8
# Ports collection makefile for:	GraphThing
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	graphthing
PORTVERSION=	0.9.5
CATEGORIES=	math
MASTER_SITES=	http://graph.seul.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool that allows you to create, manipulate and study graphs

LIB_DEPENDS=	gtkmm.2:${PORTSDIR}/x11-toolkits/gtk--

USE_BZIP2=	yes
USE_GNOME=	gnometarget gtk12
USE_BISON=	yes
USE_REINPLACE=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

PLIST_FILES=	bin/graphthing bin/gt

post-patch:
	${REINPLACE_CMD} -e "s,\/usr\/include\/gtk-1.2\/gdk\/gdkkeysyms.h,," \
		${WRKSRC}/src/depend.1

.include <bsd.port.mk>
