# New ports collection makefile for:	tkrat
# Date created:		24 October 1997
# Whom:			Bruce Gingery <bgingery@gtcs.com>
#
# $FreeBSD$
#

PORTNAME=	tkrat
PORTVERSION= 	1.2
CATEGORIES=	mail tk82
MASTER_SITES=	ftp://ftp.md.chalmers.se/pub/tkrat/ \
		ftp://ftp.sunet.se/pub/unix/mail/tkrat/

MAINTAINER=	appleseed@his.com

BUILD_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82
LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
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
	#${CHMOD} ugo+wt /var/mail

.include <bsd.port.mk>
