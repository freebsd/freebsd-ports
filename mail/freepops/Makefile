# New ports collection makefile for:   freepops
# Date created:                19 Feb 2005
# Whom:                        Filippo Natali <filippo@widestore.net>
#
# $FreeBSD$
#

PORTNAME=	freepops
PORTVERSION=	0.0.25
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	freepops

MAINTAINER=	filippo@widestore.net
COMMENT=	Extensible webmail to pop3 interface

LIB_DEPENDS=	expat.5:${PORTSDIR}/textproc/expat2 \
		curl:${PORTSDIR}/ftp/curl
BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison

MAN1=		freepopsd.1
USE_GMAKE=	yes
HAS_CONFIGURE=	yes
USE_REINPLACE=	yes
CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ARGS=	fbsd

pre-configure:
	@${REINPLACE_CMD} -e "s|^WHERE=\/usr\/local\/|WHERE=${PREFIX}\/|g"  ${WRKSRC}/${CONFIGURE_SCRIPT}

post-install:
.if !defined(BATCH)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
