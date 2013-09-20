# Created by: David Thiel <lx@redundancy.redundancy.org>
# $FreeBSD$

PORTNAME=	silktools
PORTVERSION=	2.5.0
CATEGORIES=	security net
MASTER_SITES=	http://tools.netsa.cert.org/releases/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	silk-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for large-scale network capture analysis

LIB_DEPENDS=	lzo2:${PORTSDIR}/archivers/lzo2 \
		fixbuf:${PORTSDIR}/net/libfixbuf

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo=${LOCALBASE} --enable-packing-tools --with-python
USE_PYTHON=	yes
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" GCC_FLAGS="" CFLAGS_RELEASE=""
USE_LDCONFIG=	yes
USES=		perl5
USE_PERL5=	build

MAN1=	mapsid.1 num2dot.1 rwaddrcount.1 rwappend.1 \
	rwbag.1 rwbagbuild.1 rwbagcat.1 rwbagtool.1 \
	rwcat.1 rwcount.1 rwcut.1 rwdedupe.1 rwfglob.1 \
	rwfileinfo.1 rwfilter.1 rwgeoip2ccmap.1 rwgroup.1 \
	rwip2cc.1 rwmatch.1 rwnetmask.1 rwpcut.1 rwpdedupe.1 \
	rwpmapbuild.1 rwpmapcat.1 rwpmatch.1 rwptoflow.1 \
	rwrandomizeip.1 rwresolve.1 rwscan.1 rwscanquery.1 \
	rwset.1 rwsetbuild.1 rwsetcat.1 rwsetintersect.1 \
	rwsetmember.1 rwsettool.1 rwsetunion.1 \
	rwsort.1 rwsplit.1 rwstats.1 rwswapbytes.1 \
	rwtotal.1 rwtuc.1 rwuniq.1 rwcompare.1 silk_config.1 \
	rwidsquery.1 rwipfix2silk.1 rwp2yaf2silk.1 rwsilk2ipfix.1

MAN3=	addrtype.3 ccfilter.3 flowrate.3 pmapfilter.3 pysilk.3 \
		silk-plugin.3 silkpython.3

MAN5=	sensor.conf.5 silk.conf.5

MAN7=	silk.7

MAN8=	flowcap.8 rwflowappend.8 rwflowpack.8 rwguess.8 \
		rwpackchecker.8 rwpollexec.8 rwreceiver.8 \
		rwsender.8

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.mk>
