# New ports collection makefile for:	latex2rtf
# Date created:         14 Dec 1999
# Whom:                 Joerg Wunsch <joerg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	latex2rtf
PORTVERSION=	2.0.0
CATEGORIES=	print
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-unix/${PORTVERSION} \
		${MASTER_SITE_TEX_CTAN}


MAINTAINER=	joerg@FreeBSD.org
COMMENT=	Translator from LaTeX to RTF

MAN1=		latex2rtf.1 latex2png.1
INFO=		latex2rtf

USES=		perl5
USE_PERL5=	build

INSTALL_TARGET=	install install-info

pre-patch:
	@${CP} ${WRKSRC}/doc/latex2rtf.info ${WRKSRC}/doc/latex2rtf.info.bak
	@${TR} -d '\r\b\0' < ${WRKSRC}/doc/latex2rtf.info.bak > ${WRKSRC}/doc/latex2rtf.info

.include <bsd.port.mk>
