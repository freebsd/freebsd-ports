# New ports collection makefile for:	rabbitmq-c-devel
# Date created:				31 March 2010
# Whom:					Geoff Garside
#
# $FreeBSD$
#

PORTNAME=	rabbitmq-c
PORTVERSION=	0.0.1
CATEGORIES=	net
MASTER_SITES=	http://hg.rabbitmq.com/rabbitmq-c/archive/:c \
		http://hg.rabbitmq.com/rabbitmq-codegen/archive/:codegen
PKGNAMESUFFIX=	-devel
DISTNAME=	${PORTNAME}-17b9fb0d63d3
DISTFILES=	17b9fb0d63d3.tar.bz2:c \
		fc46914f99b7.tar.bz2:codegen
DIST_SUBDIR=	rabbitmq

MAINTAINER=	rabbitmq@geoffgarside.co.uk
COMMENT=	RabbitMQ C AMQP client library

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}simplejson>=2.0:${PORTSDIR}/devel/py-simplejson

CONFLICTS=	rabbitmq-c-[0-9]*

USE_BZIP2=	YES
USE_GMAKE=	YES
USE_PYTHON=	YES
USE_LDCONFIG=	YES
GNU_CONFIGURE=	YES
USE_AUTOTOOLS=	aclocal:110 autoconf:262 automake:110 autoheader:262 libtool:22
AUTOMAKE_ARGS=	-i --add-missing
ACLOCAL_ARGS=	-I . -I ${LOCALBASE}/share/aclocal

LICENSE=		GPLv2 MPL
LICENSE_COMB=		dual
LICENSE_FILE_MPL=	${WRKSRC}/LICENSE-GPL-2.0
LICENSE_FILE_GPLv2=	${WRKSRC}/LICENSE-MPL-RabbitMQ

OPTIONS=	64BIT "Produce 64-bit library" Off \
		POPT  "Popt support in tools" Off

.include <bsd.port.options.mk>

.if defined(WITH_64BIT)
ONLY_FOR_ARCHS=		amd64 sparc64 powerpc
ONLY_FOR_ARCHS_REASON=	WITH_64BIT is set
CONFIGURE_ARGS+=	--enable-64-bit
.endif

.if defined(WITH_POPT)
LIB_DEPENDS+=	popt.0:${PORTSDIR}/devel/popt
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	CFLAGS="${CFLAGS}" \
		LDFLAGS="${LDFLAGS}"

PLIST_SUB+=		POPT=''
CONFIGURE_ARGS+=	--with-popt
.else
PLIST_SUB+=		POPT='@comment '
CONFIGURE_ARGS+=	--without-popt
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|rabbitmq-codegen|rabbitmq-codegen-fc46914f99b7|g' ${WRKSRC}/configure.ac

pre-configure:
	@(cd ${CONFIGURE_WRKSRC} && ${SETENV} ${AUTOTOOLS_ENV} ${LIBTOOLIZE})

post-install:
	${STRIP_CMD} ${PREFIX}/lib/librabbitmq.so.0

.include <bsd.port.mk>
