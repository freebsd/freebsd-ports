# ex:ts=8
# Ports collection makefile for:	terraform
# Date created:			Feb 8, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	terraform
PORTVERSION=	0.9.0
PORTREVISION=	2
CATEGORIES=	misc gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Interactive height field generation and manipulation program

BUILD_DEPENDS=	${LOCALBASE}/lib/libtrio.a:${PORTSDIR}/devel/trio

USE_X_PREFIX=	yes
USE_BISON=	yes
USE_REINPLACE=	yes
USE_GNOME=	gnomeprefix gnomehack gnomeprint
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e "s|Bison |Bison|g ; \
		 s|-ltrio  $$LIBS|-ltrio -lm $$LIBS|g ; \
		 s|#define  1|#define HAVE_LIB_TRIO 1|g ; \
		 s|(HAVE_LIB_TRIO)||g" ${WRKSRC}/configure
	@${REINPLACE_CMD} -e "s|malloc\.h|stdlib.h|g" ${WRKSRC}/src/xmlsupport.c
	@${FIND} ${WRKSRC} -name "Makefile.in" | ${XARGS} ${REINPLACE_CMD} -e \
		's|@datadir@/gnome/|@datadir@/|g'

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in FAQ.sgml README.sgml UsersGuide.sgml i18n.txt
	${INSTALL_DATA} ${WRKSRC}/docs/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
