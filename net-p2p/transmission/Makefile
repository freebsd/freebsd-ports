# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	0.5
PORTREVISION?=	0
CATEGORIES=	net-p2p
MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=mezz
DISTNAME=	Transmission-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT?=	A free BitTorrent client written from scratch in C

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

CFLAGS+=	-Wall -W ${CPPFLAGS}
HAS_CONFIGURE=	yes
USE_GETOPT_LONG=yes
CONFIGURE_ARGS?=--prefix=${PREFIX} \
		--disable-gtk

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude beos \
			--exclude macosx \
			--exclude packageOSX.sh

PLIST_FILES?=	bin/transmissioncli
PORTDOCS=	AUTHORS LICENSE NEWS README

.if defined(WITHOUT_OPENSSL)
CONFIGURE_ARGS+=--disable-openssl
.else
USE_OPENSSL=	yes
CONFIGURE_ARGS+=--openssl-prefix=${OPENSSLBASE}
.endif

pre-everything::
.if !defined(WITHOUT_OPENSSL)
	@${ECHO_MSG} "You may specify the following on the command line:"
	@${ECHO_MSG} " "
.endif
.if !defined(WITHOUT_OPENSSL)
	@${ECHO_MSG} "WITHOUT_OPENSSL=yes to disable OpenSSL support, using built-in SHA1 implementation. Warning, it is a bit slower if you use this option." | ${FMT} 75 75
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|$$LINKLIBS ;|${LDFLAGS} $$LINKLIBS ;|g ; \
		s|/usr/local/|${LOCALBASE}/|g ; s|/usr/X11R6/|${X11BASE}/|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||g' \
		${WRKSRC}/Jamrules

# jam -dx, it will giving a verbose of build.
do-build:
	@(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} jam -dx)

.if !defined(SLAVE_PORT)
do-install: docsfiles
	${INSTALL_PROGRAM} ${WRKSRC}/transmissioncli ${PREFIX}/bin/
.endif

docsfiles:
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
