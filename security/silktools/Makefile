# New ports collection makefile for:	silktools
# Date created:		2006-03-17
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	silktools
PORTVERSION=	1.1.9
CATEGORIES=	security net
MASTER_SITES=	http://tools.netsa.cert.org/releases/ \
		http://redundancy.redundancy.org/mirror/
DISTNAME=	silk-${PORTVERSION}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for large-scale network capture analysis

# Optional PySiLK support awaiting a fix for the USE_PYTHON
# chicken/egg issue
OPTIONS=	IPFIX "Enable IPFIX support" off

LIB_DEPENDS=	lzo:${PORTSDIR}/archivers/lzo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo=${LOCALBASE} --enable-packing-tools
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" GCC_FLAGS="" CFLAGS_RELEASE=""
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

MAN1=	mapsid.1 num2dot.1 rwaddrcount.1 rwappend.1 \
	rwbag.1 rwbagbuild.1 rwbagcat.1 rwbagtool.1 \
	rwcat.1 rwcount.1 rwcut.1 rwdedupe.1 rwfglob.1 \
	rwfileinfo.1 rwfilter.1 rwgeoip2ccmap.1 rwgroup.1 \
	rwidsquery.1 rwip2cc.1 rwmatch.1 \
	rwnetmask.1 rwp2yaf2silk.1 rwpcut.1 rwpdedupe.1 \
	rwpmapbuild.1 rwpmapcat.1 rwpmatch.1 rwptoflow.1 \
	rwrandomizeip.1 rwresolve.1 rwscan.1 rwscanquery.1 \
	rwset.1 rwsetbuild.1 rwsetcat.1 rwsetintersect.1 \
	rwsetmember.1 rwsettool.1 rwsetunion.1 \
	rwsort.1 rwsplit.1 rwstats.1 rwswapbytes.1 \
	rwtotal.1 rwtuc.1 rwuniq.1

MAN3=	addrtype.3 ccfilter.3 flowrate.3 pmapfilter.3

MAN5=	sensor.conf.5 silk.conf.5

MAN7=	silk.7

MAN8=	flowcap.8 rwflowappend.8 rwflowpack.8 rwguess.8 \
		rwpackchecker.8 rwreceiver.8 rwsender.8

.include <bsd.port.pre.mk>

.if defined(WITH_IPFIX)
LIB_DEPENDS+=	fixbuf:${PORTSDIR}/net/libfixbuf
MAN1+=	rwipfix2silk.1 rwsilk2ipfix.1
PLIST_SUB=	IPFIX=""
.else
PLIST_SUB=	IPFIX="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

.include <bsd.port.post.mk>
