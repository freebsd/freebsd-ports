# New ports collection makefile for:	harvest
# Date created:		Fri Mar  1 19:43:52 MET 1996
# Whom:			Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	harvest
PORTVERSION=	1.5
CATEGORIES=	www
MASTER_SITES=	ftp://ftp.tardis.ed.ac.uk/pub/harvest/ \
		ftp://nic.nasa.gov/software/harvest-dist/ \
		ftp://ftp.sunet.se/pub/nir/harvest-uk/ \
		ftp://gd.tuwien.ac.at/infosys/indexers/uk-harvest/ \
		http://www3.uniovi.es/~mirror/harvest-net/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
USE_PERL5=	yes

pre-patch:
	@${REINPLACE_CMD} -e 's,<malloc.h>,<stdlib.h>,' \
		${WRKSRC}/src/configure ${WRKSRC}/src/broker/broker.h \
		${WRKSRC}/src/gatherer/essence/main.c \
		${WRKSRC}/src/gatherer/include/essence.h \
		${WRKSRC}/components/gatherer/standard/dvi2tty/dvi2tty.h

pre-install:
	${MKDIR} ${PREFIX}/harvest

.include <bsd.port.mk>
