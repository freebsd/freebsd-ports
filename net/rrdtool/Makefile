# New ports collection makefile for:	rrdtool
# Date created:				20 July 1999
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	1.0.40
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	demon@FreeBSD.org

USE_PERL5=	yes
MAKE_ENV+=	PERL=${PERL}

USE_GMAKE=	yes
USE_LIBTOOL=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared=yes
CONFIGURE_ENV=	PERL=${PERL}
CFLAGS:=	${CFLAGS:N-ffast-math}

MAN1=		RRDp.1 RRDs.1 bin_dec_hex.1 rrdcgi.1 rrdcreate.1 rrddump.1 \
		rrdfetch.1 rrdgraph.1 rrdlast.1 rrdresize.1 rrdrestore.1 \
		rrdtool.1 rrdtune.1 rrdtutorial.1 rrdtutorial.es.1 rrdupdate.1 \
		cdeftutorial.1 rpntutorial.1 rrdinfo.1 rrdxport.1
MAN3=		RRDp.3 RRDs.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

post-install:
.if !defined(BATCH)
	@${ECHO} ""
	@${ECHO} "############################################################################"
	@${ECHO} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO} "############################################################################"
.endif

.include <bsd.port.mk>
