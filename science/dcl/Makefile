# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	dcl
PORTVERSION=	5.4.8
PORTREVISION=	5
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/library/dcl/ \
		http://dennou-h.gfd-dennou.org/library/dcl/ \
		http://dennou-q.gfd-dennou.org/library/dcl/

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Scientific graphic library for geoscience

MAKE_JOBS_UNSAFE=	yes
USES=		desthack pkgconfig fortran
USE_XORG=	x11 xext
USE_GNOME=	gtk20 gdkpixbuf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-x

PORTDOCS=	CHECK CREDITS HISTORY README
PORTEXAMPLES=	*

RESTRICTED=	No commercial use

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demo/ && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
