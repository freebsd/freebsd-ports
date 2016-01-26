# Created by: reed@pugetsoundtechnology.com
# $FreeBSD$

PORTNAME=	libwpd
PORTVERSION=	0.9.9
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	office@FreeBSD.org
COMMENT=	Tools for importing and exporting WordPerfect(tm) documents

DEPRECATED=	Not used any more
EXPIRATION_DATE=2016-03-26

LICENSE=	LGPL21 MPL
LICENSE_COMB=	dual

USES=		pathfix libtool:keepla tar:bzip2
GNU_CONFIGURE=	yes
USE_GNOME=	libgsf
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--without-docs
PLIST_SUB=	MAJVER=${PORTVERSION:R}

post-stage:
	@${RM} ${STAGEDIR}${PREFIX}/bin/wpd*

.include <bsd.port.mk>
