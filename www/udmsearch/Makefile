# New ports collection makefile for:	udmsearch
# Version required:	2.1.5
# Date created:		10/19/1999
# Whom:			Kelly Yancey <kbyanc@posi.net>
#
# $FreeBSD$
#

DISTNAME=	udmsearch-2.1.5
CATEGORIES=	www databases
MASTER_SITES=	http://search.udm.net/about/Download/	\
		http://mysearch.udm.net/Download/	\
		ftp://ftp.izhcom.ru/pub/unix/UdmSearch/	\
		http://mirror.kuenzler.ch/udmsearch/Download/

MAINTAINER=	kbyanc@posi.net

LIB_DEPENDS=	mysqlclient.6:${PORTSDIR}/databases/mysql322-client

MAN1=		indexer.1
MAN5=		indexer.conf.5

USE_GMAKE=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ARGS= --prefix=${PREFIX} \
		--bindir=${PREFIX}/bin/udmsearch \
		--sysconfdir=${PREFIX}/etc/udmsearch \

pre-install:
	${MKDIR} ${PREFIX}/bin/udmsearch
	${MKDIR} ${PREFIX}/etc/udmsearch

post-install:
	@cp -R ${WRKDIR}/${DISTNAME}/create ${PREFIX}/etc/udmsearch
	@strip ${PREFIX}/sbin/indexer
	@strip ${PREFIX}/bin/udmsearch/search.cgi
	@${ECHO}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
