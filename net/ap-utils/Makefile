# New ports collection makefile for:    ap-utils
# Date created:		2002/07/10
# Whom:			Jerry A! <jerry@thehutt.org>
#
# $FreeBSD$
#

PORTNAME=	ap-utils
PORTVERSION=	1.3
CATEGORIES=	net
MASTER_SITES=	http://ap-utils.polesye.net/files/ \
		http://web.cs.cmu.edu/~dpelleg/download/

MAINTAINER=	daniel+aputils@pelleg.org

LIB_DEPENDS=	intl.4:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
MAN8=		ap-trapd.8 ap-mrtg.8 ap-config.8

.if !defined(NOPORTDOCS)
post-install:
	@${MKDIR} ${DOCSDIR} ${DOCSDIR}/uk
	@cd ${WRKSRC}/Documentation && ${INSTALL_DATA} FAQ Ovislink-HOWTO.html ${DOCSDIR}
	@cd ${WRKSRC}/Documentation/uk && ${INSTALL_DATA} INSTALL README.atmel ${DOCSDIR}/uk
.endif

.include <bsd.port.mk>
