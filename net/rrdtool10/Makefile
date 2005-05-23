# New ports collection makefile for:	rrdtool
# Date created:				20 July 1999
# Whom:					Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	rrdtool
PORTVERSION=	1.0.49
CATEGORIES=	net
MASTER_SITES=	http://people.ee.ethz.ch/~oetiker/webtools/rrdtool/pub/

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Round Robin Database Tools

USE_PERL5=	yes
MAKE_ENV=	PERL=${PERL}

CONFLICTS=	rrdtool-1.2*
LATEST_LINK=	rrdtool10

USE_LIBTOOL_VER=15
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
CONFIGURE_ARGS=	--enable-shared --enable-local-zlib \
		--program-transform-name=''
CONFIGURE_ENV=	PERL=${PERL}
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CFLAGS+=	-I${LOCALBASE}/include -L${LOCALBASE}/lib -fPIC
LDFLAGS+=	-L${LOCALBASE}/lib
CFLAGS:=	${CFLAGS:N-ffast-math}

MAN1=		RRDp.1 RRDs.1 bin_dec_hex.1 rrdcgi.1 rrdcreate.1 rrddump.1 \
		rrdfetch.1 rrdgraph.1 rrdlast.1 rrdresize.1 rrdrestore.1 \
		rrdtool.1 rrdtune.1 rrdtutorial.1 rrdtutorial.es.1 rrdupdate.1 \
		cdeftutorial.1 rpntutorial.1 rrdinfo.1 rrdxport.1 rrd-beginners.1
MAN3=		RRDp.3 RRDs.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

OPTIONS=	"ISO-8859-2 fonts support" off

.include <bsd.port.pre.mk>

.if defined(WITH_LATIN2)
CONFIGURE_ARGS+=--enable-latin2
.endif

.if ${ARCH} == "amd64"
CONFIGURE_ARGS+=--with-pic
.endif

.if ${ARCH} == "ia64"
BROKEN=		"Does not build on ia64"
.endif

post-extract:
.if defined(NOPORTDOCS)
	@${REINPLACE_CMD} -e 's/install-idocDATA install-ihtmlDATA//g' \
		${WRKSRC}/doc/Makefile.in
.endif

post-install:
.if !defined(BATCH)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "############################################################################"
	@${ECHO_MSG} "# See ${PREFIX}/share/examples/rrdtool for some demonstration code        #"
	@${ECHO_MSG} "############################################################################"
.endif

.include <bsd.port.post.mk>
