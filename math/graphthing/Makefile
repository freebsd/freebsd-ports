# ex:ts=8
# Ports collection makefile for:	GraphThing
# Date created:			Feb 10, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	graphthing
PORTVERSION=	1.3.2
PORTREVISION=	8
CATEGORIES=	math
MASTER_SITES=	http://graph.seul.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that allows you to create, manipulate, and study graphs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_BISON=	build
USE_WX=		2.6+
WX_CONF_ARGS=	absolute
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/graphthing bin/gt

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@CXX@|@CXX@|' ${WRKSRC}/src/GNUmakefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/graphthing ${PREFIX}/bin
	${LN} -sf graphthing ${PREFIX}/bin/gt

.include <bsd.port.mk>
