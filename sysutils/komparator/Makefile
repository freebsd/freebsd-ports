# New ports collection makefile for:	komparator
# Date created:				18 Jan 2006
# Whom:			Alexander V. Ribchansky <triosoft@triosoft.com.ua>
#
# $FreeBSD$

PORTNAME=	komparator
PORTVERSION=	0.5
PORTREVISION=	6
CATEGORIES=	sysutils kde
MASTER_SITES=	SF

MAINTAINER=	triosoft@triosoft.com.ua
COMMENT=	KDE app that searches and synchronizes two directories

USE_KDELIBS_VER=3
USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
USE_BZIP2=	yes
USE_GETTEXT=	yes

DOCSDIR=	${PREFIX}/share/doc/HTML/en/komparator

post-patch:
	${REINPLACE_CMD} -e 's,-O2,,g ; \
		s,-lpthread,${PTHREAD_LIBS},g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
.if defined(NOPORTDOCS)
	${REINPLACE_CMD} -e 's|doc po src|po src|g' ${WRKSRC}/Makefile
.endif

.include <bsd.port.mk>
