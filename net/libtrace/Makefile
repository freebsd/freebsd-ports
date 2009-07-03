# New ports collection makefile for:	libtrace
# Date created:				Mon Oct  8 20:32:57 PDT 2007
# Whom:					Matt Peterson <matt@peterson.org>
#
# $FreeBSD$
#

PORTNAME=	libtrace
PORTVERSION=	3.0.6
CATEGORIES=	net
MASTER_SITES=	http://research.wand.net.nz/software/libtrace/ \
		http://matt.peterson.org/FreeBSD/ports/

MAINTAINER=	matt@peterson.org
COMMENT=	C library for network device, raw & compressed network flows

CONFIGURE_ARGS=	--with-libpcap=${LOCALBASE}

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_GMAKE=	yes

MAN1=		traceanon.1 traceconvert.1 tracefilter.1 tracemerge.1  tracepktdump.1 \
		tracereport.1 tracertstats.1 tracesplit.1 tracesplit_dir.1 tracestats.1 \
		tracesummary.1

CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|g' \
	${WRKSRC}/configure

.include <bsd.port.mk>
