# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mongrel2
PORTVERSION=	1.7.5
PORTREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://mongrel2.org/static/downloads/

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Is an application, language, and network arch

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libzmq.so:${PORTSDIR}/net/libzmq2 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3

USES=	gmake
USE_BZIP2=	yes
MAKE_FLAGS=	freebsd
EXAMPLES_LIST=	bbs \
		chat \
		configs \
		http_0mq \
		kegogi \
		mp3stream \
		procer \
		python \
		tornado \
		zcov

OPTIONS_DEFINE=		EXAMPLES

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MEXAMPLES}
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/Makefile

post-install:
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${STAGEDIR}/${EXAMPLESDIR}
.for examples in ${EXAMPLES_LIST}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${examples} ${STAGEDIR}/${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.mk>
