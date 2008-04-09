# New ports collection makefile for:	tkrat2
# Date created:		9 November 1999
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	tkrat
PORTVERSION=	2.1.5
PORTREVISION=	2
CATEGORIES=	mail tk
MASTER_SITES=	http://tkrat.org/downloads/stable/ \
		ftp://ftp.tkrat.org/pub/tkrat/

MAINTAINER=	sjr@comcast.net
COMMENT=	A mail user agent for X with a Tcl/Tk user interface

LIB_DEPENDS=	tcl84:${PORTSDIR}/lang/tcl84 \
		tk84:${PORTSDIR}/x11-toolkits/tk84 \
		c-client4.9:${PORTSDIR}/mail/cclient

USE_XLIB=	yes

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.4 \
		--with-tk-config=${PREFIX}/lib/tk8.4 \
		--with-tcl-include=${PREFIX}/include/tcl8.4 \
		--with-tk-include=${PREFIX}/include/tk8.4
MAKE_ARGS+=	-j2 -B

DOCFILES=	CONFIGURATION COPYRIGHT README doc/interface doc/userprocs \
		doc/userproc.example

MAN1=		tkrat.1

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Build fails on sparc64
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/share/doc/tkrat
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif
	@${MKDIR} ${PREFIX}/lib/ratatosk
	${INSTALL_DATA} ${FILESDIR}/ratatoskrc ${PREFIX}/lib/ratatosk

.include <bsd.port.post.mk>
