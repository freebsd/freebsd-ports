# New ports collection makefile for:	cfengine2
# Date created:		2002-07-29
# Whom:			fanf@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	cfengine2
PORTVERSION=	2.0.3
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.iu.hio.no/pub/cfengine/ \
		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	cfengine-${PORTVERSION}

MAINTAINER=	fanf@FreeBSD.org
COMMENT=	GNU cfengine - a systems administration tool for networks

LIB_DEPENDS=	db4:${PORTSDIR}/databases/db4

FORBIDDEN=	"Stack overflow; http://www.securityfocus.com/archive/1/339083"

USE_OPENSSL=	yes

# if we use GNU_CONFIGURE=yes then the binaries get installed with weird names
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX}

MAN8=		cfengine.8

.include <bsd.port.mk>
