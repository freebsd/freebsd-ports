# Created by: kwm@rainbow-runner.nl
# $FreeBSD$
#   $MCom: ports/mail/contact-lookup-applet/Makefile,v 1.15 2007/07/29 22:17:31 mezz Exp $

PORTNAME=	contact
PORTVERSION=	0.17
PORTREVISION=	8
CATEGORIES=	mail gnome
MASTER_SITES=	http://www.burtonini.com/computing/
PKGNAMESUFFIX=	-lookup-applet
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Gnome panel applet for easy Evolution contact book access

USES=        pathfix gettext gmake pkgconfig
USE_GNOME=	evolutiondataserver gnomepanel gnomeprefix \
		libgnomeui
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
