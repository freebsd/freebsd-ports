# New ports collection makefile for:	tkrat
# Version required:	1.1
# Date created:		24 October 1997
# Whom:			Bruce Gingery <bgingery@gtcs.com>
#
# $Id: Makefile,v 1.5 1998/07/24 06:15:46 hoek Exp $
#

DISTNAME=	tkrat-1.1
CATEGORIES=	mail tk80
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/tkrat/ \
		ftp://ftp.sunet.se/pub/unix/mail/tkrat/

MAINTAINER=	appleseed@his.com

BUILD_DEPENDS=	tclsh8.0:${PORTSDIR}/lang/tcl80
LIB_DEPENDS=	tcl80\\.1\\.2:${PORTSDIR}/lang/tcl80 \
		tk80\\.1\\.2:${PORTSDIR}/x11-toolkits/tk80 \
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
