# New ports collection makefile for:	tkrat
# Version required:	1.1
# Date created:		24 October 1997
# Whom:			Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.3 1997/12/07 07:21:20 hoek Exp $
#

DISTNAME=	tkrat-1.1
CATEGORIES=	mail tk80
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/tkrat/ \
		ftp://ftp.sunet.se/pub/unix/mail/tkrat/

MAINTAINER=	bgingery@gtcs.com

BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80\\.1\\.2:${PORTSDIR}/lang/tcl80 \
		tk80\\.1\\.2:${PORTSDIR}/x11/tk80 \
		c-client\\.2\\.1:${PORTSDIR}/mail/imap-uw

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--with-tcl-config=${PREFIX}/lib/tcl8.0 \
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
	#/bin/chmod ugo+wt /var/mail

.include <bsd.port.mk>
