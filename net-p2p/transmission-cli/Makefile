# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	0.81
PORTREVISION?=	0
CATEGORIES=	net-p2p
#MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/
MASTER_SITES=	${MASTER_SITE_LOCAL} \
		http://people.freebsd.org/~mezz/distfiles/
MASTER_SITE_SUBDIR=mezz
DISTNAME=	Transmission-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT?=	A free BitTorrent client written from scratch in C

USE_GMAKE=	yes
SLAVE_TRANS?=	no
HAS_CONFIGURE=	yes
CONFIGURE_ARGS?=--prefix=${PREFIX} \
		--disable-daemon \
		--disable-gtk

DOCS=		AUTHORS LICENSE NEWS README

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude beos \
			--exclude macosx \
			--exclude Transmission.xcodeproj

.if !defined(MASTERDIR)
EXTRACT_AFTER_ARGS+=	--exclude daemon \
			--exclude gtk \
			--exclude libevent \
			--exclude wx
MAN1=			transmissioncli.1
.endif

.if ${SLAVE_TRANS}=="gtk2"
EXTRACT_AFTER_ARGS+=	--exclude cli \
			--exclude daemon \
			--exclude libevent \
			--exclude wx
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
	@${ECHO_MSG} "WITHOUT_OPENSSL=yes to disable OpenSSL support, using built-in SHA1 implementation. Warning, it is a bit slower if you use this option." | ${FMT} 75 75
.endif

general-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/|${LOCALBASE}/|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|-g -Wall -W -O3 -funroll-loops|-Wall -W|g' \
			${WRKSRC}/mk/common.mk
	@${REINPLACE_CMD} -e 's|) .install.misc|)|g' \
		${WRKSRC}/mk/default.mk

post-patch: general-patch

general-install:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install: general-install

.include <bsd.port.mk>
