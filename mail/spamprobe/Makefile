# New ports collection makefile for:    spamprobe
# Whom:                                 Matthew N. Dodd <mdodd@FreeBSD.org>
# Date created:                         05 September 2002
#
# $FreeBSD$
#

PORTNAME=	spamprobe
PORTVERSION=	0.9h
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Spam detector using Bayesian analysis of word counts

LIB_DEPENDS=	db4.0:${PORTSDIR}/databases/db4

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-default-8bit
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include/db4" \
		LDFLAGS="-L${LOCALBASE}/lib"

MAN1=	spamprobe.1

.include <bsd.port.mk>
