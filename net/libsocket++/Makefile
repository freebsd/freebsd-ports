# Ports collection makefile for:  libsocket++
# Date created:			  Sun Jan 19, 1997
# Whom:				  Narvi <narvi@haldjas.folklore.ee>
#				  David O'Brien (obrien@FreeBSD.org)
#
# $FreeBSD$
#

PORTNAME=	libsocket++
PORTVERSION=	1.12.7
CATEGORIES=	net
MASTER_SITES=	http://members.aon.at/~hstraub/linux/socket++/ \
		ftp://ftp.umsicht.fhg.de/pub/unix/language/C++/class-libraries/ \
		ftp://ftp.par.univie.ac.at/pub/unix/c++/  \
		ftp://jungfrau.ptf.hro.nl/pub/socket/
DISTNAME=	socket++-${PORTVERSION}

MAINTAINER=	narvi@haldjas.folklore.ee

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf

GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
USE_AUTOMAKE=	yes
USE_AUTOMAKE_VER=	15
USE_LIBTOOL=	yes

post-patch:
	cd ${WRKSRC}; ./autogen

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/libsocket++
	${INSTALL_MAN} ${WRKSRC}/README ${PREFIX}/share/doc/libsocket++
.endif

.include <bsd.port.mk>
