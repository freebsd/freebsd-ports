# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xlhtml
PORTVERSION=	0.5
PORTREVISION=	4
PORTEPOCH=	1
CATEGORIES=	textproc
MASTER_SITES=	SF/chicago/${PORTNAME}/backend
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Convert Excel and PowerPoint files to HTML and text

USE_GMAKE=	yes
USE_AUTOTOOLS=	automake14 autoconf
CONFIGURE_ARGS=	--mandir=${PREFIX}/man
NO_STAGE=	yes

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
