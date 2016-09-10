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

BROKEN_sparc64=	fails to build

USES=		ssl
USE_XORG=	x11 xt

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.4 \
		--with-tk-config=${PREFIX}/lib/tk8.4 \
		--with-tcl-include=${PREFIX}/include/tcl8.4 \
		--with-tk-include=${PREFIX}/include/tk8.4 \
		--with-ssl-dir=${OPENSSLBASE} \
		--prefix=${PREFIX}
MAKE_ARGS+=	-j2 -B

OPTIONS_DEFINE=	DOCS

DOCFILES=	CONFIGURATION COPYRIGHT README doc/interface doc/userprocs \
		doc/userproc.example

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
	@${REINPLACE_CMD} -e 's|/usr/include/openssl|$$(SSLDIR)|g' \
		${WRKSRC}/imap/src/osdep/unix/Makefile
	@${REINPLACE_CMD} -e 's|SSLDIR=/usr SSLINCLUDE=/usr/include/openssl|SSLDIR=${OPENSSLBASE} SSLINCLUDE=${OPENSSLINC}|g' \
		${WRKSRC}/imap/Makefile

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/ratatosk
	${INSTALL_DATA} ${FILESDIR}/ratatoskrc \
		${STAGEDIR}${PREFIX}/lib/ratatosk
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tkrat/ratatosk2.1.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/tkrat/blt_busy1.0.so

.include <bsd.port.mk>
