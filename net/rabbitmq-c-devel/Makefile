# Created by: Geoff Garside
# $FreeBSD$

PORTNAME=	rabbitmq-c
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://hg.rabbitmq.com/rabbitmq-c/archive/:c \
		http://hg.rabbitmq.com/rabbitmq-codegen/archive/:codegen
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-cbeb2f3c3e6d
DISTFILES=	cbeb2f3c3e6d.tar.bz2:c \
		df43f2bfcf0e.tar.bz2:codegen
DIST_SUBDIR=	rabbitmq

MAINTAINER=	rabbitmq@geoffgarside.co.uk
COMMENT=	RabbitMQ C AMQP client library

LICENSE=		GPLv2 MPL
LICENSE_COMB=		dual

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson

CONFLICTS=	rabbitmq-c-[0-9]*

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	aclocal autoconf automake autoheader libtool
AUTOMAKE_ARGS=	-i --add-missing
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal

OPTIONS_DEFINE=	64BIT POPT
64BIT_DESC=	Produce 64-bit library
POPT_DESC=	Popt support in tools

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M64BIT}
ONLY_FOR_ARCHS=		amd64 sparc64 powerpc
ONLY_FOR_ARCHS_REASON=	64BIT option is set
CONFIGURE_ARGS+=	--enable-64-bit
.endif

.if ${PORT_OPTIONS:MPOPT}
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB+=		POPT=''
CONFIGURE_ARGS+=	--with-popt
.else
PLIST_SUB+=		POPT='@comment '
CONFIGURE_ARGS+=	--without-popt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|rabbitmq-codegen|rabbitmq-codegen-df43f2bfcf0e|g' ${WRKSRC}/configure.ac

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE})

post-install:
	${STRIP_CMD} ${PREFIX}/lib/librabbitmq.so.0

.include <bsd.port.mk>
