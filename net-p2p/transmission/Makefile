# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	0.6.1
PORTREVISION?=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=mezz
DISTNAME=	Transmission-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT?=	A free BitTorrent client written from scratch in C

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS?=--prefix=${PREFIX} \
		--disable-gtk

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude beos \
			--exclude macosx \
			--exclude packageOSX.sh \
			--exclude Sparkle.framework \
			--exclude Transmission.xcodeproj

DOCS=		AUTHORS LICENSE NEWS README

.if defined(SLAVE_TRANS)
EXTRACT_AFTER_ARGS+=--exclude cli
.else
CFLAGS+=	${CPPFLAGS}
USE_GETOPT_LONG=yes
EXTRACT_AFTER_ARGS+=--exclude gtk
MAN1=		transmissioncli.1
.endif

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=--disable-openssl
.else
USE_OPENSSL=	yes
.endif

pre-everything::
.if !defined(WITHOUT_OPENSSL)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.endif
.if !defined(WITHOUT_OPENSSL)
	@${ECHO_MSG} "WITHOUT_OPENSSL=yes to disable OpenSSL support, using built-in SHA1 implementation. Warning, it is a bit slower if you use this option." | ${FMT} 75 75
.endif

general-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g ; \
		s|/usr/X11R6/|${X11BASE}/|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|-g -Wall -W -O3 -funroll-loops|-Wall -W|g' \
			${WRKSRC}/mk/common.mk

post-patch: general-patch

.ifndef (NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
