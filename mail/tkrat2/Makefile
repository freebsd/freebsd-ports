# New ports collection makefile for:	tkrat2
# Date created:		9 November 1999
# Whom:			Stephen J. Roznowski <sjr@home.net>
#
# $FreeBSD$
#

PORTNAME=	tkrat
PORTVERSION= 	2.0.rc3
CATEGORIES=	mail tk82
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/tkrat/ \
		ftp://ftp.sunet.se/pub/unix/mail/tkrat/
DISTNAME=	${PORTNAME}-2.0rc3

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	tcl82:${PORTSDIR}/lang/tcl82 \
		tk82:${PORTSDIR}/x11-toolkits/tk82 \
		c-client4.7:${PORTSDIR}/mail/imap-uw

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.2 \
		--with-tk-config=${PREFIX}/lib/tk8.2

DOCFILES=	CONFIGURATION COPYRIGHT README doc/interface doc/userprocs \
		doc/userproc.example

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
