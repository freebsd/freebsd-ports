# New ports collection makefile for:	tkrat
# Date created:		24 October 1997
# Whom:			Bruce Gingery <bgingery@gtcs.com>
#
# $FreeBSD$
#

PORTNAME=	tkrat
PORTVERSION=	1.2
CATEGORIES=	mail tk82
MASTER_SITES=	ftp://ftp.karen.hik.se/pub2/unix/mail/ratatosk/ \
		ftp://ftp.mc.hik.se/pub/unix/mail/ratatosk/ \
		ftp://ftp.riken.go.jp/pub/net/mail/tkrat/ \
		ftp://ftp.uni-koeln.de/windows/xcontrib/

MAINTAINER=	petef@databits.net

BUILD_DEPENDS=	tclsh8.2:${PORTSDIR}/lang/tcl82
LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82 \
		c-client4.8:${PORTSDIR}/mail/cclient

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
