# New ports collection makefile for:	magicpoint
# Date created:		24 December 1997
# Whom:			itojun@itojun.org
#
# $FreeBSD$
#
# "?=" and "+=" are for localized (i.e. Japanese) version

PORTNAME=	magicpoint
PORTVERSION=	1.10a
PORTREVISION=	1
CATEGORIES+=	misc
MASTER_SITES=	ftp://ftp.mew.org/pub/mgp/

MAINTAINER?=	mita@FreeBSD.org
COMMENT?=	An X11-based presentation tool

LIB_DEPENDS+=	png.5:${PORTSDIR}/graphics/png \
		mng:${PORTSDIR}/graphics/libmng
RUN_DEPENDS+=	pnmscale:${PORTSDIR}/graphics/netpbm

USE_IMAKE=	yes
USE_REINPLACE=	yes
USE_FREETYPE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS?=--disable-vflib

MAN1=	mgp.1 mgp2ps.1 mgpembed.1 mgpnet.1 xwintoppm.1 xmindpath.1

DOCS=	COPYRIGHT COPYRIGHT.jp FAQ README README.fonts README.fonts.jp \
	README.lang RELNOTES SYNTAX TODO.jp USAGE USAGE.jp
SAMPLES=	README README.jp cloud.jpg dad.eps dad.jpg default.mgp \
		embed-jp.mgp embed.mgp gradation-jp.mgp \
		gradation.mgp mgp-old1.jpg mgp-old2.jpg mgp-old3.jpg \
		mgp.mng mgp1.jpg mgp2.jpg mgp3.jpg mgp3.xbm mgprc-sample \
		multilingual.mgp sample-fr.mgp sample-jp.mgp sample.mgp \
		sendmail6-jp.mgp sendmail6.mgp tutorial-jp.mgp \
		tutorial.mgp v6-jp.mgp v6.mgp v6header.eps v6header.jpg
EMACS_LISPS=	mgp-mode.el mgp-el/COPYING mgp-el/README \
		mgp-el/mgp.el mgp-el/mgp.sty mgp-el/sample.tex
SAMPLE_SCRIPTS=	eqn2eps.sh tex2eps.sh mgp2html.pl mgp2latex.pl

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|varargs.h|stdarg.h|' \
		${WRKSRC}/image/rlelib.c

post-configure:
	(cd ${WRKSRC}/contrib/xmindpath; ./configure --prefix=${PREFIX})

post-build:
	(cd ${WRKSRC}/contrib/xmindpath; make)
.if ${X_WINDOW_SYSTEM:L} != xfree86-3
	(cd ${WRKSRC}/contrib/xmindpath; \
	 ${RM} -f xmindpath.1.html xmindpath-1.html; \
	 ${X11BASE}/bin/rman -f HTML < xmindpath.1 > xmindpath-1.html && \
	 ${MV} -f xmindpath-1.html xmindpath.1.html)
.endif

# NOTE: there are some discussions/twists in gzip'ing xmindpath.1.
post-install:
	(cd ${WRKSRC}/contrib/xmindpath; make install)
	${GZIP_CMD} ${PREFIX}/man/man1/xmindpath.1
.if ${X_WINDOW_SYSTEM:L} != xfree86-3
	(cd ${WRKSRC}/contrib/xmindpath; \
	 ${INSTALL_MAN} xmindpath.1.html ${PREFIX}/lib/X11/doc/html)
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/mgp
	for i in $(DOCS); do \
		${INSTALL_DATA} ${WRKSRC}/$$i ${PREFIX}/share/doc/mgp; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/sample
	for i in $(SAMPLES); do \
		${INSTALL_DATA} ${WRKSRC}/sample/$$i ${PREFIX}/share/doc/mgp/sample; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/emacs-lisp/mgp-el
	for i in $(EMACS_LISPS); do \
		${INSTALL_DATA} ${WRKSRC}/contrib/$$i ${PREFIX}/share/doc/mgp/emacs-lisp/$$i; \
	done
	${MKDIR} ${PREFIX}/share/doc/mgp/scripts
	for i in $(SAMPLE_SCRIPTS); do \
		${INSTALL_SCRIPT} ${WRKSRC}/contrib/$$i ${PREFIX}/share/doc/mgp/scripts/$$i; \
	done
.endif

.include <bsd.port.post.mk>
