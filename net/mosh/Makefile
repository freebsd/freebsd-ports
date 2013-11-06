# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mosh
PORTVERSION=	1.2.4
CATEGORIES=	net
MASTER_SITES=	http://mosh.mit.edu/ \
		http://mirrors.rit.edu/zi/

MAINTAINER=	zi@FreeBSD.org
COMMENT=	Mobile terminal that supports intermittent connectivity

LICENSE=	GPLv3

LIB_DEPENDS=	libprotobuf.so:${PORTSDIR}/devel/protobuf

USE_PERL5=	run
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-utempter
CONFIGURE_ENV+=	OPENSSL_CFLAGS="-I${OPENSSLINC}" OPENSSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
INSTALL_TARGET=	install-strip
USE_OPENSSL=	yes
USES=		pkgconfig perl5

LATEST_LINK=	mosh-term

CONFLICTS_INSTALL=	mosh-0.[2-9].*

PLIST_FILES=	bin/mosh bin/mosh-server bin/mosh-client \
		man/man1/mosh-client.1.gz man/man1/mosh-server.1.gz man/man1/mosh.1.gz

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 900004
LIB_DEPENDS+=	libutempter.so:${PORTSDIR}/sysutils/libutempter
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
