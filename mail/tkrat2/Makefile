# New ports collection Makefile for:	TkRat
# Version required:	1.0.5
# Date created:		24 October 1997
# Whom:			Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.1.1.1 1997/11/14 22:51:07 hoek Exp $
#

DISTNAME=	tkrat-1.0.5
CATEGORIES=	mail tk80
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/tkrat/ \
		ftp://ftp.sunet.se/pub/unix/mail/tkrat/
# NOTE:  "fetch" fails on FreeBSD 2.2.1 for "no-login", but ncftp succeeds
#	from commandline, or script invocation.

MAINTAINER=	bgingery@gtcs.com

BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80 \
		${PORTSDIR}/mail/imap-uw/work/imap-4.1.BETA/c-client:${PORTSDIR}/mail/imap-uw
LIB_DEPENDS=	c-client\\.2\\.1:${PORTSDIR}/mail/imap-uw \
		tk80\\.1:${PORTSDIR}/x11/tk80

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared=yes \
		--with-tcl-config=${PREFIX}/lib/tcl8.0 \
		--with-tk-config=${PREFIX}/lib/tk8.0

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
