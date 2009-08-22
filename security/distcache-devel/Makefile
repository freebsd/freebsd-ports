# New ports collection makefile for:	distcache
# Date created:				2005-04-13
# Whom:					Marcel Prisi <marcel.prisi@virtua.ch>
#
# $FreeBSD$
#

PORTNAME=	distcache
PORTVERSION=	1.5.1
PORTREVISION=	1
CATEGORIES=	security www
MASTER_SITES=	SF/${PORTNAME}/1.%20${PORTNAME}-devel/${PORTVERSION} \
		http://osdn.dl.sourceforge.net/sourceforge/${PORTNAME}/

PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	marcel.prisi@virtua.ch
COMMENT=	Distributed OpenSSL session caching tools - development version

CONFLICTS=	distcache-1.4*

USE_BZIP2=	yes
USE_RC_SUBR=	dc_server.sh
USE_AUTOTOOLS=	libtool:22
USE_OPENSSL=	yes
LIBTOOLFILES=	configure ssl/configure
USE_LDCONFIG=	yes

SUB_LIST+=	NAME=dc_server

.if !defined(NOPORTDOCS)
PORTDOCS=	ANNOUNCE BUGS CHANGES FAQ INSTALL LICENSE README
.endif

MAN1=	dc_client.1 dc_server.1 dc_snoop.1 dc_test.1 sslswamp.1
MAN2=	DC_CTX_new.2 DC_PLUG_new.2 DC_PLUG_read.2 DC_SERVER_new.2 \
	NAL_ADDRESS_new.2 NAL_BUFFER_new.2 NAL_CONNECTION_new.2 \
	NAL_LISTENER_new.2 NAL_SELECTOR_new.2 NAL_decode_uint32.2
MAN8=	distcache.8

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
