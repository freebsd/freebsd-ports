# Ports collection makefile for:  pear-Net_CDDB
# Date created:			  2006/08/14
# Whom:				  chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Net_CDDB
PORTVERSION=	0.2.0
CATEGORIES=	net audio www pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PEAR class that access and query CDDB audio-CD servers

BUILD_DEPENDS=	${PEARDIR}/Net/Socket.php:${PORTSDIR}/net/pear-Net_Socket \
		${PEARDIR}/HTTP/Request.php:${PORTSDIR}/www/pear-HTTP_Request
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_DOS2UNIX=	yes

CATEGORY=	Net
FILES=		CDDB.php CDDB/Disc.php CDDB/Track.php CDDB/Utilities.php \
		CDDB/Protocol.php CDDB/Request.php CDDB/Client.php \
		CDDB/Server.php CDDB/Reader/test.php CDDB/Reader/cddiscid.php \
		CDDB/Reader/cdparanoia.php CDDB/Protocol/Http.php \
		CDDB/Protocol/Cddbp.php CDDB/Protocol/Filesystem.php \
		CDDB/Request/Http.php
DOCS=		CDDB_example_output.txt CDDB_fileformat.txt CDDB_notes.txt \
		CDDB_protocol.txt CDDB_record.txt
TESTS=		CDDBTest.php CDDBTest_HTTP.php CDDBTest_CDDBP.php \
		CDDBTest_Filesystem.php
EXAMPLES=	CDDB_client_example.php CDDB_server_example.php CDDB_misc_example.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
