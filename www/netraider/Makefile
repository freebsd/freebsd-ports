# New ports collection makefile for:	netraider
# Date created:				5 Jul 2001
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	netraider
PORTVERSION=	0.0.2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://www.mandragon.org/raider/
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	${PORTNAME}-source-${PORTVERSION}

MAINTAINER=	kde@freebsd.org

USE_QT_VER=	2
USE_REINPLACE=	yes
USE_OPENSSL=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CFLAGS+=	-DBSD
SUBST=		${WRKSRC}/konq-embed/src/Makefile.in

pre-configure:
	${FIND} ${WRKSRC} -name Makefile.am | ${XARGS} ${REINPLACE_CMD} -e \
		"s@-lqt@-lqt @g; s@ -lqt @ -lqt2@g"
	${CP} ${WRKSRC}/konq-embed/src/konqueror ${WRKSRC}/konq-embed/src/konq-embedded
	${REINPLACE_CMD} \
		-e 's,^bindir = \$$(prefix),bindir= ${PREFIX}/bin,g' \
		-e 's,bin_SCRIPTS = konqueror,bin_SCRIPTS= konq-embedded,g' \
		-e 's,-lqt,-lqt ,g' \
		-e 's, -lqt , -lqt2,g' \
		${WRKSRC}/konq-embed/src/Makefile.in

.include <bsd.port.mk>
