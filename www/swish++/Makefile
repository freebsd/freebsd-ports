# ex:ts=8
# Ports collection makefile for:	swish++
# Date created:			Jan 13, 2002
# Whom:              		ijliao
#
# $FreeBSD$
#

PORTNAME=	swish++
PORTVERSION=	6.1.5
PORTREVISION=	1
CATEGORIES=	www textproc
MASTER_SITES=	SF/swishplusplus/swishplusplus/${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Web Indexing System for Humans: C++ version

RUN_DEPENDS=	wget:${PORTSDIR}/ftp/wget

USE_PERL5=	yes
USE_GMAKE=	yes
MAKEFILE=	GNUmakefile
MAKE_ENV=	PTHREAD_LIBS=${PTHREAD_LIBS} \
		PERL=${PERL} PERL_VER=${PERL_VERSION}

MAN1=	extract.1 httpindex.1 index.1 search.1 splitmail.1
MAN3=	WWW.3
MAN4=	swish++.conf.4 swish++.index.4
MAN8=	searchd.8 searchmonitor.8

post-patch:
	@${REINPLACE_CMD} -e '/^#error/d' ${WRKSRC}/config.h
.for file in scripts/searchd scripts/searchmonitor
	@${REINPLACE_CMD} -e "s,%%PREFIX%%,${PREFIX},g" ${WRKSRC}/${file}.in
.endfor

pre-install:
	@${MKDIR} ${SITE_PERL}

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/swish++.sh ${PREFIX}/etc/rc.d/swish++.sh.sample

.include <bsd.port.mk>
