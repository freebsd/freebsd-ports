# ex:ts=8
# Ports collection makefile for:  libsocket++
# Version required:     	  1.10
# Date created:			  Sun Jan 19, 1997
# Whom:				  Narvi <narvi@haldjas.folklore.ee>
#				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

DISTNAME=	socket++-1.10
PKGNAME=	libsocket++-1.10
CATEGORIES=     net
MASTER_SITES=	ftp://ftp.umsicht.fhg.de/pub/unix/language/C++/class-libraries/ \
		ftp://ftp.par.univie.ac.at/pub/unix/c++/  \
		ftp://jungfrau.ptf.hro.nl/pub/socket/

MAINTAINER=	narvi@haldjas.folklore.ee

GNU_CONFIGURE=	yes
#NOPROFILE=	true

post-configure:
	@${CP} ${FILESDIR}/Makefile.lib ${WRKSRC}/Makefile

post-install:
	@${SETENV} OBJFORMAT=${PORTOBJFORMAT} ${LDCONFIG} -m ${PREFIX}/lib
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/socket++.ps ${PREFIX}/share/doc/libsocket++
.endif
	@install-info ${PREFIX}/info/socket++.info ${PREFIX}/info/dir

.include <bsd.port.mk>
