# New ports collection makefile for:	xlhtml
# Date created:				27 March 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xlhtml
PORTVERSION=	0.5
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	chicago
EXTRACT_SUFX=	.tgz

MAINTAINER=	coop9211@uidaho.edu
COMMENT=	Convert Excel and PowerPoint files to HTML and text

USE_GMAKE=	yes
USE_AUTOMAKE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

MAN1=		ppthtml.1 xlhtml.1

.if !defined(NOPORTDOCS)
post-install:
.for dir in xlhtml ppthtml
	@${MKDIR} ${DOCSDIR}/${dir}
	cd ${WRKSRC}/${dir} && \
		${INSTALL_DATA} ChangeLog README THANKS ${DOCSDIR}/${dir}
.endfor
.endif

.include <bsd.port.mk>
