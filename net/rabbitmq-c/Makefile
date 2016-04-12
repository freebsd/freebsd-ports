# Created by: Geoff Garside
# $FreeBSD$

PORTNAME=	rabbitmq-c
PORTVERSION=	0.0.1
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	http://hg.rabbitmq.com/rabbitmq-c/archive/:c \
		http://hg.rabbitmq.com/rabbitmq-codegen/archive/:codegen
DISTNAME=	${PORTNAME}-4e789c776a45
DISTFILES=	4e789c776a45.tar.bz2:c \
		821f5ee7b040.tar.bz2:codegen
DIST_SUBDIR=	rabbitmq

MAINTAINER=	rabbitmq@geoffgarside.co.uk
COMMENT=	RabbitMQ C AMQP client library

LICENSE=	GPLv2 MPL
LICENSE_COMB=	dual

BUILD_DEPENDS=	python:lang/python \
		${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:devel/py-simplejson

CONFLICTS=	rabbitmq-c-devel-[0-9]*

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf gmake libtool python tar:bzip2
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	64BIT POPT
64BIT_DESC=	Produce 64-bit library
POPT_DESC=	Popt support in tools

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:M64BIT}
ONLY_FOR_ARCHS=		amd64 sparc64 powerpc
ONLY_FOR_ARCHS_REASON=	64BIT option is set
CONFIGURE_ARGS+=	--enable-64-bit
.endif

.if ${PORT_OPTIONS:MPOPT}
LIB_DEPENDS+=	libpopt.so:devel/popt
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB+=	POPT=''
CONFIGURE_ARGS+=	--with-popt
.else
PLIST_SUB+=	POPT='@comment '
CONFIGURE_ARGS+=	--without-popt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|rabbitmq-codegen|rabbitmq-codegen-821f5ee7b040|g' ${WRKSRC}/configure.ac

.include <bsd.port.mk>
