# New ports collection makefile for:	mod_dtcl
# Version required:			0.6.4-2
# Date created:				January 9, 1999
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

DISTNAME=	libapache-mod-dtcl_0.7.3-1
PKGNAME=	mod_dtcl-0.7.3.1
CATEGORIES=	www tcl82
MASTER_SITES=	http://master.debian.org/~davidw/mod_dtcl/

MAINTAINER=	mi@aldan.algebra.com

BUILD_DEPENDS=	${LOCALBASE}/sbin/apxs:${PORTSDIR}/www/apache13
LIB_DEPENDS=	tcl82:${PORTSDIR}/lang/tcl82

WRKSRC=		${WRKDIR}/mod_dtcl

MAKEFILE=	${FILESDIR}/Makefile.bsd

MAN1=		testdtcl.1
MANCOMPRESSED=	no

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmod_dtcl.so.1* \
		${PREFIX}/libexec/apache/mod_dtcl.so
	${INSTALL_PROGRAM} ${WRKSRC}/testdtcl ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/testdtcl.1 ${PREFIX}/man/man1/
	${MKDIR} ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/dtcl.tcl ${PREFIX}/share/doc/mod_dtcl
.if !defined(NOPORTDOCS)
	${INSTALL_DATA} ${WRKSRC}/*.?tml ${WRKSRC}/*.gif \
		${PREFIX}/share/doc/mod_dtcl
	${CAT} ${PKGMESSAGE}
.else
	# Not installing the documentation. Consult the
	#	file:/${WRKSRC}/INSTALL.html
	# for information on how to proceed to enable mod_dtcl.
	# Note, that the dtcl.tcl mentioned there is installed as
	#	${PREFIX}/share/doc/mod_dtcl/dtcl.tcl
	# but the comment in it suggests it should not be used
	# in a "production environment"...
.endif

.include <bsd.port.mk>
