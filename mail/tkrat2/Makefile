# New ports collection makefile for:	tkrat2
# Date created:		9 November 1999
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	tkrat
PORTVERSION=	2.0.1
CATEGORIES=	mail tk83
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/tkrat/ \
		ftp://ftp.sunet.se/pub/unix/mail/tkrat/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tcl83:${PORTSDIR}/lang/tcl83 \
		tk83:${PORTSDIR}/x11-toolkits/tk83 \
		c-client4.8:${PORTSDIR}/mail/cclient

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.3 \
		--with-tk-config=${PREFIX}/lib/tk8.3 \
		--with-tcl-include=${PREFIX}/include/tcl8.3 \
		--with-tk-include=${PREFIX}/include/tk8.3
MAKE_ARGS+=	-j2 -B
EXTRACT_AFTER_ARGS=| ${TAR} -xf - --exclude '*/imap/*'

DOCFILES=	CONFIGURATION COPYRIGHT README doc/interface doc/userprocs \
		doc/userproc.example

MAN1=		tkrat.1

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Copying documents to ${PREFIX}/${PORTDOCDIR}"
	@${MKDIR} ${PREFIX}/share/doc/tkrat
.for f in ${DOCFILES}
	${INSTALL_DATA} ${WRKSRC}/${f} ${PREFIX}/share/doc/tkrat
.endfor
.else
	@${ECHO_MSG} "===>  Not copying available documents"
.endif
	@${MKDIR} ${PREFIX}/lib/ratatosk
	${INSTALL_DATA} ${FILESDIR}/ratatoskrc ${PREFIX}/lib/ratatosk

.include <bsd.port.mk>
