# Created by: ijliao
# $FreeBSD$

PORTNAME=	graphthing
PORTVERSION=	1.3.2
PORTREVISION=	9
CATEGORIES=	math
MASTER_SITES=	http://graph.seul.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool that allows you to create, manipulate, and study graphs

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

USE_GNOME=	gtk20
USES=		bison gmake tar:bzip2
USE_WX=		2.8
WX_UNICODE=	yes
WX_CONF_ARGS=	absolute
GNU_CONFIGURE=	yes
MAKEFILE=	GNUmakefile

PLIST_FILES=	bin/graphthing bin/gt

CPPFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|@@CXX@|@CXX@|' ${WRKSRC}/src/GNUmakefile.in

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/graphthing ${STAGEDIR}${PREFIX}/bin
	${LN} -sf graphthing ${STAGEDIR}${PREFIX}/bin/gt

.include <bsd.port.mk>
