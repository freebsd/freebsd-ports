# New ports collection makefile for:	DCL
# Date created:		30 January 2005
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	dcl
PORTVERSION=	5.3.3
PORTREVISION=	4
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/arch/dcl/ \
		http://dennou-h.gfd-dennou.org/arch/dcl/ \
		http://dennou-q.gfd-dennou.org/arch/dcl/

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Scientific graphic library for geoscience

USE_XORG=	x11 xext
USE_FORTRAN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --disable-gtk2 --disable-gtk --with-x

DOCFILES=	CHECK CREDITS HISTORY README README_clrmap README_gt2dlib \
		README_itr51 README_pslib README_umfmap

RESTRICTED=	No commercial use

post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/demo/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
