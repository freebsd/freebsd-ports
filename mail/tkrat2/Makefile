# Created by: Stephen J. Roznowski <sjr@home.net>
# $FreeBSD$

PORTNAME=	tkrat
PORTVERSION=	2.1.5
PORTREVISION=	5
CATEGORIES=	mail tk
MASTER_SITES=	http://tkrat.org/downloads/stable/ \
		ftp://ftp.tkrat.org/pub/tkrat/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Mail user agent for X with a Tcl/Tk user interface

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libtcl84.so:lang/tcl84 \
		libtk84.so:x11-toolkits/tk84 \
		libc-client4.so:mail/cclient

USE_XORG=	x11 xt

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.4 \
		--with-tk-config=${PREFIX}/lib/tk8.4 \
		--with-tcl-include=${PREFIX}/include/tcl8.4 \
		--with-tk-include=${PREFIX}/include/tk8.4 \
		--prefix=${PREFIX}
MAKE_ARGS+=	-j2 -B

OPTIONS_DEFINE=	DOCS

DOCFILES=	CONFIGURATION COPYRIGHT README doc/interface doc/userprocs \
		doc/userproc.example

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Build fails on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} '-e s|@INSTALL_PREFIX@|${STAGEDIR}${PREFIX}|g' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/util/Makefile.in \
		${WRKSRC}/tkrat/Makefile.in ${WRKSRC}/misc/Makefile.in \
		${WRKSRC}/doc/Makefile.in
	@${REINPLACE_CMD} '-e s|@libdir@|/lib|g' \
		${WRKSRC}/lib/Makefile.in ${WRKSRC}/util/Makefile.in
	@${REINPLACE_CMD} '-e s|@datadir@|/share|g' \
		${WRKSRC}/util/Makefile.in ${WRKSRC}/tkrat/Makefile.in \
		${WRKSRC}/misc/Makefile.in
	@${REINPLACE_CMD} '-e s|@bindir@|/bin|g' ${WRKSRC}/tkrat/Makefile.in
	@${REINPLACE_CMD} '-e s|@mandir@|/man|g' ${WRKSRC}/doc/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor
.endif
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ratatosk
	${INSTALL_DATA} ${FILESDIR}/ratatoskrc ${STAGEDIR}${PREFIX}/lib/ratatosk
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tkrat/ratatosk2.1.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tkrat/blt_busy1.0.so

.include <bsd.port.post.mk>
