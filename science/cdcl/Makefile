# New ports collection makefile for:	DCL-C
# Date created:		15 February 2004
# Whom:			Shin'ya Murakami <murakami@ahs.scitec.kobe-u.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	cdcl
PORTVERSION=	5.3.3
PORTREVISION=	4
CATEGORIES=	science graphics
MASTER_SITES=	http://www.gfd-dennou.org/arch/dcl/ \
		http://dennou-h.gfd-dennou.org/arch/dcl/ \
		http://dennou-q.gfd-dennou.org/arch/dcl/
DISTNAME=	dcl-${PORTVERSION}-C

MAINTAINER=	murashin@gfd-dennou.org
COMMENT=	Scientific graphic library for geoscience

.if defined(WITHOUT_GTK)
USE_XORG=	x11
.else
USE_GNOME=	gtk20
.endif

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--prefix=${PREFIX} --exec-prefix=${PREFIX} --with-x

.if defined(WITHOUT_GTK)
CONFIGURE_ARGS+=	--disable-gtk --disable-gtk2
.endif

PLIST_SUB=	DCL_VERSION=${PORTVERSION:S/.//g}

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=        -fPIC
.endif

BINARIES=	cdclcmap cdclclr cdcldate cdcldbs cdclexec cdclfont \
		cdclpara cdcltone cdcltrf cdclver
DOCFILES=	CHECK CREDITS HISTORY README README_clrmap README_gt2dlib \
		README_itr51 README_pslib README_umfmap

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
.for i in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.post.mk>
