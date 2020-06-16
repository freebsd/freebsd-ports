# Created by Radim Kolar <hsn@sendmail.cz>
# $FreeBSD$

PORTNAME=	courier-sox
DISTVERSION=	0.12.20180428
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF/courier/sox-devel/${DISTVERSION:E}

MAINTAINER=	hsn@sendmail.cz
COMMENT=	Courier Socks 5 Proxy client library and wrapper

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	courier-authlib-base>0.56:security/courier-authlib-base \
		gdbm>0:databases/gdbm \
		libltdl>0:devel/libltdl
RUN_DEPENDS=	courier-authlib-base>0.56:security/courier-authlib-base \
		gdbm>0:databases/gdbm \
		libltdl>0:devel/libltdl \
		p5-GDBM>0:databases/p5-GDBM \
		p5-Net-CIDR>0:net-mgmt/p5-Net-CIDR

USES=		autoreconf libtool localbase perl5 tar:bz2
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USE_RC_SUBR=	sockd
TEST_TARGET=	check

post-stage:
		@(cd ${STAGEDIR}/${PREFIX}/etc/socksrc/ && \
			${MV} system system.sample)

.include <bsd.port.mk>
