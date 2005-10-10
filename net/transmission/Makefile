# New ports collection makefile for:	transmission
# Date created:				08 October 2005
# Whom:					Mezz <mezz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	transmission
PORTVERSION=	0.2.20051009
CATEGORIES=	net
#MASTER_SITES=	http://download.m0k.org/${PORTNAME}/files/
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	mezz
DISTNAME=	Transmission-${PORTVERSION}

MAINTAINER=	mezz@FreeBSD.org
COMMENT=	A free BitTorrent client written from scratch in C

BUILD_DEPENDS=	jam:${PORTSDIR}/devel/jam

USE_OPENSSL=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes

EXTRACT_AFTER_ARGS=	| ${TAR} -xf - --exclude macosx \
			--exclude packageOSX.sh

PLIST_FILES=	bin/transmissioncli
PORTDOCS=	AUTHORS LICENSE NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|-pthread|${PTHREAD_LIBS}|g ; \
		s|$$LINKLIBS ;|${LDFLAGS} $$LINKLIBS ;|g' \
			${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|-O3||g ; \
		s|-g |${CFLAGS} ${CPPFLAGS} ${PTHREAD_CFLAGS}|g' \
			${WRKSRC}/Jamrules

# jam -dx, it will giving a verbose of build.
do-build:
	@(cd ${BUILD_WRKSRC} ; ${SETENV} ${MAKE_ENV} jam)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/transmissioncli ${PREFIX}/bin/
.ifndef (NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
