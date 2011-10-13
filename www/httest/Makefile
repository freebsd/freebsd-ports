# New ports collection makefile for:	httest
# Date created:			Jun 15, 2011
# Whom:				Martin Matuska <mm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	httest
PORTVERSION=	2.1.5
CATEGORIES=	www
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	htt/htt2.1/${PORTNAME}-${PORTVERSION}

MAINTAINER=	mm@FreeBSD.org
COMMENT=	HTTP Test Tool

LIB_DEPENDS+=	apr-1:${PORTSDIR}/devel/apr1 \
		pcre.0:${PORTSDIR}/devel/pcre

LICENSE=	ASL

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes

LDFLAGS+=	-lm

CONFIGURE_ARGS+=--with-apr="${LOCALBASE}/bin" \
		--with-apr-util="${LOCALBASE}/bin" \
		--with-pcre="${LOCALBASE}/bin"

CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

MAN1=		httest.1 htproxy.1 htntlm.1 htremote.1 hturlext.1 htx2b.1

.include <bsd.port.mk>
