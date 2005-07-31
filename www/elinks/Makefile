# New ports collection makefile for:	links
# Date created:		21 January 2000
# Whom:			Michael Vasilenko <acid@stu.cn.ua>
#
# $FreeBSD$
#

PORTNAME=	elinks
PORTVERSION=	0.10.5
CATEGORIES=	www
MASTER_SITES=	http://keyserver.kjsl.com/~jharris/distfiles/ \
		http://elinks.or.cz/download/
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} ${DISTNAME}${EXTRACT_SUFX}.asc
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	jharris@widomaker.com
COMMENT=	Elinks - links text WWW browser with enhancements

USE_GPG?=	yes
SIG_FILES=	${DISTNAME}${EXTRACT_SUFX}.asc
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BZIP2=	yes
USE_BISON=	yes
USE_OPENSSL=	yes
#USE_ICONV=	yes
#CONFIGURE_ARGS+=	--with-libiconv-prefix=${LOCALBASE}
CONFIGURE_ARGS+=	--disable-nls

.if defined(WITH_256COLORS)
CONFIGURE_ARGS+=	--enable-256-colors
.endif

MAN1=		elinks.1
MAN5=		elinkskeys.5 elinks.conf.5

PLIST_FILES=	bin/elinks

.include <bsd.port.mk>
