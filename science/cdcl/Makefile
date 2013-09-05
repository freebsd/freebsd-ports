# Created by: Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
# $FreeBSD$

PORTNAME=	cdcl
PORTVERSION=	5.4.7
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/arch/dcl/ \
		http://dennou-h.gfd-dennou.org/arch/dcl/ \
		http://dennou-q.gfd-dennou.org/arch/dcl/
DISTNAME=	dcl-${PORTVERSION}-C

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Scientific graphic library for geoscience

USES=		pkgconfig
USE_GCC=	any
USE_XORG=	x11 xext
USE_GNOME=	gtk20 gdkpixbuf2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --with-x --enable-shared

PLIST_SUB=	DCL_VERSION=${PORTVERSION:S/.//g}

MAKE_JOBS_UNSAFE=	yes

.include <bsd.port.pre.mk>

BINARIES=	cdclcmap cdclclr cdcldate cdcldbs cdclexec cdclfont \
		cdclpara cdcltone cdcltrf cdclver
PORTDOCS=	CHECK CREDITS HISTORY README
PORTEXAMPLES=	*

RESTRICTED=	No commercial use

post-configure:
	@${REINPLACE_CMD} -e 's|$$(DCLLANG)dcl$$(DCLVERNUM)|$$(DCLLANG)dcl|' ${WRKSRC}/Mkinclude

post-install:
.for i in ${BINARIES}
	${STRIP_CMD} ${PREFIX}/bin/${i}
.endfor
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

.include <bsd.port.post.mk>
