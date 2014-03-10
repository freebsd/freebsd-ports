# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	dcl
PORTVERSION=	5.4.7
PORTREVISION=	2
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/library/dcl/ \
		http://dennou-h.gfd-dennou.org/library/dcl/ \
		http://dennou-q.gfd-dennou.org/library/dcl/

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Scientific graphic library for geoscience

MAKE_JOBS_UNSAFE=	yes
USES=		fortran pkgconfig
USE_XORG=	x11 xext
USE_GNOME=	gtk20 gdkpixbuf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --with-x

PORTDOCS=	CHECK CREDITS HISTORY README
PORTEXAMPLES=	*

RESTRICTED=	No commercial use

NO_STAGE=	yes
post-install:
.if !defined(NOPORTEXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
	(cd ${WRKSRC}/demo/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
