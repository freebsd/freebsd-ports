# New ports collection makefile for:   liblingoteach
# Date created:        14 October 2003
# Whom:                Marcus von Appen
#
# $FreeBSD$
#

PORTNAME=	liblingoteach
PORTVERSION=	0.2.1
PORTREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	SF/lingoteach/OldFiles

MAINTAINER=	mva@FreeBSD.org
COMMENT=	A library for parsing lesson files based on the LingoTeach DTD

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
USE_GNOME=	gnomehack gnometarget libxml2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

.if defined(WITH_COMP)
CONFIGURE_ARGS+=	--with-compression
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug
.endif

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "liblingoteach can be used with the following switches:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "		WITH_COMP=yes	Enables zlib compression of"
	@${ECHO_MSG} "				the lesson files"
	@${ECHO_MSG} "		WITH_DEBUG=yes  Enables additional debugging"
	@${ECHO_MSG} "				information and output"
	@${ECHO_MSG} ""

.include <bsd.port.mk>
