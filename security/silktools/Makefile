# New ports collection makefile for:	silktools
# Date created:		2006-03-17
# Whom:			David Thiel <lx@redundancy.redundancy.org>
#
# $FreeBSD$
#

PORTNAME=	silktools
PORTVERSION=	0.10.5
CATEGORIES=	security net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lx@FreeBSD.org
COMMENT=	Tools for large-scale network capture analysis

LIB_DEPENDS=	lzo:${PORTSDIR}/archivers/lzo

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-lzo=${LOCALBASE}
USE_GMAKE=	yes
MAKE_ARGS=	CC="${CC}" GCC_FLAGS="" CFLAGS_RELEASE=""
USE_LDCONFIG=	yes
USE_PERL5_BUILD=	yes

MAN1=	rwip2cc.1 rwpmapbuild.1 mapsid.1 num2dot.1 rwaddrcount.1 rwappend.1 \
	rwbag.1 rwbagbuild.1 rwbagcat.1 rwbagtool.1 rwcat.1 rwcount.1 \
	rwcut.1 rwfileinfo.1 rwfilter.1 rwfglob.1 rwgroup.1 rwmatch.1 \
	rwnetmask.1 rwrandomizeip.1 rwset.1 rwsetbuild.1 rwsetcat.1 rwsort.1 \
	rwsetintersect.1 rwsetunion.1 rwstats.1 rwswapbytes.1 rwtotal.1 \
	rwtuc.1 rwuniq.1 rwptoflow.1 rwpmatch.1 rwpdedupe.1 rwpcut.1 \
	rwp2yaf2silk.1

MAN3=	libaddrtype.3 libccfilter.3 libpmapfilter.3

MAN5=	sensor.conf.5

MAN8=	rwflowpack.8 flowcap.8

post-install:
	@${MV} ${PREFIX}/share/silk/rwfpd.conf ${PREFIX}/share/silk/rwfpd.conf.sample
	@${MV} ${PREFIX}/share/silk/flowcap.conf ${PREFIX}/share/silk/flowcap.conf.sample

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=	Does not build on 4.x
.endif

.include <bsd.port.post.mk>
