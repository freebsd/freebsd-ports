# New ports collection makefile for:	versuch
# Date created:				1 October 2006
# Whom:					warlock <warlock@elcat.kg>
#
# $FreeBSD$
#

PORTNAME=	versuch
PORTVERSION=	1.02
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_EXTENDED} \
		http://warlock.elcat.kg/
MASTER_SITE_SUBDIR=	versuch
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	H323 voice&video proxy

LIB_DEPENDS=	pt_r.1:${PORTSDIR}/devel/pwlib \
		h323_r.1:${PORTSDIR}/net/openh323 \
		pcre\\+\\+.0:${PORTSDIR}/devel/pcre++

BROKEN=		Does not compile

WRKSRC=		${WRKDIR}/versuch

USE_GMAKE=	yes
USE_AUTOTOOLS=	autoconf:261
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
