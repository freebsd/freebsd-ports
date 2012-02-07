# New ports collection makefile for:	mongrel2
# Date created:		2011-09-28
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	mongrel2
PORTVERSION=	1.7.5
CATEGORIES=	www
MASTER_SITES=	http://mongrel2.org/static/downloads/

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Is an application, language, and network arch

LIB_DEPENDS=	zmq.1:${PORTSDIR}/devel/zmq \
		sqlite3.8:${PORTSDIR}/databases/sqlite3

USE_GMAKE=	yes
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

OPTIONS=	EXAMPLES "Install examplse" on

.include <bsd.port.pre.mk>

.if defined(WITH_EXAMPLES)
PLIST_SUB+=	EXAMPLES=""
.else
PLIST_SUB+=	EXAMPLES="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's#/usr/local#${LOCALBASE}#g' ${WRKSRC}/Makefile

post-install:
.if defined(WITH_EXAMPLES)
	@${MKDIR} ${EXAMPLESDIR}
.for examples in ${EXAMPLES_LIST}
	@cd ${WRKSRC}/examples && ${COPYTREE_SHARE} ${examples} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
