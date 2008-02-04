# New ports collection makefile for:   cutlass
# Date created:        28 December 2005
# Whom:                Wesley Shields <wxs@csh.rit.edu>
#
# $FreeBSD$
#

PORTNAME=	cutlass
PORTVERSION=	0.2.0
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.synacklabs.net/projects/cutlass/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Encrypted peer-to-peer voice, text, and file transmission protocol

BUILD_DEPENDS=	botan-config:${PORTSDIR}/security/botan \
		speexdec:${PORTSDIR}/audio/speex

MAN3=	cutlass.3

INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
USE_GNOME=	libglade2
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}"

CPPFLAGS+=	-I${LOCALBASE}/include/speex -I${LOCALBASE}/include

.include <bsd.port.mk>
