# ex:ts=8
# New ports collection makefile for:	GiNaC
# Date created:			Mar 7, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	GiNaC
PORTVERSION=	1.0.1
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/

MAINTAINER=	ports@FreeBSD.org

USE_BZIP2=	yes
LIB_DEPENDS=	cln:${PORTSDIR}/math/cln

USE_LIBTOOL=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes

INSTALLS_SHLIB=	yes

MAN1=	ginsh.1 viewgar.1 ginac-config.1

post-patch:
	@${PERL} -pi -e "s,sstream,strstream,g" ${WRKSRC}/configure
.for file in numeric.cpp tostring.h
	@${PERL} -pi -e "s,sstream,strstream,g ; \
		s,stringstream,strstream,g" ${WRKSRC}/ginac/${file}
.endfor

pre-build:
	@(cd ${WRKSRC} ; \
	  ${LN} -sf ${PREFIX}/bin/libtool)

.include <bsd.port.mk>
