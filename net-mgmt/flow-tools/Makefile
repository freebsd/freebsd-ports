# New ports collection makefile for:	flow-tools
# Date created:				2000 Jul 25
# Whom:					@BABOLO <.@babolo.ru>
#
# $FreeBSD$
#

PORTNAME=	flow-tools
PORTVERSION=	0.68
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	ftp://ftp.eng.oar.net/pub/flow-tools/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Suite of tools and library to work with netflow data

USE_PYTHON_RUN=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--localstatedir=${PREFIX}

MAN1=	flow-capture.1 flow-cat.1 flow-dscan.1 flow-expire.1	\
	flow-export.1 flow-fanout.1 flow-filter.1 flow-gen.1	\
	flow-header.1 flow-import.1 flow-mask.1 flow-merge.1	\
	flow-nfilter.1 flow-print.1 flow-receive.1		\
	flow-report.1 flow-send.1 flow-split.1 flow-stat.1	\
	flow-tag.1 flow-tools.1	flow-tools-examples.1 		\
	flow-xlate.1 flow-rptfmt.1 flow-log2rrd.1 flow-rpt2rrd.1

.if defined(WITH_PGSQL)
CONFIGURE_ARGS+=--with-pgsql=${PREFIX}
USE_PGSQL=	yes
.endif

.if defined(WITH_MYSQL)
CONFIGURE_ARGS+=--with-mysql=${PREFIX}
USE_MYSQL=	yes
.endif

post-patch:
	${REINPLACE_CMD}\
	 -e 's|@localstatedir@/sym/|${PREFIX}/share/flow-tools/|' \
	 -e 's|@localstatedir@/cfg/|${PREFIX}/etc/flow-tools/|' \
	  ${WRKSRC}/docs/flow-*.1.in ${WRKSRC}/docs/flow-*.html.in

post-install:
.for I in ${MAN1}
	${INSTALL_MAN} ${WRKSRC}/docs/${I} ${PREFIX}/man/man1/
.endfor

.include <bsd.port.mk>
