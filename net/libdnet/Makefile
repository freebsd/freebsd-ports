# New ports collection makefile for:	libdnet
# Date created:				15 April 2002
# Whom:			Dominic Marks <dominic.marks@btinternet.com>
#
# $FreeBSD$
#

PORTNAME=	libdnet
PORTVERSION=	1.11
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
.if defined(BUILD_PYTHON_MODULE)
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
.endif

MAINTAINER=	onatan@gmail.com
COMMENT?=	A simple interface to low level networking routines

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_GMAKE=	yes

SLAVE_DIRS=	net/py-libdnet

.if defined(BUILD_PYTHON_MODULE)
USE_PYTHON=	yes
CONFIGURE_ARGS+=	--with-python
INSTALL_WRKSRC=	${BUILD_WRKSRC}/python
PLIST_FILES=	%%PYTHON_SITELIBDIR%%/dnet.so
PLIST_SUB+=	MASTER="@comment "
.else
CONFIGURE_ARGS+=	--without-python
USE_LDCONFIG=	yes
PLIST_SUB+=	MASTER=""

MAN3=	dnet.3
MAN8=	dnet.8
.endif

.include <bsd.port.pre.mk>
.if ${OSVERSION} < 500000
IGNORE=		doesn't build on FreeBSD 4.x
.endif


pre-everything::
.if !defined(BUILD_PYTHON_MODULE)
	@${ECHO_MSG} "===>"
	@${ECHO_MSG} "===> You can add python support with the port ${SLAVE_DIRS}."
	@${ECHO_MSG} "===>"
	@sleep 2
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|echo aout|echo elf|' ${WRKSRC}/configure

post-build:
	@cd ${WRKSRC}/src ; ${CC} ${CFLAGS} -shared -o libdnet.so .libs/addr-util.o .libs/addr.o .libs/blob.o .libs/ip-util.o .libs/ip6.o .libs/rand.o .libs/arp-bsd.o .libs/eth-bsd.o .libs/fw-pf.o .libs/intf.o .libs/ip.o .libs/route-bsd.o .libs/tun-bsd.o

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME}.so ${PREFIX}/lib/
	@${LN} ${PREFIX}/lib/${PORTNAME}.so ${PREFIX}/lib/${PORTNAME}.so.1

.if defined(BUILD_PYTHON_MODULE) && defined(MAINTAINER_MODE)
test:	install
	${PYTHON_CMD} ${INSTALL_WRKSRC}/test.py
.endif

.include <bsd.port.post.mk>
