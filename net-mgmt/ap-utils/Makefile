# New ports collection makefile for:    ap-utils
# Date created:		2002/07/10
# Whom:			Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	ap-utils
PORTVERSION=	1.3.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	daniel+aputils@pelleg.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN8=		ap-trapd.8 ap-mrtg.8 ap-config.8

.if !defined(NOPORTDOCS)
post-install:
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC}/Documentation && \
		${INSTALL_DATA} FAQ Ovislink-HOWTO.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
