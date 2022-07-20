PORTNAME=	scws
PORTVERSION=	1.2.3
CATEGORIES=	textproc
MASTER_SITES=	http://www.xunsearch.com/scws/down/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Chinese word segmentation program and lib

LICENSE=	BSD2CLAUSE

GNU_CONFIGURE=	yes
USES=		gmake libtool:keepla tar:bzip2
USE_LDCONFIG=	yes

CONFIGURE_ARGS=	--sysconfdir=${PREFIX}/etc/scws \
		--with-pic

INSTALL_TARGET=install-strip

.include <bsd.port.mk>
