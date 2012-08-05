# New ports collection makefile for:	pound
# Date created:				27 August 2002
# Whom:					Anders Nordby <anders@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pound
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	www net
MASTER_SITES=	http://www.apsis.ch/pound/ \
		ftp://ftp.nuug.no/pub/anders/distfiles/
DISTNAME=	Pound-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	anders@FreeBSD.org
COMMENT=	Reverse proxy, load balancer and HTTP(S) frontend for web servers

GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USE_RC_SUBR=	${PORTNAME}

SUB_LIST=	NAME=${PORTNAME}

MAN8=	pound.8 poundctl.8

OPTIONS=	MSDAV		"With the Microsoft WebDAV extensions support" off \
		PCRE		"Build with libpcre support" on

CONFIGURE_ARGS=	--disable--tcmalloc --disable-hoard
PLIST_FILES=	sbin/pound sbin/poundctl
PORTDOCS=	README FAQ CHANGELOG

.include <bsd.port.pre.mk>

.if defined(WITH_MSDAV)
CONFIGURE_ARGS+=	--enable-msdav
.endif

.if !defined(WITHOUT_PCRE)
LIB_DEPENDS+=		pcre.1:${PORTSDIR}/devel/pcre
CFLAGS+=		"-I${LOCALBASE}/include"
CPPFLAGS+=		"-I${LOCALBASE}/include"
LDFLAGS+=		"-L${LOCALBASE}/lib"
.else
CONFIGURE_ARGS+=	--disable-pcreposix
.endif

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
